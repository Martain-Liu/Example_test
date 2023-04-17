#include "FSM_State_Locomotion.h"
using namespace std;
FSM_State_Locomotion::FSM_State_Locomotion(ControlFSMData* _controlFSMData)
    : FSM_State(_controlFSMData)
{
    std::cout << "Entry IN  FSM_State_Locomotion" << std::endl;
  std::cout << "FSM_State_Locomotion-a:=="<<_data->a << std::endl;
  std::cout << "FSM_State_Locomotion-b:=="<<_data->b << std::endl;
    _data->a = 10;
}