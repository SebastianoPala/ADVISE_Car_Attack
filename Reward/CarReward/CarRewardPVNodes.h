#ifndef _CARREWARD_PVS_
#define _CARREWARD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/Car/CarADVISE.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"


class CarRewardPV0Worker:public InstantOfTime
{
 public:
  CarADVISE *Car;
  
  CarRewardPV0Worker();
  ~CarRewardPV0Worker();
  double Reward_Function();
};

class CarRewardPV0:public PerformanceVariableNode
{
 public:
  CarADVISE *TheCarADVISE;

  CarRewardPV0Worker *CarRewardPV0WorkerList;

  CarRewardPV0(int timeindex=0);
  ~CarRewardPV0();
  void CreateWorkerList(void);
};

#endif
