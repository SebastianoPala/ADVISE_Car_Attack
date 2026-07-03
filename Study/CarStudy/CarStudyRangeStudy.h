
#ifndef CarStudyRangeSTUDY_H_
#define CarStudyRangeSTUDY_H_

#include "Reward/CarReward/CarRewardPVNodes.h"
#include "Reward/CarReward/CarRewardPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Short CANExtractionCost;
extern Short CANExtractionSkillThreshold;
extern Short CANExtractionTime;
extern Short CANSpoofingSkillThreshold;
extern Short OEMSpoofingSkillThreshold;
extern Short chipFlashingSkillLevel;
extern Short chipFlashingSkillThreshold;
extern Short dataExtractionSkillLevel;
extern Bool hasCarModelKnowledge;
extern Bool hasMessageFormatKnowledge;
extern Bool hasProximityAccess;
extern Bool hasRemoteNetworkAccess;
extern Bool hasV2XProtocolKnowledge;
extern Short injectionSkillLevel;
extern Short injectionSkillThreshold;
extern Short maliciousCANMessagesCost;
extern Short maliciousCANMessagesTime;
extern Short maliciousV2XMessagesCost;
extern Short maliciousV2XMessagesTime;
extern Short remoteExtractionSkillThreshold;
extern Short spoofingSkillLevel;
extern Short v2XPacketCraftingSkillLevel;
extern Short v2XPacketCraftingSkillThreshold;

class CarStudyRangeStudy : public BaseStudyClass {
public:

CarStudyRangeStudy();
~CarStudyRangeStudy();

private:

short *CANExtractionCostValues;
short *CANExtractionSkillThresholdValues;
short *CANExtractionTimeValues;
short *CANSpoofingSkillThresholdValues;
short *OEMSpoofingSkillThresholdValues;
short *chipFlashingSkillLevelValues;
short *chipFlashingSkillThresholdValues;
short *dataExtractionSkillLevelValues;
bool *hasCarModelKnowledgeValues;
bool *hasMessageFormatKnowledgeValues;
bool *hasProximityAccessValues;
bool *hasRemoteNetworkAccessValues;
bool *hasV2XProtocolKnowledgeValues;
short *injectionSkillLevelValues;
short *injectionSkillThresholdValues;
short *maliciousCANMessagesCostValues;
short *maliciousCANMessagesTimeValues;
short *maliciousV2XMessagesCostValues;
short *maliciousV2XMessagesTimeValues;
short *remoteExtractionSkillThresholdValues;
short *spoofingSkillLevelValues;
short *v2XPacketCraftingSkillLevelValues;
short *v2XPacketCraftingSkillThresholdValues;

void SetValues_CANExtractionCost();
void SetValues_CANExtractionSkillThreshold();
void SetValues_CANExtractionTime();
void SetValues_CANSpoofingSkillThreshold();
void SetValues_OEMSpoofingSkillThreshold();
void SetValues_chipFlashingSkillLevel();
void SetValues_chipFlashingSkillThreshold();
void SetValues_dataExtractionSkillLevel();
void SetValues_hasCarModelKnowledge();
void SetValues_hasMessageFormatKnowledge();
void SetValues_hasProximityAccess();
void SetValues_hasRemoteNetworkAccess();
void SetValues_hasV2XProtocolKnowledge();
void SetValues_injectionSkillLevel();
void SetValues_injectionSkillThreshold();
void SetValues_maliciousCANMessagesCost();
void SetValues_maliciousCANMessagesTime();
void SetValues_maliciousV2XMessagesCost();
void SetValues_maliciousV2XMessagesTime();
void SetValues_remoteExtractionSkillThreshold();
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

