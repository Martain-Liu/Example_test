#ifndef FSM_STATE_LOCOMOTION_H
#define FSM_STATE_LOCOMOTION_H

#include "FSM_State.h"
#include "ControlFSMData.h"
class FSM_State_Locomotion : public FSM_State
{
public:
    FSM_State_Locomotion(ControlFSMData* _controlFSMData);
};

#endif 