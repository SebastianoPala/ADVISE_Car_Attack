#ifndef _CARREWARD_PVMODEL_
#define _CARREWARD_PVMODEL_
#include "CarRewardPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Car/CarADVISE.h"
class CarRewardPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  CarRewardPVModel(bool expandtimepoints);
};

#endif
