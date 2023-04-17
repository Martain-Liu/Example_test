#ifndef FSM_STATE_RECOVERY_STANDUP_H
#define FSM_STATE_RECOVERY_STANDUP_H

#include "FSM_State.h"
#include "ControlFSMData.h"
class FSM_State_RecoveryStand : public FSM_State
{
public:
    FSM_State_RecoveryStand(ControlFSMData* _controlFSMData);

};
#endif;