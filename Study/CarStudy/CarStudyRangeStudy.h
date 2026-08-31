
#ifndef CarStudyRangeSTUDY_H_
#define CarStudyRangeSTUDY_H_

#include "Reward/CarReward/CarRewardPVNodes.h"
#include "Reward/CarReward/CarRewardPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Short CANDataExtractionSkillThreshold;
extern Short CANExtractionCost;
extern Short CANSpoofingSkillThreshold;
extern Short OEMImpersonationCost;
extern Short OEMSpoofingSkillThreshold;
extern Short binaryInjectionCost;
extern Short chipFlashingSkillLevel;
extern Short chipFlashingSkillThreshold;
extern Short dataExtractionSkillLevel;
extern Bool hasCarModelKnowledge;
extern Bool hasMessageFormatKnowledge;
extern Bool hasProximityNetworkAccess;
extern Bool hasRemoteNetworkAccess;
extern Bool hasV2XProtocolKnowledge;
extern Short injectionSkillLevel;
extern Short injectionSkillThreshold;
extern Short maliciousCANCost;
extern Short maliciousV2XCost;
extern Short reflashChipCost;
extern Short remoteDataExtractionThreshold;
extern Short remoteExtractionCost;
extern Short spoofingSkillLevel;
extern Short v2XPacketCraftingSkillLevel;
extern Short v2XPacketCraftingSkillThreshold;

class CarStudyRangeStudy : public BaseStudyClass {
public:

CarStudyRangeStudy();
~CarStudyRangeStudy();

private:

short *CANDataExtractionSkillThresholdValues;
short *CANExtractionCostValues;
short *CANSpoofingSkillThresholdValues;
short *OEMImpersonationCostValues;
short *OEMSpoofingSkillThresholdValues;
short *binaryInjectionCostValues;
short *chipFlashingSkillLevelValues;
short *chipFlashingSkillThresholdValues;
short *dataExtractionSkillLevelValues;
bool *hasCarModelKnowledgeValues;
bool *hasMessageFormatKnowledgeValues;
bool *hasProximityNetworkAccessValues;
bool *hasRemoteNetworkAccessValues;
bool *hasV2XProtocolKnowledgeValues;
short *injectionSkillLevelValues;
short *injectionSkillThresholdValues;
short *maliciousCANCostValues;
short *maliciousV2XCostValues;
short *reflashChipCostValues;
short *remoteDataExtractionThresholdValues;
short *remoteExtractionCostValues;
short *spoofingSkillLevelValues;
short *v2XPacketCraftingSkillLevelValues;
short *v2XPacketCraftingSkillThresholdValues;

void SetValues_CANDataExtractionSkillThreshold();
void SetValues_CANExtractionCost();
void SetValues_CANSpoofingSkillThreshold();
void SetValues_OEMImpersonationCost();
void SetValues_OEMSpoofingSkillThreshold();
void SetValues_binaryInjectionCost();
void SetValues_chipFlashingSkillLevel();
void SetValues_chipFlashingSkillThreshold();
void SetValues_dataExtractionSkillLevel();
void SetValues_hasCarModelKnowledge();
void SetValues_hasMessageFormatKnowledge();
void SetValues_hasProximityNetworkAccess();
void SetValues_hasRemoteNetworkAccess();
void SetValues_hasV2XProtocolKnowledge();
void SetValues_injectionSkillLevel();
void SetValues_injectionSkillThreshold();
void SetValues_maliciousCANCost();
void SetValues_maliciousV2XCost();
void SetValues_reflashChipCost();
void SetValues_remoteDataExtractionThreshold();
void SetValues_remoteExtractionCost();
void SetValues_spoofingSkillLevel();
void SetValues_v2XPacketCraftingSkillLevel();
void SetValues_v2XPacketCraftingSkillThreshold();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

