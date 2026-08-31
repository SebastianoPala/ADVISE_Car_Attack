#include "CarRewardPVModel.h"

CarRewardPVModel::CarRewardPVModel(bool expandTimeArrays) {
  TheModel=new CarADVISE();
  DefineName("CarRewardPVModel");
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* CarRewardPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new CarRewardPV0(timeindex);
    break;
  }
  return NULL;
}
