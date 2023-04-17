#include "FSM_State.h"

FSM_State::FSM_State(ControlFSMData* _controlFSMData): _data(_controlFSMData)
{
  std::cout << "Entry IN  FSM_State" << std::endl;
  std::cout << "FSM_State-a:=="<<_data->a << std::endl;
  std::cout << "FSM_State-b:=="<<_data->b << std::endl;

}