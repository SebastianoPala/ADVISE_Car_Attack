#ifndef CarADVISE_H_
#define CarADVISE_H_

#include "Cpp/Simulator/UserDistributions.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/atomic/advise/ADVISEModel.h"
#include "Cpp/BaseClasses/atomic/advise/Access.h"
#include "Cpp/BaseClasses/atomic/advise/AdversaryDecision.h"
#include "Cpp/BaseClasses/atomic/advise/BeginAdversaryDecision.h"
#include "Cpp/BaseClasses/atomic/advise/Goal.h"
#include "Cpp/BaseClasses/atomic/advise/Knowledge.h"
#include "Cpp/BaseClasses/atomic/advise/Skill.h"
#include "Cpp/BaseClasses/atomic/advise/Step.h"
#include "Cpp/BaseClasses/atomic/advise/StepChosen.h"
#include "Cpp/BaseClasses/atomic/advise/StepWeight.h"
#include <limits.h>
#include <cmath>
extern Bool hasProximityNetworkAccess;
extern Bool hasRemoteNetworkAccess;
extern Bool hasMessageFormatKnowledge;
extern Bool hasCarModelKnowledge;
extern Bool hasV2XProtocolKnowledge;
extern Short spoofingSkillLevel;
extern Short chipFlashingSkillLevel;
extern Short injectionSkillLevel;
extern Short v2XPacketCraftingSkillLevel;
extern Short dataExtractionSkillLevel;
extern Short v2XPacketCraftingSkillThreshold;
extern Short injectionSkillThreshold;
extern Short chipFlashingSkillThreshold;
extern Short remoteDataExtractionThreshold;
extern Short CANSpoofingSkillThreshold;
extern Short OEMSpoofingSkillThreshold;
extern Short maliciousV2XCost;
extern Short maliciousCANCost;
extern Short remoteExtractionCost;
extern Short reflashChipCost;
extern Short OEMImpersonationCost;
extern Short binaryInjectionCost;
extern Short CANExtractionCost;
extern Short CANDataExtractionSkillThreshold;
extern UserDistributions* TheDistribution;

/*********************************************************************
               CarADVISE Submodel Definition                   
*********************************************************************/

class CarADVISE : public ADVISEModel {
public:

class ReflashGatewayChipAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *ReflashGatewayChipChosen;
  short *ReflashGatewayChipChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  double *TheDistributionParameters;

  ReflashGatewayChipAdversaryDecision();
  ~ReflashGatewayChipAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // ReflashGatewayChipAdversaryDecision

class DoNothingAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *DoNothingChosen;
  short *DoNothingChosen_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  double *TheDistributionParameters;

  DoNothingAdversaryDecision();
  ~DoNothingAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // DoNothingAdversaryDecision

class ExtractDataViaCANBusAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *ExtractDataViaCANBusChosen;
  short *ExtractDataViaCANBusChosen_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  double *TheDistributionParameters;

  ExtractDataViaCANBusAdversaryDecision();
  ~ExtractDataViaCANBusAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // ExtractDataViaCANBusAdversaryDecision

class SendV2XMaliciousMessagesAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *SendV2XMaliciousMessagesChosen;
  short *SendV2XMaliciousMessagesChosen_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  double *TheDistributionParameters;

  SendV2XMaliciousMessagesAdversaryDecision();
  ~SendV2XMaliciousMessagesAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // SendV2XMaliciousMessagesAdversaryDecision

class InjectTamperedBinaryAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *InjectTamperedBinaryChosen;
  short *InjectTamperedBinaryChosen_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  double *TheDistributionParameters;

  InjectTamperedBinaryAdversaryDecision();
  ~InjectTamperedBinaryAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // InjectTamperedBinaryAdversaryDecision

class InjectMaliciousCANMessagesAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *InjectMaliciousCANMessagesChosen;
  short *InjectMaliciousCANMessagesChosen_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  double *TheDistributionParameters;

  InjectMaliciousCANMessagesAdversaryDecision();
  ~InjectMaliciousCANMessagesAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // InjectMaliciousCANMessagesAdversaryDecision

class ExtractDataRemotelyAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *ExtractDataRemotelyChosen;
  short *ExtractDataRemotelyChosen_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  double *TheDistributionParameters;

  ExtractDataRemotelyAdversaryDecision();
  ~ExtractDataRemotelyAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // ExtractDataRemotelyAdversaryDecision

class ImpersonateOEMAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *ImpersonateOEMChosen;
  short *ImpersonateOEMChosen_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  double *TheDistributionParameters;

  ImpersonateOEMAdversaryDecision();
  ~ImpersonateOEMAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // ImpersonateOEMAdversaryDecision

class ReflashGatewayChipFailureStep : public Step {
public:

  Access *CompromisedGatewayAccess;
  short* CompromisedGatewayAccess_Mobius_Mark;
  Knowledge *CarModelKnowledge;
  short* CarModelKnowledge_Mobius_Mark;
  Skill *ChipFlashingSkill;
  short* ChipFlashingSkill_Mobius_Mark;
  Access *InternalRemoteAccess;
  short* InternalRemoteAccess_Mobius_Mark;
  StepChosen *ReflashGatewayChipChosen;
  short *ReflashGatewayChipChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ReflashGatewayChipFailureStep();
  ~ReflashGatewayChipFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ReflashGatewayChipFailureStep

class ReflashGatewayChipSuccessStep : public Step {
public:

  Access *CompromisedGatewayAccess;
  short* CompromisedGatewayAccess_Mobius_Mark;
  Knowledge *CarModelKnowledge;
  short* CarModelKnowledge_Mobius_Mark;
  Skill *ChipFlashingSkill;
  short* ChipFlashingSkill_Mobius_Mark;
  Access *InternalRemoteAccess;
  short* InternalRemoteAccess_Mobius_Mark;
  StepChosen *ReflashGatewayChipChosen;
  short *ReflashGatewayChipChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ReflashGatewayChipSuccessStep();
  ~ReflashGatewayChipSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ReflashGatewayChipSuccessStep

class DoNothingNothingStep : public Step {
public:

  StepChosen *DoNothingChosen;
  short *DoNothingChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  DoNothingNothingStep();
  ~DoNothingNothingStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // DoNothingNothingStep

class ExtractDataViaCANBusSuccessStep : public Step {
public:

  Goal *StealPrivateData;
  short* StealPrivateData_Mobius_Mark;
  Access *InternalCANAccess;
  short* InternalCANAccess_Mobius_Mark;
  Skill *DataExtractionSkill;
  short* DataExtractionSkill_Mobius_Mark;
  StepChosen *ExtractDataViaCANBusChosen;
  short *ExtractDataViaCANBusChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ExtractDataViaCANBusSuccessStep();
  ~ExtractDataViaCANBusSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ExtractDataViaCANBusSuccessStep

class ExtractDataViaCANBusFailureStep : public Step {
public:

  Goal *StealPrivateData;
  short* StealPrivateData_Mobius_Mark;
  Access *InternalCANAccess;
  short* InternalCANAccess_Mobius_Mark;
  Skill *DataExtractionSkill;
  short* DataExtractionSkill_Mobius_Mark;
  StepChosen *ExtractDataViaCANBusChosen;
  short *ExtractDataViaCANBusChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ExtractDataViaCANBusFailureStep();
  ~ExtractDataViaCANBusFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ExtractDataViaCANBusFailureStep

class SendV2XMaliciousMessagesSuccessStep : public Step {
public:

  Access *CompromisedGatewayAccess;
  short* CompromisedGatewayAccess_Mobius_Mark;
  Skill *V2XPacketCraftingSkill;
  short* V2XPacketCraftingSkill_Mobius_Mark;
  Access *ProximityNetworkAccess;
  short* ProximityNetworkAccess_Mobius_Mark;
  Knowledge *V2XProtocolKnowledge;
  short* V2XProtocolKnowledge_Mobius_Mark;
  StepChosen *SendV2XMaliciousMessagesChosen;
  short *SendV2XMaliciousMessagesChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  SendV2XMaliciousMessagesSuccessStep();
  ~SendV2XMaliciousMessagesSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // SendV2XMaliciousMessagesSuccessStep

class SendV2XMaliciousMessagesFailureStep : public Step {
public:

  Access *CompromisedGatewayAccess;
  short* CompromisedGatewayAccess_Mobius_Mark;
  Skill *V2XPacketCraftingSkill;
  short* V2XPacketCraftingSkill_Mobius_Mark;
  Access *ProximityNetworkAccess;
  short* ProximityNetworkAccess_Mobius_Mark;
  Knowledge *V2XProtocolKnowledge;
  short* V2XProtocolKnowledge_Mobius_Mark;
  StepChosen *SendV2XMaliciousMessagesChosen;
  short *SendV2XMaliciousMessagesChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  SendV2XMaliciousMessagesFailureStep();
  ~SendV2XMaliciousMessagesFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // SendV2XMaliciousMessagesFailureStep

class InjectTamperedBinarySuccessStep : public Step {
public:

  Access *InternalRemoteAccess;
  short* InternalRemoteAccess_Mobius_Mark;
  Access *RemoteNetworkAccess;
  short* RemoteNetworkAccess_Mobius_Mark;
  Skill *InjectionSkill;
  short* InjectionSkill_Mobius_Mark;
  Knowledge *MessageFormatKnowledge;
  short* MessageFormatKnowledge_Mobius_Mark;
  StepChosen *InjectTamperedBinaryChosen;
  short *InjectTamperedBinaryChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  InjectTamperedBinarySuccessStep();
  ~InjectTamperedBinarySuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // InjectTamperedBinarySuccessStep

class InjectTamperedBinaryFailureStep : public Step {
public:

  Access *InternalRemoteAccess;
  short* InternalRemoteAccess_Mobius_Mark;
  Access *RemoteNetworkAccess;
  short* RemoteNetworkAccess_Mobius_Mark;
  Skill *InjectionSkill;
  short* InjectionSkill_Mobius_Mark;
  Knowledge *MessageFormatKnowledge;
  short* MessageFormatKnowledge_Mobius_Mark;
  StepChosen *InjectTamperedBinaryChosen;
  short *InjectTamperedBinaryChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  InjectTamperedBinaryFailureStep();
  ~InjectTamperedBinaryFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // InjectTamperedBinaryFailureStep

class InjectMaliciousCANMessagesSuccessStep : public Step {
public:

  Access *InternalCANAccess;
  short* InternalCANAccess_Mobius_Mark;
  Skill *SpoofingSkill;
  short* SpoofingSkill_Mobius_Mark;
  Access *CompromisedGatewayAccess;
  short* CompromisedGatewayAccess_Mobius_Mark;
  StepChosen *InjectMaliciousCANMessagesChosen;
  short *InjectMaliciousCANMessagesChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  InjectMaliciousCANMessagesSuccessStep();
  ~InjectMaliciousCANMessagesSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // InjectMaliciousCANMessagesSuccessStep

class InjectMaliciousCANMessagesFailureStep : public Step {
public:

  Access *InternalCANAccess;
  short* InternalCANAccess_Mobius_Mark;
  Skill *SpoofingSkill;
  short* SpoofingSkill_Mobius_Mark;
  Access *CompromisedGatewayAccess;
  short* CompromisedGatewayAccess_Mobius_Mark;
  StepChosen *InjectMaliciousCANMessagesChosen;
  short *InjectMaliciousCANMessagesChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  InjectMaliciousCANMessagesFailureStep();
  ~InjectMaliciousCANMessagesFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // InjectMaliciousCANMessagesFailureStep

class ExtractDataRemotelySuccessStep : public Step {
public:

  Goal *StealPrivateData;
  short* StealPrivateData_Mobius_Mark;
  Skill *DataExtractionSkill;
  short* DataExtractionSkill_Mobius_Mark;
  Access *InternalRemoteAccess;
  short* InternalRemoteAccess_Mobius_Mark;
  StepChosen *ExtractDataRemotelyChosen;
  short *ExtractDataRemotelyChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ExtractDataRemotelySuccessStep();
  ~ExtractDataRemotelySuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ExtractDataRemotelySuccessStep

class ExtractDataRemotelyFailureStep : public Step {
public:

  Goal *StealPrivateData;
  short* StealPrivateData_Mobius_Mark;
  Skill *DataExtractionSkill;
  short* DataExtractionSkill_Mobius_Mark;
  Access *InternalRemoteAccess;
  short* InternalRemoteAccess_Mobius_Mark;
  StepChosen *ExtractDataRemotelyChosen;
  short *ExtractDataRemotelyChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ExtractDataRemotelyFailureStep();
  ~ExtractDataRemotelyFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ExtractDataRemotelyFailureStep

class ImpersonateOEMSuccessStep : public Step {
public:

  Access *InternalRemoteAccess;
  short* InternalRemoteAccess_Mobius_Mark;
  Knowledge *CarModelKnowledge;
  short* CarModelKnowledge_Mobius_Mark;
  Skill *SpoofingSkill;
  short* SpoofingSkill_Mobius_Mark;
  Access *RemoteNetworkAccess;
  short* RemoteNetworkAccess_Mobius_Mark;
  StepChosen *ImpersonateOEMChosen;
  short *ImpersonateOEMChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ImpersonateOEMSuccessStep();
  ~ImpersonateOEMSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ImpersonateOEMSuccessStep

class ImpersonateOEMFailureStep : public Step {
public:

  Access *InternalRemoteAccess;
  short* InternalRemoteAccess_Mobius_Mark;
  Knowledge *CarModelKnowledge;
  short* CarModelKnowledge_Mobius_Mark;
  Skill *SpoofingSkill;
  short* SpoofingSkill_Mobius_Mark;
  Access *RemoteNetworkAccess;
  short* RemoteNetworkAccess_Mobius_Mark;
  StepChosen *ImpersonateOEMChosen;
  short *ImpersonateOEMChosen_Mobius_Mark;
  StepWeight *ReflashGatewayChipWeight;
  short *ReflashGatewayChipWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ExtractDataViaCANBusWeight;
  short *ExtractDataViaCANBusWeight_Mobius_Mark;
  StepWeight *SendV2XMaliciousMessagesWeight;
  short *SendV2XMaliciousMessagesWeight_Mobius_Mark;
  StepWeight *InjectTamperedBinaryWeight;
  short *InjectTamperedBinaryWeight_Mobius_Mark;
  StepWeight *InjectMaliciousCANMessagesWeight;
  short *InjectMaliciousCANMessagesWeight_Mobius_Mark;
  StepWeight *ExtractDataRemotelyWeight;
  short *ExtractDataRemotelyWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ImpersonateOEMFailureStep();
  ~ImpersonateOEMFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ImpersonateOEMFailureStep

  //List of user-specified state variables
  Access *InternalRemoteAccess;
  Access *ProximityNetworkAccess;
  Access *RemoteNetworkAccess;
  Access *CompromisedGatewayAccess;
  Access *InternalCANAccess;
  Knowledge *MessageFormatKnowledge;
  Knowledge *V2XProtocolKnowledge;
  Knowledge *CarModelKnowledge;
  Skill *SpoofingSkill;
  Skill *V2XPacketCraftingSkill;
  Skill *InjectionSkill;
  Skill *DataExtractionSkill;
  Skill *ChipFlashingSkill;
  Goal *StealPrivateData;
  //List of attack step weight state variables
  StepWeight *ReflashGatewayChipWeight;
  StepWeight *DoNothingWeight;
  StepWeight *ExtractDataViaCANBusWeight;
  StepWeight *SendV2XMaliciousMessagesWeight;
  StepWeight *InjectTamperedBinaryWeight;
  StepWeight *InjectMaliciousCANMessagesWeight;
  StepWeight *ExtractDataRemotelyWeight;
  StepWeight *ImpersonateOEMWeight;
  //List of attack step chosen state variables
  StepChosen *ReflashGatewayChipChosen;
  StepChosen *DoNothingChosen;
  StepChosen *ExtractDataViaCANBusChosen;
  StepChosen *SendV2XMaliciousMessagesChosen;
  StepChosen *InjectTamperedBinaryChosen;
  StepChosen *InjectMaliciousCANMessagesChosen;
  StepChosen *ExtractDataRemotelyChosen;
  StepChosen *ImpersonateOEMChosen;
  //List of attack steps
  ReflashGatewayChipFailureStep ReflashGatewayChipFailure;
  ReflashGatewayChipSuccessStep ReflashGatewayChipSuccess;
  DoNothingNothingStep DoNothingNothing;
  ExtractDataViaCANBusSuccessStep ExtractDataViaCANBusSuccess;
  ExtractDataViaCANBusFailureStep ExtractDataViaCANBusFailure;
  SendV2XMaliciousMessagesSuccessStep SendV2XMaliciousMessagesSuccess;
  SendV2XMaliciousMessagesFailureStep SendV2XMaliciousMessagesFailure;
  InjectTamperedBinarySuccessStep InjectTamperedBinarySuccess;
  InjectTamperedBinaryFailureStep InjectTamperedBinaryFailure;
  InjectMaliciousCANMessagesSuccessStep InjectMaliciousCANMessagesSuccess;
  InjectMaliciousCANMessagesFailureStep InjectMaliciousCANMessagesFailure;
  ExtractDataRemotelySuccessStep ExtractDataRemotelySuccess;
  ExtractDataRemotelyFailureStep ExtractDataRemotelyFailure;
  ImpersonateOEMSuccessStep ImpersonateOEMSuccess;
  ImpersonateOEMFailureStep ImpersonateOEMFailure;
  ReflashGatewayChipAdversaryDecision ReflashGatewayChipAD;
  DoNothingAdversaryDecision DoNothingAD;
  ExtractDataViaCANBusAdversaryDecision ExtractDataViaCANBusAD;
  SendV2XMaliciousMessagesAdversaryDecision SendV2XMaliciousMessagesAD;
  InjectTamperedBinaryAdversaryDecision InjectTamperedBinaryAD;
  InjectMaliciousCANMessagesAdversaryDecision InjectMaliciousCANMessagesAD;
  ExtractDataRemotelyAdversaryDecision ExtractDataRemotelyAD;
  ImpersonateOEMAdversaryDecision ImpersonateOEMAD;
  //Groups for attack steps
  PreselectGroup ImmediateGroup;
  PostselectGroup ReflashGatewayChipGroup;
  PostselectGroup ExtractDataViaCANBusGroup;
  PostselectGroup SendV2XMaliciousMessagesGroup;
  PostselectGroup InjectTamperedBinaryGroup;
  PostselectGroup InjectMaliciousCANMessagesGroup;
  PostselectGroup ExtractDataRemotelyGroup;
  PostselectGroup ImpersonateOEMGroup;
  PostselectGroup AdversaryDecisionGroup;
  CarADVISE();
  ~CarADVISE();
  void assignSVsToAttackSteps();
  double convertCostToUtility(double cost);
  double convertDetectionToUtility(double detections);
  double convertPayoffToUtility(double payoff);
  void customInitialization();

protected:
}; // end CarADVISE

#endif // CarADVISE_H_
