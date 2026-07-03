#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Ricostruisce i percorsi di attacco dai trace XML di Moebius/ADVISE.

Versione compatibile con Python 3.5 (niente f-string, dataclass,
annotazioni di variabile o sintassi "X | None").

Uso:
    python3 advise_paths_py35.py /percorso/cartella
    python3 advise_paths_py35.py /percorso/cartella --csv percorsi.csv
    python3 advise_paths_py35.py /percorso/cartella --goal StealPrivateData
    python3 advise_paths_py35.py /percorso/cartella --tutti-gli-step
"""

import argparse
import csv
import re
import sys
import xml.etree.ElementTree as ET
from collections import Counter, defaultdict
from pathlib import Path

# Suffissi con cui ADVISE nomina le azioni generate dagli attack step.
SUFFISSO_SUCCESSO = "SuccessStep"
SUFFISSO_FALLIMENTO = "FailureStep"
SUFFISSO_DECISIONE = "AdversaryDecision"
# Step "vuoto": l'avversario sceglie di non fare nulla, non fa parte del percorso.
STEP_INERTI = set(["DoNothingNothingStep", "DoNothing"])

# Suffissi/nomi delle variabili che sono meccanica interna del decision
# process di ADVISE (non sono "metadati" della run, sono l'ingranaggio
# con cui l'avversario sceglie il prossimo step). Vanno esclusi quando
# si cerca automaticamente qualche variabile interessante non prevista
# (es. Detectability, Cost, Risk, se il modello le definisce).
SUFFISSI_MECCANICA = ("Weight", "Chosen")
NOMI_MECCANICA = set(["MakeDecision"])
# Suffissi che identificano il "profilo" statico dell'attaccante
# (capacita' assegnate a inizio run): non sono metadati della run,
# sono il parametro sperimentale che gia' mostriamo a parte.
SUFFISSI_PROFILO = ("Access", "Knowledge", "Skill")


def e_meccanica_interna(nome_var):
    return nome_var in NOMI_MECCANICA or nome_var.endswith(SUFFISSI_MECCANICA)


def e_profilo_attaccante(nome_var):
    return nome_var.endswith(SUFFISSI_PROFILO)


def id_esperimento(nomefile):
    """Prova a estrarre un identificativo breve tipo 'Exp2302' dal nome
    file; se non lo trova usa il nome file senza estensione."""
    m = re.search(r"Exp\d+", nomefile, re.IGNORECASE)
    if m:
        return m.group(0)
    return Path(nomefile).stem


def nome_base(nome_azione):
    """ExtractDataRemotelySuccessStep -> ExtractDataRemotely"""
    for suffisso in (SUFFISSO_SUCCESSO, SUFFISSO_FALLIMENTO, SUFFISSO_DECISIONE):
        if nome_azione.endswith(suffisso):
            return nome_azione[: -len(suffisso)]
    return nome_azione


class Trace(object):
    """Una singola run estratta da un file XML."""

    def __init__(self, file):
        self.file = file
        self.percorso = ()            # step riusciti, in ordine, fino all'obiettivo
        self.percorso_completo = ()   # tutti gli step riusciti, anche dopo l'obiettivo
        self.falliti = []             # coppie (step, t) dei tentativi falliti
        self.obiettivo_raggiunto = False
        self.t_obiettivo = None
        self.t_finale = None
        self.profilo = {}             # stato iniziale (capacita' dell'avversario)
        self.stato_finale = {}        # ultimo valore noto di ogni variabile
        self.n_decisioni = 0          # quante volte l'avversario ha scelto un ramo
        self.errore = None

    @property
    def n_tentativi(self):
        return len(self.percorso_completo) + len(self.falliti)

    @property
    def step_ripetuti(self):
        """Step tentati piu' di una volta (successo o fallimento), utile
        per capire se l'avversario ha dovuto insistere su un certo ramo."""
        conteggio = Counter(list(self.percorso_completo) + [s for s, _ in self.falliti])
        return sorted(s for s, n in conteggio.items() if n > 1)

    @property
    def efficienza(self):
        """Tempo impiegato per step riuscito sul percorso verso l'obiettivo.
        Piu' basso = percorso piu' diretto."""
        if self.t_obiettivo is None or not self.percorso:
            return None
        return self.t_obiettivo / len(self.percorso)


def leggi_trace(path, var_obiettivo):
    """Estrae il percorso da un singolo file di trace."""
    tr = Trace(path)
    try:
        root = ET.parse(str(path)).getroot()
    except ET.ParseError as e:
        tr.errore = "XML non valido: {0}".format(e)
        return tr

    # Mappa id -> nome, sia per le azioni che per le variabili.
    azioni = {}
    variabili = {}
    for processo in root.iter("Process"):
        for a in processo.iter("Action"):
            azioni[a.get("id")] = a.get("name", "")
        for v in processo.iter("Var"):
            variabili[v.get("id")] = v.get("name", "")

    if not azioni:
        tr.errore = "nessuna <Action> dichiarata nel <Process>"
        return tr

    # Gli id delle variabili sono prefissati col processo (p2StealPrivateData),
    # quindi si risale al nome logico tramite la mappa <Var>.
    def nome_var(vid):
        return variabili.get(vid, vid)

    id_obiettivo = set(vid for vid, n in variabili.items() if n == var_obiettivo)

    for sequenza in root.iter("Sequence"):
        # Stato iniziale: e' il profilo dell'avversario (access, knowledge, skill).
        stato_iniziale = sequenza.find("S")
        if stato_iniziale is not None:
            for v in stato_iniziale.iter("V"):
                tr.profilo[nome_var(v.get("id"))] = v.get("val")
            # L'obiettivo potrebbe gia' essere vero a t=0 (raro, ma va gestito).
            if tr.profilo.get(var_obiettivo) == "1":
                tr.obiettivo_raggiunto = True
                tr.t_obiettivo = 0.0

        successi_prima = []
        successi_tutti = []

        for a in sequenza.iter("A"):
            nome = azioni.get(a.get("id"), a.get("id"))
            try:
                t = float(a.get("t", "nan"))
            except ValueError:
                t = float("nan")
            tr.t_finale = t

            if nome not in STEP_INERTI:
                if nome.endswith(SUFFISSO_SUCCESSO):
                    base = nome_base(nome)
                    successi_tutti.append(base)
                    if not tr.obiettivo_raggiunto:
                        successi_prima.append(base)
                elif nome.endswith(SUFFISSO_FALLIMENTO):
                    tr.falliti.append((nome_base(nome), t))
                elif nome.endswith(SUFFISSO_DECISIONE):
                    tr.n_decisioni += 1

            # Gli aggiornamenti di stato sono figli dell'azione: si tiene
            # traccia dell'ultimo valore noto di ogni variabile (serve sia
            # per il goal sia per scoprire metadati extra non previsti,
            # tipo un'eventuale Detectability/Cost/Risk del modello) e si
            # controlla se questo step ha portato l'obiettivo a vero.
            for v in a.iter("V"):
                vid = v.get("id")
                tr.stato_finale[nome_var(vid)] = v.get("val")
                if not tr.obiettivo_raggiunto and vid in id_obiettivo \
                        and v.get("val") not in ("0", None):
                    tr.obiettivo_raggiunto = True
                    tr.t_obiettivo = t

        tr.percorso = tuple(successi_prima)
        tr.percorso_completo = tuple(successi_tutti)

    return tr


def raccogli(cartella, prefisso, var_obiettivo):
    file_trovati = sorted(cartella.rglob(prefisso + "*.xml"))
    if not file_trovati:
        sys.stderr.write("Nessun file {0}*.xml trovato in {1}\n".format(prefisso, cartella))
    return [leggi_trace(f, var_obiettivo) for f in file_trovati]


def trova_metadati_extra(validi, var_obiettivo):
    """Cerca variabili che non sono ne' profilo dell'attaccante ne'
    meccanica interna del decision process ne' l'obiettivo stesso, e il
    cui valore finale cambia tra le run: e' li' che finirebbe una
    eventuale Detectability/Cost/Risk se il modello la definisce."""
    per_nome = defaultdict(set)
    for t in validi:
        for nome, val in t.stato_finale.items():
            if nome == var_obiettivo:
                continue
            if e_meccanica_interna(nome) or e_profilo_attaccante(nome):
                continue
            per_nome[nome].add(val)
    return sorted(nome for nome, valori in per_nome.items() if len(valori) > 1)


def stampa_dettaglio_per_esperimento(validi, mostra_tutti, extra):
    campo = "percorso_completo" if mostra_tutti else "percorso"
    righe = []
    for t in validi:
        righe.append((id_esperimento(t.file.name), t))
    righe.sort(key=lambda r: r[0])

    larghezza_percorso = max([len(" -> ".join(getattr(t, campo)) or "-")
                               for _, t in righe] + [8])

    print("\n=== DETTAGLIO PER ESPERIMENTO ===")
    print("{0:14s} {1:{lp}s} {2:>11s} {3:>9s} {4:>12s} {5:>7s} {6:>9s}  {7}".format(
        "Esperimento", "Percorso", "t_obiettivo", "t_finale",
        "eff.(t/step)", "falliti", "decisioni", "ripetuti", lp=larghezza_percorso))

    for nome_exp, t in righe:
        percorso = getattr(t, campo)
        etichetta = " -> ".join(percorso) if percorso else "-"
        t_ob = "{0:g}".format(t.t_obiettivo) if t.t_obiettivo is not None else "n/a"
        t_fin = "{0:g}".format(t.t_finale) if t.t_finale is not None else "n/a"
        eff = "{0:.2f}".format(t.efficienza) if t.efficienza is not None else "n/a"
        ripetuti = ", ".join(t.step_ripetuti) if t.step_ripetuti else "-"
        valori_extra = " ".join(
            "{0}={1}".format(e, t.stato_finale.get(e, "?")) for e in extra)
        print("{0:14s} {1:{lp}s} {2:>11s} {3:>9s} {4:>12s} {5:>7d} {6:>9d}  {7}  {8}".format(
            nome_exp, etichetta, t_ob, t_fin, eff, len(t.falliti), t.n_decisioni,
            ripetuti, valori_extra, lp=larghezza_percorso))


def stampa_report(traces, var_obiettivo, mostra_tutti):
    validi = [t for t in traces if t.errore is None]
    rotti = [t for t in traces if t.errore is not None]

    print("File letti: {0}   validi: {1}   illeggibili: {2}".format(
        len(traces), len(validi), len(rotti)))
    for t in rotti:
        print("  ! {0}: {1}".format(t.file.name, t.errore))
    if not validi:
        return

    riusciti = [t for t in validi if t.obiettivo_raggiunto]
    print("Run che raggiungono {0}: {1}/{2} ({3:.1%})".format(
        var_obiettivo, len(riusciti), len(validi), len(riusciti) / len(validi)))

    if riusciti:
        tempi = sorted(t.t_obiettivo for t in riusciti if t.t_obiettivo is not None)
        if tempi:
            mediana = tempi[len(tempi) // 2]
            print("Tempo al successo: min {0:g}  mediana {1:g}  max {2:g}".format(
                tempi[0], mediana, tempi[-1]))

    extra = trova_metadati_extra(validi, var_obiettivo)
    if extra:
        print("\nMetadati extra rilevati (variabili non di profilo/meccanica "
              "il cui valore finale cambia tra le run): " + ", ".join(extra))
    else:
        print("\nNessun metadato extra (tipo Detectability/Cost/Risk) trovato: "
              "il modello non ne dichiara, o e' costante in tutte le run.")

    stampa_dettaglio_per_esperimento(validi, mostra_tutti, extra)

    print("\n=== PERCORSI DISTINTI ===")
    campo = "percorso_completo" if mostra_tutti else "percorso"
    conteggio = Counter(getattr(t, campo) for t in validi)
    for percorso, n in conteggio.most_common():
        etichetta = " -> ".join(percorso) if percorso else "(nessuno step riuscito)"
        print("{0:5d}  {1:6.1%}  {2}".format(n, n / len(validi), etichetta))

    print("\n=== FREQUENZA DEI SINGOLI STEP ===")
    usi = Counter()
    fallimenti = Counter()
    for t in validi:
        for s in set(getattr(t, campo)):
            usi[s] += 1
        for s, _ in t.falliti:
            fallimenti[s] += 1
    for step in sorted(set(usi) | set(fallimenti)):
        print("  {0:35s} riuscito in {1:4d} run   tentativi falliti: {2:4d}".format(
            step, usi[step], fallimenti[step]))

    # Le capacita' dell'avversario che cambiano tra i file spiegano
    # perche' vengono scelti percorsi diversi.
    varianti = defaultdict(set)
    for t in validi:
        for k, v in t.profilo.items():
            varianti[k].add(v)
    discriminanti = set(k for k, vals in varianti.items() if len(vals) > 1)
    if discriminanti:
        print("\n=== PROFILO x PERCORSO (solo variabili che cambiano tra i file) ===")
        for k in sorted(discriminanti):
            per_valore = defaultdict(Counter)
            for t in validi:
                per_valore[t.profilo.get(k)][getattr(t, campo)] += 1
            print("\n  {0}:".format(k))
            for val, c in sorted(per_valore.items(), key=lambda x: str(x[0])):
                principale, n = c.most_common(1)[0]
                etichetta = " -> ".join(principale) if principale else "(nessuno)"
                print("    = {0:6s}  {1:4d} run, percorso dominante: {2} ({3})".format(
                    str(val), sum(c.values()), etichetta, n))


def esporta_csv(traces, destinazione, mostra_tutti, var_obiettivo):
    campo = "percorso_completo" if mostra_tutti else "percorso"
    validi = [t for t in traces if t.errore is None]
    chiavi_profilo = sorted(set(k for t in validi for k in t.profilo))
    extra = trova_metadati_extra(validi, var_obiettivo)

    with open(str(destinazione), "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["esperimento", "file", "percorso", "n_step", "obiettivo_raggiunto",
                    "t_obiettivo", "t_finale", "efficienza", "n_falliti",
                    "n_decisioni", "step_ripetuti"] + chiavi_profilo + extra)
        for t in sorted(validi, key=lambda t: id_esperimento(t.file.name)):
            percorso = getattr(t, campo)
            riga = [
                id_esperimento(t.file.name),
                t.file.name,
                " -> ".join(percorso),
                len(percorso),
                int(t.obiettivo_raggiunto),
                t.t_obiettivo if t.t_obiettivo is not None else "",
                t.t_finale if t.t_finale is not None else "",
                "{0:.3f}".format(t.efficienza) if t.efficienza is not None else "",
                len(t.falliti),
                t.n_decisioni,
                ", ".join(t.step_ripetuti),
            ]
            riga.extend(t.profilo.get(k, "") for k in chiavi_profilo)
            riga.extend(t.stato_finale.get(k, "") for k in extra)
            w.writerow(riga)
    print("\nCSV scritto: {0}".format(destinazione))


def main():
    p = argparse.ArgumentParser(
        description="Ricostruisce i percorsi di attacco dai trace XML di ADVISE.")
    p.add_argument("cartella", type=Path, help="cartella da cui partire (ricorsiva)")
    p.add_argument("--prefisso", default="Results_",
                   help="prefisso dei file (default: Results_)")
    p.add_argument("--goal", default="StealPrivateData",
                   help="variabile che segna l'obiettivo (default: StealPrivateData)")
    p.add_argument("--csv", type=Path, help="esporta il dettaglio per run in CSV")
    p.add_argument("--tutti-gli-step", action="store_true",
                   help="includi anche gli step riusciti dopo il raggiungimento dell'obiettivo")
    args = p.parse_args()

    if not args.cartella.is_dir():
        sys.exit("Non e' una cartella: {0}".format(args.cartella))

    traces = raccogli(args.cartella, args.prefisso, args.goal)
    if not traces:
        sys.exit(1)

    stampa_report(traces, args.goal, args.tutti_gli_step)
    if args.csv:
        esporta_csv(traces, args.csv, args.tutti_gli_step, args.goal)


if __name__ == "__main__":
    main()
