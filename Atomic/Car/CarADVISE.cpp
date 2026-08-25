
#include "Atomic/Car/CarADVISE.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


CarADVISE::CarADVISE() {
  SendMaliciousPacketAD.setParent(this);
  DoNothingAD.setParent(this);
  ImpersonateOEMAD.setParent(this);
  SendMaliciousPacketOutcome1.setParent(this);
  DoNothingOutcome1.setParent(this);
  ImpersonateOEMOutcome1.setParent(this);
  AdversaryDecisionGroup.initialize(3, "AdversaryDecisionGroup");
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &SendMaliciousPacketAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DoNothingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ImpersonateOEMAD);

  BaseADVISEAction* InitialActions[6] = {
    &SendMaliciousPacketAD, // 0
    &DoNothingAD, // 1
    &ImpersonateOEMAD, // 2
    &SendMaliciousPacketOutcome1, // 3
    &DoNothingOutcome1, // 4
    &ImpersonateOEMOutcome1 // 5
  };

  Step* InitialSteps[3] = {
      &SendMaliciousPacketOutcome1,
      &DoNothingOutcome1,
      &ImpersonateOEMOutcome1
  };

  BaseGroupClass* InitialGroups[4] = {
    (BaseGroupClass*) &SendMaliciousPacketOutcome1, // 0
    (BaseGroupClass*) &DoNothingOutcome1, // 1
    (BaseGroupClass*) &ImpersonateOEMOutcome1, // 2
    (BaseGroupClass*) &AdversaryDecisionGroup
  };

  CarWirelessNetworkAccess = new Access("CarWirelessNetworkAccess", 0);
  MessageFormatKnowledge = new Knowledge("MessageFormatKnowledge", 0);
  CarModelKnowledge = new Knowledge("CarModelKnowledge", 0);
  InjectionSkill = new Skill("InjectionSkill", 0);
  SpoofingSkill = new Skill("SpoofingSkill", 0);
  StealPrivateData = new Goal("StealPrivateData", 0);
  StealPrivateData->setPayoff(0);
  MakeDecision = new BeginAdversaryDecision("MakeDecision", 0);
  SendMaliciousPacketWeight = new StepWeight("SendMaliciousPacketWeight", 0);
  SendMaliciousPacketChosen = new StepChosen("SendMaliciousPacketChosen", 0);
  DoNothingWeight = new StepWeight("DoNothingWeight", 0);
  DoNothingChosen = new StepChosen("DoNothingChosen", 0);
  ImpersonateOEMWeight = new StepWeight("ImpersonateOEMWeight", 0);
  ImpersonateOEMChosen = new StepChosen("ImpersonateOEMChosen", 0);

  Goal* InitialGoals[1] = {
      StealPrivateData
  };

  ADVISEStateVariable* InitialSVs[13] = {
    CarWirelessNetworkAccess, // 0
    MessageFormatKnowledge, // 1
    CarModelKnowledge, // 2
    InjectionSkill, // 3
    SpoofingSkill, // 4
    StealPrivateData, // 5
    SendMaliciousPacketChosen, // 6
    DoNothingChosen, // 7
    ImpersonateOEMChosen, // 8
    SendMaliciousPacketWeight, // 9
    DoNothingWeight, // 10
    ImpersonateOEMWeight, // 11
    MakeDecision // 12
};

  int outCounts[3] = { 1, 1, 1 };

  commonInit("Car", 13, InitialSVs, 6, InitialActions, 4, InitialGroups, 3, outCounts, InitialSteps, 1, InitialGoals);

  advCostPref = 0.1;
  advDetectPref = 0.1;
  advPayPref = 0.8;

  planningHorizon = 1;
  costDiscount = 1.0;
  detectionDiscount = 1.0;
  payoffDiscount = 1.0;

  assignSVsToAttackSteps();

  int AffectArcs[29][2] = {
    {12,0}, {6,0}, {9,0}, {12,1}, {7,1}, {10,1}, {12,2}, {8,2}, 
    {11,2}, {12,3}, {6,3}, {9,3}, {10,3}, {11,3}, {0,3}, {1,3}, 
    {12,4}, {7,4}, {9,4}, {10,4}, {11,4}, {12,5}, {8,5}, {9,5}, 
    {10,5}, {11,5}, {5,5}, {2,5}, {0,5}
};
  for(int n = 0; n < 29;n++)
    AddAffectArc(InitialSVs[AffectArcs[n][0]], InitialActions[AffectArcs[n][1]]);
  int EnableArcs[7][2] = {
    {12,0}, {12,1}, {12,2}, {6,3}, {7,4}, {8,5}, {5,5}
};
  for(int n = 0; n < 7;n++)
    AddEnableArc(InitialSVs[EnableArcs[n][0]], InitialActions[EnableArcs[n][1]]);
  for(int x = 0; x < 6; x++) {
    InitialActions[x]->LinkVariables();
  }

  customInitialization();

  recalculateAdversaryDecisionWeights();

}

CarADVISE::~CarADVISE() {
}

void CarADVISE::assignSVsToAttackSteps() {
  SendMaliciousPacketOutcome1.CarWirelessNetworkAccess = CarWirelessNetworkAccess;
  SendMaliciousPacketOutcome1.MessageFormatKnowledge = MessageFormatKnowledge;
  SendMaliciousPacketOutcome1.SendMaliciousPacketChosen = SendMaliciousPacketChosen;
  SendMaliciousPacketOutcome1.SendMaliciousPacketWeight = SendMaliciousPacketWeight;
  SendMaliciousPacketOutcome1.DoNothingWeight = DoNothingWeight;
  SendMaliciousPacketOutcome1.ImpersonateOEMWeight = ImpersonateOEMWeight;
  SendMaliciousPacketOutcome1.MakeDecision = MakeDecision;
  SendMaliciousPacketOutcome1.setSVs(SendMaliciousPacketChosen, SendMaliciousPacketWeight);
  DoNothingOutcome1.DoNothingChosen = DoNothingChosen;
  DoNothingOutcome1.SendMaliciousPacketWeight = SendMaliciousPacketWeight;
  DoNothingOutcome1.DoNothingWeight = DoNothingWeight;
  DoNothingOutcome1.ImpersonateOEMWeight = ImpersonateOEMWeight;
  DoNothingOutcome1.MakeDecision = MakeDecision;
  DoNothingOutcome1.setSVs(DoNothingChosen, DoNothingWeight);
  ImpersonateOEMOutcome1.StealPrivateData = StealPrivateData;
  ImpersonateOEMOutcome1.CarModelKnowledge = CarModelKnowledge;
  ImpersonateOEMOutcome1.CarWirelessNetworkAccess = CarWirelessNetworkAccess;
  ImpersonateOEMOutcome1.SpoofingSkill = SpoofingSkill;
  ImpersonateOEMOutcome1.ImpersonateOEMChosen = ImpersonateOEMChosen;
  ImpersonateOEMOutcome1.SendMaliciousPacketWeight = SendMaliciousPacketWeight;
  ImpersonateOEMOutcome1.DoNothingWeight = DoNothingWeight;
  ImpersonateOEMOutcome1.ImpersonateOEMWeight = ImpersonateOEMWeight;
  ImpersonateOEMOutcome1.MakeDecision = MakeDecision;
  ImpersonateOEMOutcome1.setSVs(ImpersonateOEMChosen, ImpersonateOEMWeight);

  SendMaliciousPacketAD.MakeDecision = MakeDecision;
  SendMaliciousPacketAD.SendMaliciousPacketChosen = SendMaliciousPacketChosen;
  SendMaliciousPacketAD.SendMaliciousPacketWeight = SendMaliciousPacketWeight;
  DoNothingAD.MakeDecision = MakeDecision;
  DoNothingAD.DoNothingChosen = DoNothingChosen;
  DoNothingAD.DoNothingWeight = DoNothingWeight;
  ImpersonateOEMAD.MakeDecision = MakeDecision;
  ImpersonateOEMAD.ImpersonateOEMChosen = ImpersonateOEMChosen;
  ImpersonateOEMAD.ImpersonateOEMWeight = ImpersonateOEMWeight;
}

double CarADVISE::convertCostToUtility(double cost) {
  const double esquared = 7.389056099; // e^(2)
  if(cost < 0)
    return 1.0;
  else if(cost > 100)
    return 0.0;
  else {
    return (esquared - exp(cost/50))/(-1 + esquared);
  }
}

double CarADVISE::convertPayoffToUtility(double payoff) {
  const double etoten = 28.031624895; // e^(10/3)
  if(payoff < 0)
    return 0;
  else if(payoff > 1000)
    return 1;
  else {
    return (etoten - (etoten/exp(payoff/300)))/(-1 + etoten);
  }
}

double CarADVISE::convertDetectionToUtility(double detection) {
  const double esquared = 7.389056099; // e^(2)
  if(detection < 0)
    return 1;
  else if(detection > 1)
    return 0;
  else {
    return (1-(esquared/exp(2*detection)))/(1-esquared);
  }
}

void CarADVISE::customInitialization() {

}

/*****************************************************************/
/*                   Attack Step Definitions                     */
/*****************************************************************/

/*====================== SendMaliciousPacketOutcome1Step ========================*/

CarADVISE::SendMaliciousPacketOutcome1Step::SendMaliciousPacketOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("SendMaliciousPacketOutcome1Step", 0, Exponential, RaceEnabled, 7, 0, false);}

CarADVISE::SendMaliciousPacketOutcome1Step::~SendMaliciousPacketOutcome1Step() {
  delete[] TheDistributionParameters;
}

void CarADVISE::SendMaliciousPacketOutcome1Step::LinkVariables() {
  CarWirelessNetworkAccess->Register(&CarWirelessNetworkAccess_Mobius_Mark);
  MessageFormatKnowledge->Register(&MessageFormatKnowledge_Mobius_Mark);
  SendMaliciousPacketChosen->Register(&SendMaliciousPacketChosen_Mobius_Mark);
  SendMaliciousPacketWeight->Register(&SendMaliciousPacketWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::SendMaliciousPacketOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(SendMaliciousPacketChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::SendMaliciousPacketOutcome1Step::timeDistributionParameter0() {
return 1;
}

double CarADVISE::SendMaliciousPacketOutcome1Step::Weight() {
  return 1;
}

bool CarADVISE::SendMaliciousPacketOutcome1Step::ReactivationPredicate() {
  return false;
}

bool CarADVISE::SendMaliciousPacketOutcome1Step::ReactivationFunction() {
  return false;
}

double CarADVISE::SendMaliciousPacketOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *CarADVISE::SendMaliciousPacketOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::SendMaliciousPacketOutcome1Step::Rank() {
  return 1;
}

bool CarADVISE::SendMaliciousPacketOutcome1Step::preconditionsMet() {

  return true;
}

void CarADVISE::SendMaliciousPacketOutcome1Step::executeEffects() {

}

double CarADVISE::SendMaliciousPacketOutcome1Step::getCost() {

}

double CarADVISE::SendMaliciousPacketOutcome1Step::getOutcomeProbability() {
return 1;
}

double CarADVISE::SendMaliciousPacketOutcome1Step::getDetection() {
return 0;
}

/*====================== DoNothingOutcome1Step ========================*/

CarADVISE::DoNothingOutcome1Step::DoNothingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("DoNothingOutcome1Step", 1, Deterministic, RaceEnabled, 5, 0, false);}

CarADVISE::DoNothingOutcome1Step::~DoNothingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void CarADVISE::DoNothingOutcome1Step::LinkVariables() {
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  SendMaliciousPacketWeight->Register(&SendMaliciousPacketWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::DoNothingOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DoNothingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::DoNothingOutcome1Step::timeDistributionParameter0() {
return 1;
}

double CarADVISE::DoNothingOutcome1Step::Weight() {
  return 1;
}

bool CarADVISE::DoNothingOutcome1Step::ReactivationPredicate() {
  return false;
}

bool CarADVISE::DoNothingOutcome1Step::ReactivationFunction() {
  return false;
}

double CarADVISE::DoNothingOutcome1Step::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::DoNothingOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::DoNothingOutcome1Step::Rank() {
  return 1;
}

bool CarADVISE::DoNothingOutcome1Step::preconditionsMet() {

  return true;
}

void CarADVISE::DoNothingOutcome1Step::executeEffects() {

}

double CarADVISE::DoNothingOutcome1Step::getCost() {
return 0;
}

double CarADVISE::DoNothingOutcome1Step::getOutcomeProbability() {
return 1;
}

double CarADVISE::DoNothingOutcome1Step::getDetection() {
return 0;
}

/*====================== ImpersonateOEMOutcome1Step ========================*/

CarADVISE::ImpersonateOEMOutcome1Step::ImpersonateOEMOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("ImpersonateOEMOutcome1Step", 2, Exponential, RaceEnabled, 9, 1, false);}

CarADVISE::ImpersonateOEMOutcome1Step::~ImpersonateOEMOutcome1Step() {
  delete[] TheDistributionParameters;
}

void CarADVISE::ImpersonateOEMOutcome1Step::LinkVariables() {
  StealPrivateData->Register(&StealPrivateData_Mobius_Mark);
  CarModelKnowledge->Register(&CarModelKnowledge_Mobius_Mark);
  CarWirelessNetworkAccess->Register(&CarWirelessNetworkAccess_Mobius_Mark);
  SpoofingSkill->Register(&SpoofingSkill_Mobius_Mark);
  ImpersonateOEMChosen->Register(&ImpersonateOEMChosen_Mobius_Mark);
  SendMaliciousPacketWeight->Register(&SendMaliciousPacketWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::ImpersonateOEMOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ImpersonateOEMChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ImpersonateOEMOutcome1Step::timeDistributionParameter0() {
return 1;
}

double CarADVISE::ImpersonateOEMOutcome1Step::Weight() {
  return 1;
}

bool CarADVISE::ImpersonateOEMOutcome1Step::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ImpersonateOEMOutcome1Step::ReactivationFunction() {
  return false;
}

double CarADVISE::ImpersonateOEMOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *CarADVISE::ImpersonateOEMOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::ImpersonateOEMOutcome1Step::Rank() {
  return 1;
}

bool CarADVISE::ImpersonateOEMOutcome1Step::preconditionsMet() {

  return true;
}

void CarADVISE::ImpersonateOEMOutcome1Step::executeEffects() {

}

double CarADVISE::ImpersonateOEMOutcome1Step::getCost() {

}

double CarADVISE::ImpersonateOEMOutcome1Step::getOutcomeProbability() {
return 1;
}

double CarADVISE::ImpersonateOEMOutcome1Step::getDetection() {
return 0;
}

/*****************************************************************/
/*                   Adversary Decisions                         */
/*****************************************************************/

/*====================== SendMaliciousPacketAdversaryDecision ========================*/

CarADVISE::SendMaliciousPacketAdversaryDecision::SendMaliciousPacketAdversaryDecision() {
  commonInit("SendMaliciousPacketAdversaryDecision", 3, Instantaneous, RaceEnabled, 2, 1, false);
}

CarADVISE::SendMaliciousPacketAdversaryDecision::~SendMaliciousPacketAdversaryDecision() {
}

void CarADVISE::SendMaliciousPacketAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  SendMaliciousPacketChosen->Register(&SendMaliciousPacketChosen_Mobius_Mark);
  SendMaliciousPacketWeight->Register(&SendMaliciousPacketWeight_Mobius_Mark);
}

bool CarADVISE::SendMaliciousPacketAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::SendMaliciousPacketAdversaryDecision::Weight() {
  return SendMaliciousPacketWeight->Mark();
}

bool CarADVISE::SendMaliciousPacketAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool CarADVISE::SendMaliciousPacketAdversaryDecision::ReactivationFunction() {
  return false;
}

double CarADVISE::SendMaliciousPacketAdversaryDecision::SampleDistribution() {
  return 0;
}

double* CarADVISE::SendMaliciousPacketAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int CarADVISE::SendMaliciousPacketAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* CarADVISE::SendMaliciousPacketAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(SendMaliciousPacketWeight_Mobius_Mark))--;
  (*(SendMaliciousPacketChosen_Mobius_Mark))++;
  return this;
}

/*====================== DoNothingAdversaryDecision ========================*/

CarADVISE::DoNothingAdversaryDecision::DoNothingAdversaryDecision() {
  commonInit("DoNothingAdversaryDecision", 3, Instantaneous, RaceEnabled, 2, 1, false);
}

CarADVISE::DoNothingAdversaryDecision::~DoNothingAdversaryDecision() {
}

void CarADVISE::DoNothingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
}

bool CarADVISE::DoNothingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::DoNothingAdversaryDecision::Weight() {
  return DoNothingWeight->Mark();
}

bool CarADVISE::DoNothingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool CarADVISE::DoNothingAdversaryDecision::ReactivationFunction() {
  return false;
}

double CarADVISE::DoNothingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* CarADVISE::DoNothingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int CarADVISE::DoNothingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* CarADVISE::DoNothingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(DoNothingWeight_Mobius_Mark))--;
  (*(DoNothingChosen_Mobius_Mark))++;
  return this;
}

/*====================== ImpersonateOEMAdversaryDecision ========================*/

CarADVISE::ImpersonateOEMAdversaryDecision::ImpersonateOEMAdversaryDecision() {
  commonInit("ImpersonateOEMAdversaryDecision", 3, Instantaneous, RaceEnabled, 2, 1, false);
}

CarADVISE::ImpersonateOEMAdversaryDecision::~ImpersonateOEMAdversaryDecision() {
}

void CarADVISE::ImpersonateOEMAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  ImpersonateOEMChosen->Register(&ImpersonateOEMChosen_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
}

bool CarADVISE::ImpersonateOEMAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ImpersonateOEMAdversaryDecision::Weight() {
  return ImpersonateOEMWeight->Mark();
}

bool CarADVISE::ImpersonateOEMAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ImpersonateOEMAdversaryDecision::ReactivationFunction() {
  return false;
}

double CarADVISE::ImpersonateOEMAdversaryDecision::SampleDistribution() {
  return 0;
}

double* CarADVISE::ImpersonateOEMAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int CarADVISE::ImpersonateOEMAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* CarADVISE::ImpersonateOEMAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(ImpersonateOEMWeight_Mobius_Mark))--;
  (*(ImpersonateOEMChosen_Mobius_Mark))++;
  return this;
}

