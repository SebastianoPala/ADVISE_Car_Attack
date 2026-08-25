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
extern UserDistributions* TheDistribution;

/*********************************************************************
               CarADVISE Submodel Definition                   
*********************************************************************/

class CarADVISE : public ADVISEModel {
public:

class SendMaliciousPacketAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *SendMaliciousPacketChosen;
  short *SendMaliciousPacketChosen_Mobius_Mark;
  StepWeight *SendMaliciousPacketWeight;
  short *SendMaliciousPacketWeight_Mobius_Mark;
  double *TheDistributionParameters;

  SendMaliciousPacketAdversaryDecision();
  ~SendMaliciousPacketAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // SendMaliciousPacketAdversaryDecision

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

class SendMaliciousPacketOutcome1Step : public Step {
public:

  Access *CarWirelessNetworkAccess;
  short* CarWirelessNetworkAccess_Mobius_Mark;
  Knowledge *MessageFormatKnowledge;
  short* MessageFormatKnowledge_Mobius_Mark;
  StepChosen *SendMaliciousPacketChosen;
  short *SendMaliciousPacketChosen_Mobius_Mark;
  StepWeight *SendMaliciousPacketWeight;
  short *SendMaliciousPacketWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  SendMaliciousPacketOutcome1Step();
  ~SendMaliciousPacketOutcome1Step();
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
}; // SendMaliciousPacketOutcome1Step

class DoNothingOutcome1Step : public Step {
public:

  StepChosen *DoNothingChosen;
  short *DoNothingChosen_Mobius_Mark;
  StepWeight *SendMaliciousPacketWeight;
  short *SendMaliciousPacketWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  DoNothingOutcome1Step();
  ~DoNothingOutcome1Step();
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
}; // DoNothingOutcome1Step

class ImpersonateOEMOutcome1Step : public Step {
public:

  Goal *StealPrivateData;
  short* StealPrivateData_Mobius_Mark;
  Knowledge *CarModelKnowledge;
  short* CarModelKnowledge_Mobius_Mark;
  Access *CarWirelessNetworkAccess;
  short* CarWirelessNetworkAccess_Mobius_Mark;
  Skill *SpoofingSkill;
  short* SpoofingSkill_Mobius_Mark;
  StepChosen *ImpersonateOEMChosen;
  short *ImpersonateOEMChosen_Mobius_Mark;
  StepWeight *SendMaliciousPacketWeight;
  short *SendMaliciousPacketWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  StepWeight *ImpersonateOEMWeight;
  short *ImpersonateOEMWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ImpersonateOEMOutcome1Step();
  ~ImpersonateOEMOutcome1Step();
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
}; // ImpersonateOEMOutcome1Step

  //List of user-specified state variables
  Access *CarWirelessNetworkAccess;
  Knowledge *MessageFormatKnowledge;
  Knowledge *CarModelKnowledge;
  Skill *InjectionSkill;
  Skill *SpoofingSkill;
  Goal *StealPrivateData;
  //List of attack step weight state variables
  StepWeight *SendMaliciousPacketWeight;
  StepWeight *DoNothingWeight;
  StepWeight *ImpersonateOEMWeight;
  //List of attack step chosen state variables
  StepChosen *SendMaliciousPacketChosen;
  StepChosen *DoNothingChosen;
  StepChosen *ImpersonateOEMChosen;
  //List of attack steps
  SendMaliciousPacketOutcome1Step SendMaliciousPacketOutcome1;
  DoNothingOutcome1Step DoNothingOutcome1;
  ImpersonateOEMOutcome1Step ImpersonateOEMOutcome1;
  SendMaliciousPacketAdversaryDecision SendMaliciousPacketAD;
  DoNothingAdversaryDecision DoNothingAD;
  ImpersonateOEMAdversaryDecision ImpersonateOEMAD;
  //Groups for attack steps
  PreselectGroup ImmediateGroup;
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
