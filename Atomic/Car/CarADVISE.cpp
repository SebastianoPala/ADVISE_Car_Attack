
#include "Atomic/Car/CarADVISE.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


CarADVISE::CarADVISE() {
  ReflashGatewayChipAD.setParent(this);
  DoNothingAD.setParent(this);
  ExtractDataViaCANBusAD.setParent(this);
  SendV2XMaliciousMessagesAD.setParent(this);
  InjectTamperedBinaryAD.setParent(this);
  InjectMaliciousCANMessagesAD.setParent(this);
  ExtractDataRemotelyAD.setParent(this);
  ImpersonateOEMAD.setParent(this);
  ReflashGatewayChipFailure.setParent(this);
  ReflashGatewayChipSuccess.setParent(this);
  DoNothingNothing.setParent(this);
  ExtractDataViaCANBusFailure.setParent(this);
  ExtractDataViaCANBusSuccess.setParent(this);
  SendV2XMaliciousMessagesFailure.setParent(this);
  SendV2XMaliciousMessagesSuccess.setParent(this);
  InjectTamperedBinaryFailure.setParent(this);
  InjectTamperedBinarySuccess.setParent(this);
  InjectMaliciousCANMessagesFailure.setParent(this);
  InjectMaliciousCANMessagesSuccess.setParent(this);
  ExtractDataRemotelyFailure.setParent(this);
  ExtractDataRemotelySuccess.setParent(this);
  ImpersonateOEMFailure.setParent(this);
  ImpersonateOEMSuccess.setParent(this);
  ReflashGatewayChipGroup.initialize(2, "ReflashGatewayChipGroup");
  ReflashGatewayChipGroup.appendGroup((BaseGroupClass*) &ReflashGatewayChipFailure);
  ReflashGatewayChipGroup.appendGroup((BaseGroupClass*) &ReflashGatewayChipSuccess);

  ExtractDataViaCANBusGroup.initialize(2, "ExtractDataViaCANBusGroup");
  ExtractDataViaCANBusGroup.appendGroup((BaseGroupClass*) &ExtractDataViaCANBusFailure);
  ExtractDataViaCANBusGroup.appendGroup((BaseGroupClass*) &ExtractDataViaCANBusSuccess);

  SendV2XMaliciousMessagesGroup.initialize(2, "SendV2XMaliciousMessagesGroup");
  SendV2XMaliciousMessagesGroup.appendGroup((BaseGroupClass*) &SendV2XMaliciousMessagesFailure);
  SendV2XMaliciousMessagesGroup.appendGroup((BaseGroupClass*) &SendV2XMaliciousMessagesSuccess);

  InjectTamperedBinaryGroup.initialize(2, "InjectTamperedBinaryGroup");
  InjectTamperedBinaryGroup.appendGroup((BaseGroupClass*) &InjectTamperedBinaryFailure);
  InjectTamperedBinaryGroup.appendGroup((BaseGroupClass*) &InjectTamperedBinarySuccess);

  InjectMaliciousCANMessagesGroup.initialize(2, "InjectMaliciousCANMessagesGroup");
  InjectMaliciousCANMessagesGroup.appendGroup((BaseGroupClass*) &InjectMaliciousCANMessagesFailure);
  InjectMaliciousCANMessagesGroup.appendGroup((BaseGroupClass*) &InjectMaliciousCANMessagesSuccess);

  ExtractDataRemotelyGroup.initialize(2, "ExtractDataRemotelyGroup");
  ExtractDataRemotelyGroup.appendGroup((BaseGroupClass*) &ExtractDataRemotelyFailure);
  ExtractDataRemotelyGroup.appendGroup((BaseGroupClass*) &ExtractDataRemotelySuccess);

  ImpersonateOEMGroup.initialize(2, "ImpersonateOEMGroup");
  ImpersonateOEMGroup.appendGroup((BaseGroupClass*) &ImpersonateOEMFailure);
  ImpersonateOEMGroup.appendGroup((BaseGroupClass*) &ImpersonateOEMSuccess);

  AdversaryDecisionGroup.initialize(8, "AdversaryDecisionGroup");
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ReflashGatewayChipAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DoNothingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ExtractDataViaCANBusAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &SendV2XMaliciousMessagesAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &InjectTamperedBinaryAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &InjectMaliciousCANMessagesAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ExtractDataRemotelyAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ImpersonateOEMAD);

  BaseADVISEAction* InitialActions[23] = {
    &ReflashGatewayChipAD, // 0
    &DoNothingAD, // 1
    &ExtractDataViaCANBusAD, // 2
    &SendV2XMaliciousMessagesAD, // 3
    &InjectTamperedBinaryAD, // 4
    &InjectMaliciousCANMessagesAD, // 5
    &ExtractDataRemotelyAD, // 6
    &ImpersonateOEMAD, // 7
    &ReflashGatewayChipFailure, // 8
    &ReflashGatewayChipSuccess, // 9
    &DoNothingNothing, // 10
    &ExtractDataViaCANBusFailure, // 11
    &ExtractDataViaCANBusSuccess, // 12
    &SendV2XMaliciousMessagesFailure, // 13
    &SendV2XMaliciousMessagesSuccess, // 14
    &InjectTamperedBinaryFailure, // 15
    &InjectTamperedBinarySuccess, // 16
    &InjectMaliciousCANMessagesFailure, // 17
    &InjectMaliciousCANMessagesSuccess, // 18
    &ExtractDataRemotelyFailure, // 19
    &ExtractDataRemotelySuccess, // 20
    &ImpersonateOEMFailure, // 21
    &ImpersonateOEMSuccess // 22
  };

  Step* InitialSteps[15] = {
      &ReflashGatewayChipFailure,
      &ReflashGatewayChipSuccess,
      &DoNothingNothing,
      &ExtractDataViaCANBusFailure,
      &ExtractDataViaCANBusSuccess,
      &SendV2XMaliciousMessagesFailure,
      &SendV2XMaliciousMessagesSuccess,
      &InjectTamperedBinaryFailure,
      &InjectTamperedBinarySuccess,
      &InjectMaliciousCANMessagesFailure,
      &InjectMaliciousCANMessagesSuccess,
      &ExtractDataRemotelyFailure,
      &ExtractDataRemotelySuccess,
      &ImpersonateOEMFailure,
      &ImpersonateOEMSuccess
  };

  BaseGroupClass* InitialGroups[9] = {
    (BaseGroupClass*) &ReflashGatewayChipGroup, // 0
    (BaseGroupClass*) &DoNothingNothing, // 1
    (BaseGroupClass*) &ExtractDataViaCANBusGroup, // 2
    (BaseGroupClass*) &SendV2XMaliciousMessagesGroup, // 3
    (BaseGroupClass*) &InjectTamperedBinaryGroup, // 4
    (BaseGroupClass*) &InjectMaliciousCANMessagesGroup, // 5
    (BaseGroupClass*) &ExtractDataRemotelyGroup, // 6
    (BaseGroupClass*) &ImpersonateOEMGroup, // 7
    (BaseGroupClass*) &AdversaryDecisionGroup
  };

  InternalRemoteAccess = new Access("InternalRemoteAccess", 0);
  ProximityNetworkAccess = new Access("ProximityNetworkAccess", hasProximityAccess);
  CompromisedGatewayAccess = new Access("CompromisedGatewayAccess", 0);
  RemoteNetworkAccess = new Access("RemoteNetworkAccess", hasRemoteNetworkAccess);
  InternalCANAccess = new Access("InternalCANAccess", 0);
  MessageFormatKnowledge = new Knowledge("MessageFormatKnowledge", hasMessageFormatKnowledge);
  V2xProtocolKnowledge = new Knowledge("V2xProtocolKnowledge", hasV2XProtocolKnowledge);
  CarModelKnowledge = new Knowledge("CarModelKnowledge", hasCarModelKnowledge);
  SpoofingSkill = new Skill("SpoofingSkill", spoofingSkillLevel);
  V2XPacketCraftingSkill = new Skill("V2XPacketCraftingSkill", v2XPacketCraftingSkillLevel);
  InjectionSkill = new Skill("InjectionSkill", injectionSkillLevel);
  DataExtractionSkill = new Skill("DataExtractionSkill", dataExtractionSkillLevel);
  ChipFlashingSkill = new Skill("ChipFlashingSkill", chipFlashingSkillLevel);
  StealPrivateData = new Goal("StealPrivateData", 0);
  StealPrivateData->setPayoff(1000);
  MakeDecision = new BeginAdversaryDecision("MakeDecision", 0);
  ReflashGatewayChipWeight = new StepWeight("ReflashGatewayChipWeight", 0);
  ReflashGatewayChipChosen = new StepChosen("ReflashGatewayChipChosen", 0);
  DoNothingWeight = new StepWeight("DoNothingWeight", 0);
  DoNothingChosen = new StepChosen("DoNothingChosen", 0);
  ExtractDataViaCANBusWeight = new StepWeight("ExtractDataViaCANBusWeight", 0);
  ExtractDataViaCANBusChosen = new StepChosen("ExtractDataViaCANBusChosen", 0);
  SendV2XMaliciousMessagesWeight = new StepWeight("SendV2XMaliciousMessagesWeight", 0);
  SendV2XMaliciousMessagesChosen = new StepChosen("SendV2XMaliciousMessagesChosen", 0);
  InjectTamperedBinaryWeight = new StepWeight("InjectTamperedBinaryWeight", 0);
  InjectTamperedBinaryChosen = new StepChosen("InjectTamperedBinaryChosen", 0);
  InjectMaliciousCANMessagesWeight = new StepWeight("InjectMaliciousCANMessagesWeight", 0);
  InjectMaliciousCANMessagesChosen = new StepChosen("InjectMaliciousCANMessagesChosen", 0);
  ExtractDataRemotelyWeight = new StepWeight("ExtractDataRemotelyWeight", 0);
  ExtractDataRemotelyChosen = new StepChosen("ExtractDataRemotelyChosen", 0);
  ImpersonateOEMWeight = new StepWeight("ImpersonateOEMWeight", 0);
  ImpersonateOEMChosen = new StepChosen("ImpersonateOEMChosen", 0);

  Goal* InitialGoals[1] = {
      StealPrivateData
  };

  ADVISEStateVariable* InitialSVs[31] = {
    InternalRemoteAccess, // 0
    ProximityNetworkAccess, // 1
    CompromisedGatewayAccess, // 2
    RemoteNetworkAccess, // 3
    InternalCANAccess, // 4
    MessageFormatKnowledge, // 5
    V2xProtocolKnowledge, // 6
    CarModelKnowledge, // 7
    SpoofingSkill, // 8
    V2XPacketCraftingSkill, // 9
    InjectionSkill, // 10
    DataExtractionSkill, // 11
    ChipFlashingSkill, // 12
    StealPrivateData, // 13
    ReflashGatewayChipChosen, // 14
    DoNothingChosen, // 15
    ExtractDataViaCANBusChosen, // 16
    SendV2XMaliciousMessagesChosen, // 17
    InjectTamperedBinaryChosen, // 18
    InjectMaliciousCANMessagesChosen, // 19
    ExtractDataRemotelyChosen, // 20
    ImpersonateOEMChosen, // 21
    ReflashGatewayChipWeight, // 22
    DoNothingWeight, // 23
    ExtractDataViaCANBusWeight, // 24
    SendV2XMaliciousMessagesWeight, // 25
    InjectTamperedBinaryWeight, // 26
    InjectMaliciousCANMessagesWeight, // 27
    ExtractDataRemotelyWeight, // 28
    ImpersonateOEMWeight, // 29
    MakeDecision // 30
};

  int outCounts[8] = { 2, 1, 2, 2, 2, 2, 2, 2 };

  commonInit("Car", 31, InitialSVs, 23, InitialActions, 9, InitialGroups, 8, outCounts, InitialSteps, 1, InitialGoals);

  advCostPref = 0.1;
  advDetectPref = 0.3;
  advPayPref = 0.6;

  planningHorizon = 4;
  costDiscount = 1.0;
  detectionDiscount = 1.0;
  payoffDiscount = 1.0;

  assignSVsToAttackSteps();

  int AffectArcs[210][2] = {
    {30,0}, {14,0}, {22,0}, {30,1}, {15,1}, {23,1}, {30,2}, {16,2}, 
    {24,2}, {30,3}, {17,3}, {25,3}, {30,4}, {18,4}, {26,4}, {30,5}, 
    {19,5}, {27,5}, {30,6}, {20,6}, {28,6}, {30,7}, {21,7}, {29,7}, 
    {30,8}, {14,8}, {22,8}, {23,8}, {24,8}, {25,8}, {26,8}, {27,8}, 
    {28,8}, {29,8}, {2,8}, {0,8}, {7,8}, {30,9}, {14,9}, {22,9}, 
    {23,9}, {24,9}, {25,9}, {26,9}, {27,9}, {28,9}, {29,9}, {2,9}, 
    {0,9}, {7,9}, {30,10}, {15,10}, {22,10}, {23,10}, {24,10}, {25,10}, 
    {26,10}, {27,10}, {28,10}, {29,10}, {30,11}, {16,11}, {22,11}, {23,11}, 
    {24,11}, {25,11}, {26,11}, {27,11}, {28,11}, {29,11}, {13,11}, {4,11}, 
    {30,12}, {16,12}, {22,12}, {23,12}, {24,12}, {25,12}, {26,12}, {27,12}, 
    {28,12}, {29,12}, {13,12}, {4,12}, {30,13}, {17,13}, {22,13}, {23,13}, 
    {24,13}, {25,13}, {26,13}, {27,13}, {28,13}, {29,13}, {2,13}, {1,13}, 
    {6,13}, {30,14}, {17,14}, {22,14}, {23,14}, {24,14}, {25,14}, {26,14}, 
    {27,14}, {28,14}, {29,14}, {2,14}, {1,14}, {6,14}, {30,15}, {18,15}, 
    {22,15}, {23,15}, {24,15}, {25,15}, {26,15}, {27,15}, {28,15}, {29,15}, 
    {0,15}, {3,15}, {5,15}, {30,16}, {18,16}, {22,16}, {23,16}, {24,16}, 
    {25,16}, {26,16}, {27,16}, {28,16}, {29,16}, {0,16}, {3,16}, {5,16}, 
    {30,17}, {19,17}, {22,17}, {23,17}, {24,17}, {25,17}, {26,17}, {27,17}, 
    {28,17}, {29,17}, {4,17}, {2,17}, {30,18}, {19,18}, {22,18}, {23,18}, 
    {24,18}, {25,18}, {26,18}, {27,18}, {28,18}, {29,18}, {4,18}, {2,18}, 
    {30,19}, {20,19}, {22,19}, {23,19}, {24,19}, {25,19}, {26,19}, {27,19}, 
    {28,19}, {29,19}, {13,19}, {0,19}, {30,20}, {20,20}, {22,20}, {23,20}, 
    {24,20}, {25,20}, {26,20}, {27,20}, {28,20}, {29,20}, {13,20}, {0,20}, 
    {30,21}, {21,21}, {22,21}, {23,21}, {24,21}, {25,21}, {26,21}, {27,21}, 
    {28,21}, {29,21}, {0,21}, {3,21}, {7,21}, {30,22}, {21,22}, {22,22}, 
    {23,22}, {24,22}, {25,22}, {26,22}, {27,22}, {28,22}, {29,22}, {0,22}, 
    {3,22}, {7,22}
};
  for(int n = 0; n < 210;n++)
    AddAffectArc(InitialSVs[AffectArcs[n][0]], InitialActions[AffectArcs[n][1]]);
  int EnableArcs[37][2] = {
    {30,0}, {30,1}, {30,2}, {30,3}, {30,4}, {30,5}, {30,6}, {30,7}, 
    {14,8}, {2,8}, {14,9}, {2,9}, {15,10}, {16,11}, {13,11}, {16,12}, 
    {13,12}, {17,13}, {2,13}, {17,14}, {2,14}, {18,15}, {0,15}, {18,16}, 
    {0,16}, {19,17}, {4,17}, {19,18}, {4,18}, {20,19}, {13,19}, {20,20}, 
    {13,20}, {21,21}, {0,21}, {21,22}, {0,22}
};
  for(int n = 0; n < 37;n++)
    AddEnableArc(InitialSVs[EnableArcs[n][0]], InitialActions[EnableArcs[n][1]]);
  for(int x = 0; x < 23; x++) {
    InitialActions[x]->LinkVariables();
  }

  customInitialization();

  recalculateAdversaryDecisionWeights();

}

CarADVISE::~CarADVISE() {
}

void CarADVISE::assignSVsToAttackSteps() {
  ReflashGatewayChipFailure.CompromisedGatewayAccess = CompromisedGatewayAccess;
  ReflashGatewayChipFailure.InternalRemoteAccess = InternalRemoteAccess;
  ReflashGatewayChipFailure.CarModelKnowledge = CarModelKnowledge;
  ReflashGatewayChipFailure.ChipFlashingSkill = ChipFlashingSkill;
  ReflashGatewayChipFailure.ReflashGatewayChipChosen = ReflashGatewayChipChosen;
  ReflashGatewayChipFailure.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  ReflashGatewayChipFailure.DoNothingWeight = DoNothingWeight;
  ReflashGatewayChipFailure.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  ReflashGatewayChipFailure.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  ReflashGatewayChipFailure.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  ReflashGatewayChipFailure.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  ReflashGatewayChipFailure.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  ReflashGatewayChipFailure.ImpersonateOEMWeight = ImpersonateOEMWeight;
  ReflashGatewayChipFailure.MakeDecision = MakeDecision;
  ReflashGatewayChipFailure.setSVs(ReflashGatewayChipChosen, ReflashGatewayChipWeight);
  ReflashGatewayChipSuccess.CompromisedGatewayAccess = CompromisedGatewayAccess;
  ReflashGatewayChipSuccess.InternalRemoteAccess = InternalRemoteAccess;
  ReflashGatewayChipSuccess.CarModelKnowledge = CarModelKnowledge;
  ReflashGatewayChipSuccess.ChipFlashingSkill = ChipFlashingSkill;
  ReflashGatewayChipSuccess.ReflashGatewayChipChosen = ReflashGatewayChipChosen;
  ReflashGatewayChipSuccess.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  ReflashGatewayChipSuccess.DoNothingWeight = DoNothingWeight;
  ReflashGatewayChipSuccess.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  ReflashGatewayChipSuccess.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  ReflashGatewayChipSuccess.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  ReflashGatewayChipSuccess.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  ReflashGatewayChipSuccess.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  ReflashGatewayChipSuccess.ImpersonateOEMWeight = ImpersonateOEMWeight;
  ReflashGatewayChipSuccess.MakeDecision = MakeDecision;
  ReflashGatewayChipSuccess.setSVs(ReflashGatewayChipChosen, ReflashGatewayChipWeight);
  DoNothingNothing.DoNothingChosen = DoNothingChosen;
  DoNothingNothing.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  DoNothingNothing.DoNothingWeight = DoNothingWeight;
  DoNothingNothing.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  DoNothingNothing.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  DoNothingNothing.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  DoNothingNothing.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  DoNothingNothing.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  DoNothingNothing.ImpersonateOEMWeight = ImpersonateOEMWeight;
  DoNothingNothing.MakeDecision = MakeDecision;
  DoNothingNothing.setSVs(DoNothingChosen, DoNothingWeight);
  ExtractDataViaCANBusFailure.StealPrivateData = StealPrivateData;
  ExtractDataViaCANBusFailure.InternalCANAccess = InternalCANAccess;
  ExtractDataViaCANBusFailure.DataExtractionSkill = DataExtractionSkill;
  ExtractDataViaCANBusFailure.ExtractDataViaCANBusChosen = ExtractDataViaCANBusChosen;
  ExtractDataViaCANBusFailure.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  ExtractDataViaCANBusFailure.DoNothingWeight = DoNothingWeight;
  ExtractDataViaCANBusFailure.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  ExtractDataViaCANBusFailure.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  ExtractDataViaCANBusFailure.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  ExtractDataViaCANBusFailure.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  ExtractDataViaCANBusFailure.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  ExtractDataViaCANBusFailure.ImpersonateOEMWeight = ImpersonateOEMWeight;
  ExtractDataViaCANBusFailure.MakeDecision = MakeDecision;
  ExtractDataViaCANBusFailure.setSVs(ExtractDataViaCANBusChosen, ExtractDataViaCANBusWeight);
  ExtractDataViaCANBusSuccess.StealPrivateData = StealPrivateData;
  ExtractDataViaCANBusSuccess.InternalCANAccess = InternalCANAccess;
  ExtractDataViaCANBusSuccess.DataExtractionSkill = DataExtractionSkill;
  ExtractDataViaCANBusSuccess.ExtractDataViaCANBusChosen = ExtractDataViaCANBusChosen;
  ExtractDataViaCANBusSuccess.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  ExtractDataViaCANBusSuccess.DoNothingWeight = DoNothingWeight;
  ExtractDataViaCANBusSuccess.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  ExtractDataViaCANBusSuccess.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  ExtractDataViaCANBusSuccess.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  ExtractDataViaCANBusSuccess.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  ExtractDataViaCANBusSuccess.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  ExtractDataViaCANBusSuccess.ImpersonateOEMWeight = ImpersonateOEMWeight;
  ExtractDataViaCANBusSuccess.MakeDecision = MakeDecision;
  ExtractDataViaCANBusSuccess.setSVs(ExtractDataViaCANBusChosen, ExtractDataViaCANBusWeight);
  SendV2XMaliciousMessagesFailure.CompromisedGatewayAccess = CompromisedGatewayAccess;
  SendV2XMaliciousMessagesFailure.V2XPacketCraftingSkill = V2XPacketCraftingSkill;
  SendV2XMaliciousMessagesFailure.ProximityNetworkAccess = ProximityNetworkAccess;
  SendV2XMaliciousMessagesFailure.V2xProtocolKnowledge = V2xProtocolKnowledge;
  SendV2XMaliciousMessagesFailure.SendV2XMaliciousMessagesChosen = SendV2XMaliciousMessagesChosen;
  SendV2XMaliciousMessagesFailure.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  SendV2XMaliciousMessagesFailure.DoNothingWeight = DoNothingWeight;
  SendV2XMaliciousMessagesFailure.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  SendV2XMaliciousMessagesFailure.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  SendV2XMaliciousMessagesFailure.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  SendV2XMaliciousMessagesFailure.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  SendV2XMaliciousMessagesFailure.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  SendV2XMaliciousMessagesFailure.ImpersonateOEMWeight = ImpersonateOEMWeight;
  SendV2XMaliciousMessagesFailure.MakeDecision = MakeDecision;
  SendV2XMaliciousMessagesFailure.setSVs(SendV2XMaliciousMessagesChosen, SendV2XMaliciousMessagesWeight);
  SendV2XMaliciousMessagesSuccess.CompromisedGatewayAccess = CompromisedGatewayAccess;
  SendV2XMaliciousMessagesSuccess.V2XPacketCraftingSkill = V2XPacketCraftingSkill;
  SendV2XMaliciousMessagesSuccess.ProximityNetworkAccess = ProximityNetworkAccess;
  SendV2XMaliciousMessagesSuccess.V2xProtocolKnowledge = V2xProtocolKnowledge;
  SendV2XMaliciousMessagesSuccess.SendV2XMaliciousMessagesChosen = SendV2XMaliciousMessagesChosen;
  SendV2XMaliciousMessagesSuccess.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  SendV2XMaliciousMessagesSuccess.DoNothingWeight = DoNothingWeight;
  SendV2XMaliciousMessagesSuccess.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  SendV2XMaliciousMessagesSuccess.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  SendV2XMaliciousMessagesSuccess.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  SendV2XMaliciousMessagesSuccess.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  SendV2XMaliciousMessagesSuccess.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  SendV2XMaliciousMessagesSuccess.ImpersonateOEMWeight = ImpersonateOEMWeight;
  SendV2XMaliciousMessagesSuccess.MakeDecision = MakeDecision;
  SendV2XMaliciousMessagesSuccess.setSVs(SendV2XMaliciousMessagesChosen, SendV2XMaliciousMessagesWeight);
  InjectTamperedBinaryFailure.InternalRemoteAccess = InternalRemoteAccess;
  InjectTamperedBinaryFailure.RemoteNetworkAccess = RemoteNetworkAccess;
  InjectTamperedBinaryFailure.InjectionSkill = InjectionSkill;
  InjectTamperedBinaryFailure.MessageFormatKnowledge = MessageFormatKnowledge;
  InjectTamperedBinaryFailure.InjectTamperedBinaryChosen = InjectTamperedBinaryChosen;
  InjectTamperedBinaryFailure.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  InjectTamperedBinaryFailure.DoNothingWeight = DoNothingWeight;
  InjectTamperedBinaryFailure.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  InjectTamperedBinaryFailure.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  InjectTamperedBinaryFailure.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  InjectTamperedBinaryFailure.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  InjectTamperedBinaryFailure.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  InjectTamperedBinaryFailure.ImpersonateOEMWeight = ImpersonateOEMWeight;
  InjectTamperedBinaryFailure.MakeDecision = MakeDecision;
  InjectTamperedBinaryFailure.setSVs(InjectTamperedBinaryChosen, InjectTamperedBinaryWeight);
  InjectTamperedBinarySuccess.InternalRemoteAccess = InternalRemoteAccess;
  InjectTamperedBinarySuccess.RemoteNetworkAccess = RemoteNetworkAccess;
  InjectTamperedBinarySuccess.InjectionSkill = InjectionSkill;
  InjectTamperedBinarySuccess.MessageFormatKnowledge = MessageFormatKnowledge;
  InjectTamperedBinarySuccess.InjectTamperedBinaryChosen = InjectTamperedBinaryChosen;
  InjectTamperedBinarySuccess.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  InjectTamperedBinarySuccess.DoNothingWeight = DoNothingWeight;
  InjectTamperedBinarySuccess.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  InjectTamperedBinarySuccess.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  InjectTamperedBinarySuccess.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  InjectTamperedBinarySuccess.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  InjectTamperedBinarySuccess.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  InjectTamperedBinarySuccess.ImpersonateOEMWeight = ImpersonateOEMWeight;
  InjectTamperedBinarySuccess.MakeDecision = MakeDecision;
  InjectTamperedBinarySuccess.setSVs(InjectTamperedBinaryChosen, InjectTamperedBinaryWeight);
  InjectMaliciousCANMessagesFailure.InternalCANAccess = InternalCANAccess;
  InjectMaliciousCANMessagesFailure.SpoofingSkill = SpoofingSkill;
  InjectMaliciousCANMessagesFailure.CompromisedGatewayAccess = CompromisedGatewayAccess;
  InjectMaliciousCANMessagesFailure.InjectMaliciousCANMessagesChosen = InjectMaliciousCANMessagesChosen;
  InjectMaliciousCANMessagesFailure.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  InjectMaliciousCANMessagesFailure.DoNothingWeight = DoNothingWeight;
  InjectMaliciousCANMessagesFailure.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  InjectMaliciousCANMessagesFailure.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  InjectMaliciousCANMessagesFailure.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  InjectMaliciousCANMessagesFailure.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  InjectMaliciousCANMessagesFailure.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  InjectMaliciousCANMessagesFailure.ImpersonateOEMWeight = ImpersonateOEMWeight;
  InjectMaliciousCANMessagesFailure.MakeDecision = MakeDecision;
  InjectMaliciousCANMessagesFailure.setSVs(InjectMaliciousCANMessagesChosen, InjectMaliciousCANMessagesWeight);
  InjectMaliciousCANMessagesSuccess.InternalCANAccess = InternalCANAccess;
  InjectMaliciousCANMessagesSuccess.SpoofingSkill = SpoofingSkill;
  InjectMaliciousCANMessagesSuccess.CompromisedGatewayAccess = CompromisedGatewayAccess;
  InjectMaliciousCANMessagesSuccess.InjectMaliciousCANMessagesChosen = InjectMaliciousCANMessagesChosen;
  InjectMaliciousCANMessagesSuccess.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  InjectMaliciousCANMessagesSuccess.DoNothingWeight = DoNothingWeight;
  InjectMaliciousCANMessagesSuccess.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  InjectMaliciousCANMessagesSuccess.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  InjectMaliciousCANMessagesSuccess.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  InjectMaliciousCANMessagesSuccess.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  InjectMaliciousCANMessagesSuccess.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  InjectMaliciousCANMessagesSuccess.ImpersonateOEMWeight = ImpersonateOEMWeight;
  InjectMaliciousCANMessagesSuccess.MakeDecision = MakeDecision;
  InjectMaliciousCANMessagesSuccess.setSVs(InjectMaliciousCANMessagesChosen, InjectMaliciousCANMessagesWeight);
  ExtractDataRemotelyFailure.StealPrivateData = StealPrivateData;
  ExtractDataRemotelyFailure.DataExtractionSkill = DataExtractionSkill;
  ExtractDataRemotelyFailure.InternalRemoteAccess = InternalRemoteAccess;
  ExtractDataRemotelyFailure.ExtractDataRemotelyChosen = ExtractDataRemotelyChosen;
  ExtractDataRemotelyFailure.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  ExtractDataRemotelyFailure.DoNothingWeight = DoNothingWeight;
  ExtractDataRemotelyFailure.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  ExtractDataRemotelyFailure.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  ExtractDataRemotelyFailure.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  ExtractDataRemotelyFailure.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  ExtractDataRemotelyFailure.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  ExtractDataRemotelyFailure.ImpersonateOEMWeight = ImpersonateOEMWeight;
  ExtractDataRemotelyFailure.MakeDecision = MakeDecision;
  ExtractDataRemotelyFailure.setSVs(ExtractDataRemotelyChosen, ExtractDataRemotelyWeight);
  ExtractDataRemotelySuccess.StealPrivateData = StealPrivateData;
  ExtractDataRemotelySuccess.DataExtractionSkill = DataExtractionSkill;
  ExtractDataRemotelySuccess.InternalRemoteAccess = InternalRemoteAccess;
  ExtractDataRemotelySuccess.ExtractDataRemotelyChosen = ExtractDataRemotelyChosen;
  ExtractDataRemotelySuccess.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  ExtractDataRemotelySuccess.DoNothingWeight = DoNothingWeight;
  ExtractDataRemotelySuccess.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  ExtractDataRemotelySuccess.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  ExtractDataRemotelySuccess.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  ExtractDataRemotelySuccess.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  ExtractDataRemotelySuccess.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  ExtractDataRemotelySuccess.ImpersonateOEMWeight = ImpersonateOEMWeight;
  ExtractDataRemotelySuccess.MakeDecision = MakeDecision;
  ExtractDataRemotelySuccess.setSVs(ExtractDataRemotelyChosen, ExtractDataRemotelyWeight);
  ImpersonateOEMFailure.InternalRemoteAccess = InternalRemoteAccess;
  ImpersonateOEMFailure.RemoteNetworkAccess = RemoteNetworkAccess;
  ImpersonateOEMFailure.CarModelKnowledge = CarModelKnowledge;
  ImpersonateOEMFailure.SpoofingSkill = SpoofingSkill;
  ImpersonateOEMFailure.ImpersonateOEMChosen = ImpersonateOEMChosen;
  ImpersonateOEMFailure.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  ImpersonateOEMFailure.DoNothingWeight = DoNothingWeight;
  ImpersonateOEMFailure.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  ImpersonateOEMFailure.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  ImpersonateOEMFailure.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  ImpersonateOEMFailure.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  ImpersonateOEMFailure.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  ImpersonateOEMFailure.ImpersonateOEMWeight = ImpersonateOEMWeight;
  ImpersonateOEMFailure.MakeDecision = MakeDecision;
  ImpersonateOEMFailure.setSVs(ImpersonateOEMChosen, ImpersonateOEMWeight);
  ImpersonateOEMSuccess.InternalRemoteAccess = InternalRemoteAccess;
  ImpersonateOEMSuccess.RemoteNetworkAccess = RemoteNetworkAccess;
  ImpersonateOEMSuccess.CarModelKnowledge = CarModelKnowledge;
  ImpersonateOEMSuccess.SpoofingSkill = SpoofingSkill;
  ImpersonateOEMSuccess.ImpersonateOEMChosen = ImpersonateOEMChosen;
  ImpersonateOEMSuccess.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  ImpersonateOEMSuccess.DoNothingWeight = DoNothingWeight;
  ImpersonateOEMSuccess.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  ImpersonateOEMSuccess.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  ImpersonateOEMSuccess.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  ImpersonateOEMSuccess.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  ImpersonateOEMSuccess.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
  ImpersonateOEMSuccess.ImpersonateOEMWeight = ImpersonateOEMWeight;
  ImpersonateOEMSuccess.MakeDecision = MakeDecision;
  ImpersonateOEMSuccess.setSVs(ImpersonateOEMChosen, ImpersonateOEMWeight);

  ReflashGatewayChipAD.MakeDecision = MakeDecision;
  ReflashGatewayChipAD.ReflashGatewayChipChosen = ReflashGatewayChipChosen;
  ReflashGatewayChipAD.ReflashGatewayChipWeight = ReflashGatewayChipWeight;
  DoNothingAD.MakeDecision = MakeDecision;
  DoNothingAD.DoNothingChosen = DoNothingChosen;
  DoNothingAD.DoNothingWeight = DoNothingWeight;
  ExtractDataViaCANBusAD.MakeDecision = MakeDecision;
  ExtractDataViaCANBusAD.ExtractDataViaCANBusChosen = ExtractDataViaCANBusChosen;
  ExtractDataViaCANBusAD.ExtractDataViaCANBusWeight = ExtractDataViaCANBusWeight;
  SendV2XMaliciousMessagesAD.MakeDecision = MakeDecision;
  SendV2XMaliciousMessagesAD.SendV2XMaliciousMessagesChosen = SendV2XMaliciousMessagesChosen;
  SendV2XMaliciousMessagesAD.SendV2XMaliciousMessagesWeight = SendV2XMaliciousMessagesWeight;
  InjectTamperedBinaryAD.MakeDecision = MakeDecision;
  InjectTamperedBinaryAD.InjectTamperedBinaryChosen = InjectTamperedBinaryChosen;
  InjectTamperedBinaryAD.InjectTamperedBinaryWeight = InjectTamperedBinaryWeight;
  InjectMaliciousCANMessagesAD.MakeDecision = MakeDecision;
  InjectMaliciousCANMessagesAD.InjectMaliciousCANMessagesChosen = InjectMaliciousCANMessagesChosen;
  InjectMaliciousCANMessagesAD.InjectMaliciousCANMessagesWeight = InjectMaliciousCANMessagesWeight;
  ExtractDataRemotelyAD.MakeDecision = MakeDecision;
  ExtractDataRemotelyAD.ExtractDataRemotelyChosen = ExtractDataRemotelyChosen;
  ExtractDataRemotelyAD.ExtractDataRemotelyWeight = ExtractDataRemotelyWeight;
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

/*====================== ReflashGatewayChipFailureStep ========================*/

CarADVISE::ReflashGatewayChipFailureStep::ReflashGatewayChipFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("ReflashGatewayChipFailureStep", 0, Deterministic, RaceEnabled, 14, 1, false);}

CarADVISE::ReflashGatewayChipFailureStep::~ReflashGatewayChipFailureStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::ReflashGatewayChipFailureStep::LinkVariables() {
  CompromisedGatewayAccess->Register(&CompromisedGatewayAccess_Mobius_Mark);
  InternalRemoteAccess->Register(&InternalRemoteAccess_Mobius_Mark);
  CarModelKnowledge->Register(&CarModelKnowledge_Mobius_Mark);
  ChipFlashingSkill->Register(&ChipFlashingSkill_Mobius_Mark);
  ReflashGatewayChipChosen->Register(&ReflashGatewayChipChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::ReflashGatewayChipFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ReflashGatewayChipChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ReflashGatewayChipFailureStep::timeDistributionParameter0() {
if(ChipFlashingSkill->Mark() < FlashingSkillExpertise)
			return 9;
else
			return 5;
}

double CarADVISE::ReflashGatewayChipFailureStep::Weight() {
return 0.25;
}

bool CarADVISE::ReflashGatewayChipFailureStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ReflashGatewayChipFailureStep::ReactivationFunction() {
  return false;
}

double CarADVISE::ReflashGatewayChipFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::ReflashGatewayChipFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::ReflashGatewayChipFailureStep::Rank() {
  return 1;
}

bool CarADVISE::ReflashGatewayChipFailureStep::preconditionsMet() {
return CompromisedGatewayAccess->Mark() == 0 && InternalRemoteAccess->Mark() && CarModelKnowledge->Mark() && ChipFlashingSkill->Mark() >= chipFlashingSkillThreshold;
  return true;
}

void CarADVISE::ReflashGatewayChipFailureStep::executeEffects() {

}

double CarADVISE::ReflashGatewayChipFailureStep::getCost() {
if(ChipFlashingSkill->Mark() < FlashingSkillExpertise)
			return 9;
else
			return 5;
}

double CarADVISE::ReflashGatewayChipFailureStep::getOutcomeProbability() {
return 0.25;
}

double CarADVISE::ReflashGatewayChipFailureStep::getDetection() {
return 0.2;
}

/*====================== ReflashGatewayChipSuccessStep ========================*/

CarADVISE::ReflashGatewayChipSuccessStep::ReflashGatewayChipSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("ReflashGatewayChipSuccessStep", 0, Deterministic, RaceEnabled, 14, 1, false);}

CarADVISE::ReflashGatewayChipSuccessStep::~ReflashGatewayChipSuccessStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::ReflashGatewayChipSuccessStep::LinkVariables() {
  CompromisedGatewayAccess->Register(&CompromisedGatewayAccess_Mobius_Mark);
  InternalRemoteAccess->Register(&InternalRemoteAccess_Mobius_Mark);
  CarModelKnowledge->Register(&CarModelKnowledge_Mobius_Mark);
  ChipFlashingSkill->Register(&ChipFlashingSkill_Mobius_Mark);
  ReflashGatewayChipChosen->Register(&ReflashGatewayChipChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::ReflashGatewayChipSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ReflashGatewayChipChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ReflashGatewayChipSuccessStep::timeDistributionParameter0() {
if(ChipFlashingSkill->Mark() < FlashingSkillExpertise)
			return 9;
else
			return 5;
}

double CarADVISE::ReflashGatewayChipSuccessStep::Weight() {
return 0.75;
}

bool CarADVISE::ReflashGatewayChipSuccessStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ReflashGatewayChipSuccessStep::ReactivationFunction() {
  return false;
}

double CarADVISE::ReflashGatewayChipSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::ReflashGatewayChipSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::ReflashGatewayChipSuccessStep::Rank() {
  return 1;
}

bool CarADVISE::ReflashGatewayChipSuccessStep::preconditionsMet() {
return CompromisedGatewayAccess->Mark() == 0 && InternalRemoteAccess->Mark() && CarModelKnowledge->Mark() && ChipFlashingSkill->Mark() >= chipFlashingSkillThreshold;
  return true;
}

void CarADVISE::ReflashGatewayChipSuccessStep::executeEffects() {
CompromisedGatewayAccess->Mark() = true;
}

double CarADVISE::ReflashGatewayChipSuccessStep::getCost() {
if(ChipFlashingSkill->Mark() < FlashingSkillExpertise)
			return 9;
else
			return 5;
}

double CarADVISE::ReflashGatewayChipSuccessStep::getOutcomeProbability() {
return 0.75;
}

double CarADVISE::ReflashGatewayChipSuccessStep::getDetection() {
return 0.1;
}

/*====================== DoNothingNothingStep ========================*/

CarADVISE::DoNothingNothingStep::DoNothingNothingStep() {
  TheDistributionParameters = new double[1];
  commonInit("DoNothingNothingStep", 1, Deterministic, RaceEnabled, 10, 0, false);}

CarADVISE::DoNothingNothingStep::~DoNothingNothingStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::DoNothingNothingStep::LinkVariables() {
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::DoNothingNothingStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DoNothingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::DoNothingNothingStep::timeDistributionParameter0() {
return 1;
}

double CarADVISE::DoNothingNothingStep::Weight() {
  return 1;
}

bool CarADVISE::DoNothingNothingStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::DoNothingNothingStep::ReactivationFunction() {
  return false;
}

double CarADVISE::DoNothingNothingStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::DoNothingNothingStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::DoNothingNothingStep::Rank() {
  return 1;
}

bool CarADVISE::DoNothingNothingStep::preconditionsMet() {

  return true;
}

void CarADVISE::DoNothingNothingStep::executeEffects() {

}

double CarADVISE::DoNothingNothingStep::getCost() {
return 0;
}

double CarADVISE::DoNothingNothingStep::getOutcomeProbability() {
return 1;
}

double CarADVISE::DoNothingNothingStep::getDetection() {
return 0;
}

/*====================== ExtractDataViaCANBusFailureStep ========================*/

CarADVISE::ExtractDataViaCANBusFailureStep::ExtractDataViaCANBusFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("ExtractDataViaCANBusFailureStep", 2, Deterministic, RaceEnabled, 13, 1, false);}

CarADVISE::ExtractDataViaCANBusFailureStep::~ExtractDataViaCANBusFailureStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::ExtractDataViaCANBusFailureStep::LinkVariables() {
  StealPrivateData->Register(&StealPrivateData_Mobius_Mark);
  InternalCANAccess->Register(&InternalCANAccess_Mobius_Mark);
  DataExtractionSkill->Register(&DataExtractionSkill_Mobius_Mark);
  ExtractDataViaCANBusChosen->Register(&ExtractDataViaCANBusChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::ExtractDataViaCANBusFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExtractDataViaCANBusChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ExtractDataViaCANBusFailureStep::timeDistributionParameter0() {
return 2;
}

double CarADVISE::ExtractDataViaCANBusFailureStep::Weight() {
return 0.15;
}

bool CarADVISE::ExtractDataViaCANBusFailureStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ExtractDataViaCANBusFailureStep::ReactivationFunction() {
  return false;
}

double CarADVISE::ExtractDataViaCANBusFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::ExtractDataViaCANBusFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::ExtractDataViaCANBusFailureStep::Rank() {
  return 1;
}

bool CarADVISE::ExtractDataViaCANBusFailureStep::preconditionsMet() {
return StealPrivateData->Mark() == 0 && InternalCANAccess->Mark() && DataExtractionSkill->Mark() >= CANExtractionSkillThreshold; 
  return true;
}

void CarADVISE::ExtractDataViaCANBusFailureStep::executeEffects() {

}

double CarADVISE::ExtractDataViaCANBusFailureStep::getCost() {
return 2;
}

double CarADVISE::ExtractDataViaCANBusFailureStep::getOutcomeProbability() {
return 0.15;
}

double CarADVISE::ExtractDataViaCANBusFailureStep::getDetection() {
return 0.15;
}

/*====================== ExtractDataViaCANBusSuccessStep ========================*/

CarADVISE::ExtractDataViaCANBusSuccessStep::ExtractDataViaCANBusSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("ExtractDataViaCANBusSuccessStep", 2, Deterministic, RaceEnabled, 13, 1, false);}

CarADVISE::ExtractDataViaCANBusSuccessStep::~ExtractDataViaCANBusSuccessStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::ExtractDataViaCANBusSuccessStep::LinkVariables() {
  StealPrivateData->Register(&StealPrivateData_Mobius_Mark);
  InternalCANAccess->Register(&InternalCANAccess_Mobius_Mark);
  DataExtractionSkill->Register(&DataExtractionSkill_Mobius_Mark);
  ExtractDataViaCANBusChosen->Register(&ExtractDataViaCANBusChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::ExtractDataViaCANBusSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExtractDataViaCANBusChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ExtractDataViaCANBusSuccessStep::timeDistributionParameter0() {
return 2;
}

double CarADVISE::ExtractDataViaCANBusSuccessStep::Weight() {
return 0.75;
}

bool CarADVISE::ExtractDataViaCANBusSuccessStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ExtractDataViaCANBusSuccessStep::ReactivationFunction() {
  return false;
}

double CarADVISE::ExtractDataViaCANBusSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::ExtractDataViaCANBusSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::ExtractDataViaCANBusSuccessStep::Rank() {
  return 1;
}

bool CarADVISE::ExtractDataViaCANBusSuccessStep::preconditionsMet() {
return StealPrivateData->Mark() == 0 && InternalCANAccess->Mark() && DataExtractionSkill->Mark() >= CANExtractionSkillThreshold; 
  return true;
}

void CarADVISE::ExtractDataViaCANBusSuccessStep::executeEffects() {
StealPrivateData->Mark() = 1;
}

double CarADVISE::ExtractDataViaCANBusSuccessStep::getCost() {
return 2;
}

double CarADVISE::ExtractDataViaCANBusSuccessStep::getOutcomeProbability() {
return 0.75;
}

double CarADVISE::ExtractDataViaCANBusSuccessStep::getDetection() {
return 0.15;
}

/*====================== SendV2XMaliciousMessagesFailureStep ========================*/

CarADVISE::SendV2XMaliciousMessagesFailureStep::SendV2XMaliciousMessagesFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("SendV2XMaliciousMessagesFailureStep", 3, Deterministic, RaceEnabled, 14, 1, false);}

CarADVISE::SendV2XMaliciousMessagesFailureStep::~SendV2XMaliciousMessagesFailureStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::SendV2XMaliciousMessagesFailureStep::LinkVariables() {
  CompromisedGatewayAccess->Register(&CompromisedGatewayAccess_Mobius_Mark);
  V2XPacketCraftingSkill->Register(&V2XPacketCraftingSkill_Mobius_Mark);
  ProximityNetworkAccess->Register(&ProximityNetworkAccess_Mobius_Mark);
  V2xProtocolKnowledge->Register(&V2xProtocolKnowledge_Mobius_Mark);
  SendV2XMaliciousMessagesChosen->Register(&SendV2XMaliciousMessagesChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::SendV2XMaliciousMessagesFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(SendV2XMaliciousMessagesChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::SendV2XMaliciousMessagesFailureStep::timeDistributionParameter0() {
return 3;
}

double CarADVISE::SendV2XMaliciousMessagesFailureStep::Weight() {
return 0.35;
}

bool CarADVISE::SendV2XMaliciousMessagesFailureStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::SendV2XMaliciousMessagesFailureStep::ReactivationFunction() {
  return false;
}

double CarADVISE::SendV2XMaliciousMessagesFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::SendV2XMaliciousMessagesFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::SendV2XMaliciousMessagesFailureStep::Rank() {
  return 1;
}

bool CarADVISE::SendV2XMaliciousMessagesFailureStep::preconditionsMet() {
return CompromisedGatewayAccess->Mark() == 0 && ProximityNetworkAccess->Mark() && V2xProtocolKnowledge->Mark() && V2XPacketCraftingSkill->Mark() >= v2XPacketCraftingSkillThreshold;
  return true;
}

void CarADVISE::SendV2XMaliciousMessagesFailureStep::executeEffects() {

}

double CarADVISE::SendV2XMaliciousMessagesFailureStep::getCost() {
return 1;
}

double CarADVISE::SendV2XMaliciousMessagesFailureStep::getOutcomeProbability() {
return 0.35;
}

double CarADVISE::SendV2XMaliciousMessagesFailureStep::getDetection() {
return 0.4;
}

/*====================== SendV2XMaliciousMessagesSuccessStep ========================*/

CarADVISE::SendV2XMaliciousMessagesSuccessStep::SendV2XMaliciousMessagesSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("SendV2XMaliciousMessagesSuccessStep", 3, Deterministic, RaceEnabled, 14, 1, false);}

CarADVISE::SendV2XMaliciousMessagesSuccessStep::~SendV2XMaliciousMessagesSuccessStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::SendV2XMaliciousMessagesSuccessStep::LinkVariables() {
  CompromisedGatewayAccess->Register(&CompromisedGatewayAccess_Mobius_Mark);
  V2XPacketCraftingSkill->Register(&V2XPacketCraftingSkill_Mobius_Mark);
  ProximityNetworkAccess->Register(&ProximityNetworkAccess_Mobius_Mark);
  V2xProtocolKnowledge->Register(&V2xProtocolKnowledge_Mobius_Mark);
  SendV2XMaliciousMessagesChosen->Register(&SendV2XMaliciousMessagesChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::SendV2XMaliciousMessagesSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(SendV2XMaliciousMessagesChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::SendV2XMaliciousMessagesSuccessStep::timeDistributionParameter0() {
return 3;
}

double CarADVISE::SendV2XMaliciousMessagesSuccessStep::Weight() {
return 0.65;
}

bool CarADVISE::SendV2XMaliciousMessagesSuccessStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::SendV2XMaliciousMessagesSuccessStep::ReactivationFunction() {
  return false;
}

double CarADVISE::SendV2XMaliciousMessagesSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::SendV2XMaliciousMessagesSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::SendV2XMaliciousMessagesSuccessStep::Rank() {
  return 1;
}

bool CarADVISE::SendV2XMaliciousMessagesSuccessStep::preconditionsMet() {
return CompromisedGatewayAccess->Mark() == 0 && ProximityNetworkAccess->Mark() && V2xProtocolKnowledge->Mark() && V2XPacketCraftingSkill->Mark() >= v2XPacketCraftingSkillThreshold;
  return true;
}

void CarADVISE::SendV2XMaliciousMessagesSuccessStep::executeEffects() {
CompromisedGatewayAccess->Mark() = true;
}

double CarADVISE::SendV2XMaliciousMessagesSuccessStep::getCost() {
return 1;
}

double CarADVISE::SendV2XMaliciousMessagesSuccessStep::getOutcomeProbability() {
return 0.65;
}

double CarADVISE::SendV2XMaliciousMessagesSuccessStep::getDetection() {
return 0.35;
}

/*====================== InjectTamperedBinaryFailureStep ========================*/

CarADVISE::InjectTamperedBinaryFailureStep::InjectTamperedBinaryFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("InjectTamperedBinaryFailureStep", 4, Deterministic, RaceEnabled, 14, 1, false);}

CarADVISE::InjectTamperedBinaryFailureStep::~InjectTamperedBinaryFailureStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::InjectTamperedBinaryFailureStep::LinkVariables() {
  InternalRemoteAccess->Register(&InternalRemoteAccess_Mobius_Mark);
  RemoteNetworkAccess->Register(&RemoteNetworkAccess_Mobius_Mark);
  InjectionSkill->Register(&InjectionSkill_Mobius_Mark);
  MessageFormatKnowledge->Register(&MessageFormatKnowledge_Mobius_Mark);
  InjectTamperedBinaryChosen->Register(&InjectTamperedBinaryChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::InjectTamperedBinaryFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(InjectTamperedBinaryChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::InjectTamperedBinaryFailureStep::timeDistributionParameter0() {
return 7;
}

double CarADVISE::InjectTamperedBinaryFailureStep::Weight() {
return 0.2;
}

bool CarADVISE::InjectTamperedBinaryFailureStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::InjectTamperedBinaryFailureStep::ReactivationFunction() {
  return false;
}

double CarADVISE::InjectTamperedBinaryFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::InjectTamperedBinaryFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::InjectTamperedBinaryFailureStep::Rank() {
  return 1;
}

bool CarADVISE::InjectTamperedBinaryFailureStep::preconditionsMet() {
return InternalRemoteAccess->Mark() == 0 && MessageFormatKnowledge->Mark() && RemoteNetworkAccess->Mark() && InjectionSkill->Mark() >= injectionSkillThreshold;
  return true;
}

void CarADVISE::InjectTamperedBinaryFailureStep::executeEffects() {

}

double CarADVISE::InjectTamperedBinaryFailureStep::getCost() {
return 7;
}

double CarADVISE::InjectTamperedBinaryFailureStep::getOutcomeProbability() {
return 0.2;
}

double CarADVISE::InjectTamperedBinaryFailureStep::getDetection() {
return 0.25;
}

/*====================== InjectTamperedBinarySuccessStep ========================*/

CarADVISE::InjectTamperedBinarySuccessStep::InjectTamperedBinarySuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("InjectTamperedBinarySuccessStep", 4, Deterministic, RaceEnabled, 14, 1, false);}

CarADVISE::InjectTamperedBinarySuccessStep::~InjectTamperedBinarySuccessStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::InjectTamperedBinarySuccessStep::LinkVariables() {
  InternalRemoteAccess->Register(&InternalRemoteAccess_Mobius_Mark);
  RemoteNetworkAccess->Register(&RemoteNetworkAccess_Mobius_Mark);
  InjectionSkill->Register(&InjectionSkill_Mobius_Mark);
  MessageFormatKnowledge->Register(&MessageFormatKnowledge_Mobius_Mark);
  InjectTamperedBinaryChosen->Register(&InjectTamperedBinaryChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::InjectTamperedBinarySuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(InjectTamperedBinaryChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::InjectTamperedBinarySuccessStep::timeDistributionParameter0() {
return 7;
}

double CarADVISE::InjectTamperedBinarySuccessStep::Weight() {
return 0.8;
}

bool CarADVISE::InjectTamperedBinarySuccessStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::InjectTamperedBinarySuccessStep::ReactivationFunction() {
  return false;
}

double CarADVISE::InjectTamperedBinarySuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::InjectTamperedBinarySuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::InjectTamperedBinarySuccessStep::Rank() {
  return 1;
}

bool CarADVISE::InjectTamperedBinarySuccessStep::preconditionsMet() {
return InternalRemoteAccess->Mark() == 0 && MessageFormatKnowledge->Mark() && RemoteNetworkAccess->Mark() && InjectionSkill->Mark() >= injectionSkillThreshold;
  return true;
}

void CarADVISE::InjectTamperedBinarySuccessStep::executeEffects() {
InternalRemoteAccess->Mark() = true;
}

double CarADVISE::InjectTamperedBinarySuccessStep::getCost() {
return 7;
}

double CarADVISE::InjectTamperedBinarySuccessStep::getOutcomeProbability() {
return 0.8;
}

double CarADVISE::InjectTamperedBinarySuccessStep::getDetection() {
return 0.25;
}

/*====================== InjectMaliciousCANMessagesFailureStep ========================*/

CarADVISE::InjectMaliciousCANMessagesFailureStep::InjectMaliciousCANMessagesFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("InjectMaliciousCANMessagesFailureStep", 5, Deterministic, RaceEnabled, 13, 1, false);}

CarADVISE::InjectMaliciousCANMessagesFailureStep::~InjectMaliciousCANMessagesFailureStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::InjectMaliciousCANMessagesFailureStep::LinkVariables() {
  InternalCANAccess->Register(&InternalCANAccess_Mobius_Mark);
  SpoofingSkill->Register(&SpoofingSkill_Mobius_Mark);
  CompromisedGatewayAccess->Register(&CompromisedGatewayAccess_Mobius_Mark);
  InjectMaliciousCANMessagesChosen->Register(&InjectMaliciousCANMessagesChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::InjectMaliciousCANMessagesFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(InjectMaliciousCANMessagesChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::InjectMaliciousCANMessagesFailureStep::timeDistributionParameter0() {
return 2;
}

double CarADVISE::InjectMaliciousCANMessagesFailureStep::Weight() {
return 0.2;
}

bool CarADVISE::InjectMaliciousCANMessagesFailureStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::InjectMaliciousCANMessagesFailureStep::ReactivationFunction() {
  return false;
}

double CarADVISE::InjectMaliciousCANMessagesFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::InjectMaliciousCANMessagesFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::InjectMaliciousCANMessagesFailureStep::Rank() {
  return 1;
}

bool CarADVISE::InjectMaliciousCANMessagesFailureStep::preconditionsMet() {
return InternalCANAccess->Mark() == 0 && CompromisedGatewayAccess->Mark() &&SpoofingSkill->Mark() >= CANSpoofingSkillThreshold;
  return true;
}

void CarADVISE::InjectMaliciousCANMessagesFailureStep::executeEffects() {

}

double CarADVISE::InjectMaliciousCANMessagesFailureStep::getCost() {
return 1;
}

double CarADVISE::InjectMaliciousCANMessagesFailureStep::getOutcomeProbability() {
return 0.2;
}

double CarADVISE::InjectMaliciousCANMessagesFailureStep::getDetection() {
return 0.2;
}

/*====================== InjectMaliciousCANMessagesSuccessStep ========================*/

CarADVISE::InjectMaliciousCANMessagesSuccessStep::InjectMaliciousCANMessagesSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("InjectMaliciousCANMessagesSuccessStep", 5, Deterministic, RaceEnabled, 13, 1, false);}

CarADVISE::InjectMaliciousCANMessagesSuccessStep::~InjectMaliciousCANMessagesSuccessStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::InjectMaliciousCANMessagesSuccessStep::LinkVariables() {
  InternalCANAccess->Register(&InternalCANAccess_Mobius_Mark);
  SpoofingSkill->Register(&SpoofingSkill_Mobius_Mark);
  CompromisedGatewayAccess->Register(&CompromisedGatewayAccess_Mobius_Mark);
  InjectMaliciousCANMessagesChosen->Register(&InjectMaliciousCANMessagesChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::InjectMaliciousCANMessagesSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(InjectMaliciousCANMessagesChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::InjectMaliciousCANMessagesSuccessStep::timeDistributionParameter0() {
return 2;
}

double CarADVISE::InjectMaliciousCANMessagesSuccessStep::Weight() {
return 0.8;
}

bool CarADVISE::InjectMaliciousCANMessagesSuccessStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::InjectMaliciousCANMessagesSuccessStep::ReactivationFunction() {
  return false;
}

double CarADVISE::InjectMaliciousCANMessagesSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::InjectMaliciousCANMessagesSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::InjectMaliciousCANMessagesSuccessStep::Rank() {
  return 1;
}

bool CarADVISE::InjectMaliciousCANMessagesSuccessStep::preconditionsMet() {
return InternalCANAccess->Mark() == 0 && CompromisedGatewayAccess->Mark() &&SpoofingSkill->Mark() >= CANSpoofingSkillThreshold;
  return true;
}

void CarADVISE::InjectMaliciousCANMessagesSuccessStep::executeEffects() {
InternalCANAccess->Mark() = true;
}

double CarADVISE::InjectMaliciousCANMessagesSuccessStep::getCost() {
return 1;
}

double CarADVISE::InjectMaliciousCANMessagesSuccessStep::getOutcomeProbability() {
return 0.8;
}

double CarADVISE::InjectMaliciousCANMessagesSuccessStep::getDetection() {
return 0.2;
}

/*====================== ExtractDataRemotelyFailureStep ========================*/

CarADVISE::ExtractDataRemotelyFailureStep::ExtractDataRemotelyFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("ExtractDataRemotelyFailureStep", 6, Deterministic, RaceEnabled, 13, 1, false);}

CarADVISE::ExtractDataRemotelyFailureStep::~ExtractDataRemotelyFailureStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::ExtractDataRemotelyFailureStep::LinkVariables() {
  StealPrivateData->Register(&StealPrivateData_Mobius_Mark);
  DataExtractionSkill->Register(&DataExtractionSkill_Mobius_Mark);
  InternalRemoteAccess->Register(&InternalRemoteAccess_Mobius_Mark);
  ExtractDataRemotelyChosen->Register(&ExtractDataRemotelyChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::ExtractDataRemotelyFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExtractDataRemotelyChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ExtractDataRemotelyFailureStep::timeDistributionParameter0() {
return 3;
}

double CarADVISE::ExtractDataRemotelyFailureStep::Weight() {
return 0.25;
}

bool CarADVISE::ExtractDataRemotelyFailureStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ExtractDataRemotelyFailureStep::ReactivationFunction() {
  return false;
}

double CarADVISE::ExtractDataRemotelyFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::ExtractDataRemotelyFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::ExtractDataRemotelyFailureStep::Rank() {
  return 1;
}

bool CarADVISE::ExtractDataRemotelyFailureStep::preconditionsMet() {
return StealPrivateData->Mark() == 0 && InternalRemoteAccess->Mark() && DataExtractionSkill->Mark() >= remoteExtractionSkillThreshold;
  return true;
}

void CarADVISE::ExtractDataRemotelyFailureStep::executeEffects() {

}

double CarADVISE::ExtractDataRemotelyFailureStep::getCost() {
return 3;
}

double CarADVISE::ExtractDataRemotelyFailureStep::getOutcomeProbability() {
return 0.25;
}

double CarADVISE::ExtractDataRemotelyFailureStep::getDetection() {
return 0.55;
}

/*====================== ExtractDataRemotelySuccessStep ========================*/

CarADVISE::ExtractDataRemotelySuccessStep::ExtractDataRemotelySuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("ExtractDataRemotelySuccessStep", 6, Deterministic, RaceEnabled, 13, 1, false);}

CarADVISE::ExtractDataRemotelySuccessStep::~ExtractDataRemotelySuccessStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::ExtractDataRemotelySuccessStep::LinkVariables() {
  StealPrivateData->Register(&StealPrivateData_Mobius_Mark);
  DataExtractionSkill->Register(&DataExtractionSkill_Mobius_Mark);
  InternalRemoteAccess->Register(&InternalRemoteAccess_Mobius_Mark);
  ExtractDataRemotelyChosen->Register(&ExtractDataRemotelyChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::ExtractDataRemotelySuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ExtractDataRemotelyChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ExtractDataRemotelySuccessStep::timeDistributionParameter0() {
return 3;
}

double CarADVISE::ExtractDataRemotelySuccessStep::Weight() {
return 0.75;
}

bool CarADVISE::ExtractDataRemotelySuccessStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ExtractDataRemotelySuccessStep::ReactivationFunction() {
  return false;
}

double CarADVISE::ExtractDataRemotelySuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::ExtractDataRemotelySuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::ExtractDataRemotelySuccessStep::Rank() {
  return 1;
}

bool CarADVISE::ExtractDataRemotelySuccessStep::preconditionsMet() {
return StealPrivateData->Mark() == 0 && InternalRemoteAccess->Mark() && DataExtractionSkill->Mark() >= remoteExtractionSkillThreshold;
  return true;
}

void CarADVISE::ExtractDataRemotelySuccessStep::executeEffects() {
StealPrivateData->Mark() = true;
}

double CarADVISE::ExtractDataRemotelySuccessStep::getCost() {
return 3;
}

double CarADVISE::ExtractDataRemotelySuccessStep::getOutcomeProbability() {
return 0.75;
}

double CarADVISE::ExtractDataRemotelySuccessStep::getDetection() {
return 0.45;
}

/*====================== ImpersonateOEMFailureStep ========================*/

CarADVISE::ImpersonateOEMFailureStep::ImpersonateOEMFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("ImpersonateOEMFailureStep", 7, Deterministic, RaceEnabled, 14, 1, false);}

CarADVISE::ImpersonateOEMFailureStep::~ImpersonateOEMFailureStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::ImpersonateOEMFailureStep::LinkVariables() {
  InternalRemoteAccess->Register(&InternalRemoteAccess_Mobius_Mark);
  RemoteNetworkAccess->Register(&RemoteNetworkAccess_Mobius_Mark);
  CarModelKnowledge->Register(&CarModelKnowledge_Mobius_Mark);
  SpoofingSkill->Register(&SpoofingSkill_Mobius_Mark);
  ImpersonateOEMChosen->Register(&ImpersonateOEMChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::ImpersonateOEMFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ImpersonateOEMChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ImpersonateOEMFailureStep::timeDistributionParameter0() {
return 5;
}

double CarADVISE::ImpersonateOEMFailureStep::Weight() {
return 0.2;
}

bool CarADVISE::ImpersonateOEMFailureStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ImpersonateOEMFailureStep::ReactivationFunction() {
  return false;
}

double CarADVISE::ImpersonateOEMFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::ImpersonateOEMFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::ImpersonateOEMFailureStep::Rank() {
  return 1;
}

bool CarADVISE::ImpersonateOEMFailureStep::preconditionsMet() {
return InternalRemoteAccess->Mark() == 0 && CarModelKnowledge->Mark() && RemoteNetworkAccess->Mark() && SpoofingSkill->Mark() >= OEMSpoofingSkillThreshold;
  return true;
}

void CarADVISE::ImpersonateOEMFailureStep::executeEffects() {

}

double CarADVISE::ImpersonateOEMFailureStep::getCost() {
return 4;
}

double CarADVISE::ImpersonateOEMFailureStep::getOutcomeProbability() {
return 0.2;
}

double CarADVISE::ImpersonateOEMFailureStep::getDetection() {
return 0.6;
}

/*====================== ImpersonateOEMSuccessStep ========================*/

CarADVISE::ImpersonateOEMSuccessStep::ImpersonateOEMSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("ImpersonateOEMSuccessStep", 7, Deterministic, RaceEnabled, 14, 1, false);}

CarADVISE::ImpersonateOEMSuccessStep::~ImpersonateOEMSuccessStep() {
  delete[] TheDistributionParameters;
}

void CarADVISE::ImpersonateOEMSuccessStep::LinkVariables() {
  InternalRemoteAccess->Register(&InternalRemoteAccess_Mobius_Mark);
  RemoteNetworkAccess->Register(&RemoteNetworkAccess_Mobius_Mark);
  CarModelKnowledge->Register(&CarModelKnowledge_Mobius_Mark);
  SpoofingSkill->Register(&SpoofingSkill_Mobius_Mark);
  ImpersonateOEMChosen->Register(&ImpersonateOEMChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
  ImpersonateOEMWeight->Register(&ImpersonateOEMWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool CarADVISE::ImpersonateOEMSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ImpersonateOEMChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ImpersonateOEMSuccessStep::timeDistributionParameter0() {
return 5;
}

double CarADVISE::ImpersonateOEMSuccessStep::Weight() {
return 0.8;
}

bool CarADVISE::ImpersonateOEMSuccessStep::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ImpersonateOEMSuccessStep::ReactivationFunction() {
  return false;
}

double CarADVISE::ImpersonateOEMSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *CarADVISE::ImpersonateOEMSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int CarADVISE::ImpersonateOEMSuccessStep::Rank() {
  return 1;
}

bool CarADVISE::ImpersonateOEMSuccessStep::preconditionsMet() {
return InternalRemoteAccess->Mark() == 0 && CarModelKnowledge->Mark() && RemoteNetworkAccess->Mark() && SpoofingSkill->Mark() >= OEMSpoofingSkillThreshold;
  return true;
}

void CarADVISE::ImpersonateOEMSuccessStep::executeEffects() {
InternalRemoteAccess->Mark() = true;
}

double CarADVISE::ImpersonateOEMSuccessStep::getCost() {
return 4;
}

double CarADVISE::ImpersonateOEMSuccessStep::getOutcomeProbability() {
return 0.8;
}

double CarADVISE::ImpersonateOEMSuccessStep::getDetection() {
return 0.4;
}

/*****************************************************************/
/*                   Adversary Decisions                         */
/*****************************************************************/

/*====================== ReflashGatewayChipAdversaryDecision ========================*/

CarADVISE::ReflashGatewayChipAdversaryDecision::ReflashGatewayChipAdversaryDecision() {
  commonInit("ReflashGatewayChipAdversaryDecision", 8, Instantaneous, RaceEnabled, 2, 1, false);
}

CarADVISE::ReflashGatewayChipAdversaryDecision::~ReflashGatewayChipAdversaryDecision() {
}

void CarADVISE::ReflashGatewayChipAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  ReflashGatewayChipChosen->Register(&ReflashGatewayChipChosen_Mobius_Mark);
  ReflashGatewayChipWeight->Register(&ReflashGatewayChipWeight_Mobius_Mark);
}

bool CarADVISE::ReflashGatewayChipAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ReflashGatewayChipAdversaryDecision::Weight() {
  return ReflashGatewayChipWeight->Mark();
}

bool CarADVISE::ReflashGatewayChipAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ReflashGatewayChipAdversaryDecision::ReactivationFunction() {
  return false;
}

double CarADVISE::ReflashGatewayChipAdversaryDecision::SampleDistribution() {
  return 0;
}

double* CarADVISE::ReflashGatewayChipAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int CarADVISE::ReflashGatewayChipAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* CarADVISE::ReflashGatewayChipAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(ReflashGatewayChipWeight_Mobius_Mark))--;
  (*(ReflashGatewayChipChosen_Mobius_Mark))++;
  return this;
}

/*====================== DoNothingAdversaryDecision ========================*/

CarADVISE::DoNothingAdversaryDecision::DoNothingAdversaryDecision() {
  commonInit("DoNothingAdversaryDecision", 8, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== ExtractDataViaCANBusAdversaryDecision ========================*/

CarADVISE::ExtractDataViaCANBusAdversaryDecision::ExtractDataViaCANBusAdversaryDecision() {
  commonInit("ExtractDataViaCANBusAdversaryDecision", 8, Instantaneous, RaceEnabled, 2, 1, false);
}

CarADVISE::ExtractDataViaCANBusAdversaryDecision::~ExtractDataViaCANBusAdversaryDecision() {
}

void CarADVISE::ExtractDataViaCANBusAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  ExtractDataViaCANBusChosen->Register(&ExtractDataViaCANBusChosen_Mobius_Mark);
  ExtractDataViaCANBusWeight->Register(&ExtractDataViaCANBusWeight_Mobius_Mark);
}

bool CarADVISE::ExtractDataViaCANBusAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ExtractDataViaCANBusAdversaryDecision::Weight() {
  return ExtractDataViaCANBusWeight->Mark();
}

bool CarADVISE::ExtractDataViaCANBusAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ExtractDataViaCANBusAdversaryDecision::ReactivationFunction() {
  return false;
}

double CarADVISE::ExtractDataViaCANBusAdversaryDecision::SampleDistribution() {
  return 0;
}

double* CarADVISE::ExtractDataViaCANBusAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int CarADVISE::ExtractDataViaCANBusAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* CarADVISE::ExtractDataViaCANBusAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(ExtractDataViaCANBusWeight_Mobius_Mark))--;
  (*(ExtractDataViaCANBusChosen_Mobius_Mark))++;
  return this;
}

/*====================== SendV2XMaliciousMessagesAdversaryDecision ========================*/

CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::SendV2XMaliciousMessagesAdversaryDecision() {
  commonInit("SendV2XMaliciousMessagesAdversaryDecision", 8, Instantaneous, RaceEnabled, 2, 1, false);
}

CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::~SendV2XMaliciousMessagesAdversaryDecision() {
}

void CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  SendV2XMaliciousMessagesChosen->Register(&SendV2XMaliciousMessagesChosen_Mobius_Mark);
  SendV2XMaliciousMessagesWeight->Register(&SendV2XMaliciousMessagesWeight_Mobius_Mark);
}

bool CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::Weight() {
  return SendV2XMaliciousMessagesWeight->Mark();
}

bool CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::ReactivationFunction() {
  return false;
}

double CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::SampleDistribution() {
  return 0;
}

double* CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* CarADVISE::SendV2XMaliciousMessagesAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(SendV2XMaliciousMessagesWeight_Mobius_Mark))--;
  (*(SendV2XMaliciousMessagesChosen_Mobius_Mark))++;
  return this;
}

/*====================== InjectTamperedBinaryAdversaryDecision ========================*/

CarADVISE::InjectTamperedBinaryAdversaryDecision::InjectTamperedBinaryAdversaryDecision() {
  commonInit("InjectTamperedBinaryAdversaryDecision", 8, Instantaneous, RaceEnabled, 2, 1, false);
}

CarADVISE::InjectTamperedBinaryAdversaryDecision::~InjectTamperedBinaryAdversaryDecision() {
}

void CarADVISE::InjectTamperedBinaryAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  InjectTamperedBinaryChosen->Register(&InjectTamperedBinaryChosen_Mobius_Mark);
  InjectTamperedBinaryWeight->Register(&InjectTamperedBinaryWeight_Mobius_Mark);
}

bool CarADVISE::InjectTamperedBinaryAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::InjectTamperedBinaryAdversaryDecision::Weight() {
  return InjectTamperedBinaryWeight->Mark();
}

bool CarADVISE::InjectTamperedBinaryAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool CarADVISE::InjectTamperedBinaryAdversaryDecision::ReactivationFunction() {
  return false;
}

double CarADVISE::InjectTamperedBinaryAdversaryDecision::SampleDistribution() {
  return 0;
}

double* CarADVISE::InjectTamperedBinaryAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int CarADVISE::InjectTamperedBinaryAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* CarADVISE::InjectTamperedBinaryAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(InjectTamperedBinaryWeight_Mobius_Mark))--;
  (*(InjectTamperedBinaryChosen_Mobius_Mark))++;
  return this;
}

/*====================== InjectMaliciousCANMessagesAdversaryDecision ========================*/

CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::InjectMaliciousCANMessagesAdversaryDecision() {
  commonInit("InjectMaliciousCANMessagesAdversaryDecision", 8, Instantaneous, RaceEnabled, 2, 1, false);
}

CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::~InjectMaliciousCANMessagesAdversaryDecision() {
}

void CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  InjectMaliciousCANMessagesChosen->Register(&InjectMaliciousCANMessagesChosen_Mobius_Mark);
  InjectMaliciousCANMessagesWeight->Register(&InjectMaliciousCANMessagesWeight_Mobius_Mark);
}

bool CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::Weight() {
  return InjectMaliciousCANMessagesWeight->Mark();
}

bool CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::ReactivationFunction() {
  return false;
}

double CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::SampleDistribution() {
  return 0;
}

double* CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* CarADVISE::InjectMaliciousCANMessagesAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(InjectMaliciousCANMessagesWeight_Mobius_Mark))--;
  (*(InjectMaliciousCANMessagesChosen_Mobius_Mark))++;
  return this;
}

/*====================== ExtractDataRemotelyAdversaryDecision ========================*/

CarADVISE::ExtractDataRemotelyAdversaryDecision::ExtractDataRemotelyAdversaryDecision() {
  commonInit("ExtractDataRemotelyAdversaryDecision", 8, Instantaneous, RaceEnabled, 2, 1, false);
}

CarADVISE::ExtractDataRemotelyAdversaryDecision::~ExtractDataRemotelyAdversaryDecision() {
}

void CarADVISE::ExtractDataRemotelyAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  ExtractDataRemotelyChosen->Register(&ExtractDataRemotelyChosen_Mobius_Mark);
  ExtractDataRemotelyWeight->Register(&ExtractDataRemotelyWeight_Mobius_Mark);
}

bool CarADVISE::ExtractDataRemotelyAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double CarADVISE::ExtractDataRemotelyAdversaryDecision::Weight() {
  return ExtractDataRemotelyWeight->Mark();
}

bool CarADVISE::ExtractDataRemotelyAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool CarADVISE::ExtractDataRemotelyAdversaryDecision::ReactivationFunction() {
  return false;
}

double CarADVISE::ExtractDataRemotelyAdversaryDecision::SampleDistribution() {
  return 0;
}

double* CarADVISE::ExtractDataRemotelyAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int CarADVISE::ExtractDataRemotelyAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* CarADVISE::ExtractDataRemotelyAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(ExtractDataRemotelyWeight_Mobius_Mark))--;
  (*(ExtractDataRemotelyChosen_Mobius_Mark))++;
  return this;
}

/*====================== ImpersonateOEMAdversaryDecision ========================*/

CarADVISE::ImpersonateOEMAdversaryDecision::ImpersonateOEMAdversaryDecision() {
  commonInit("ImpersonateOEMAdversaryDecision", 8, Instantaneous, RaceEnabled, 2, 1, false);
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

