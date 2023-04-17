#include "FSM_State_RecoveryStand.h"

FSM_State_RecoveryStand::FSM_State_RecoveryStand(ControlFSMData* _controlFSMData)
    : FSM_State(_controlFSMData)
{
    std::cout << "Entry IN  FSM_State_RecoveryStand" << std::endl;
    std::cout << "FSM_State_RecoveryStand-a:=="<<_data->a << std::endl;
    std::cout << "FSM_State_RecoveryStand-b:=="<<_data->b << std::endl;
}