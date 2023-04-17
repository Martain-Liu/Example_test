#ifndef FSM_State_H
#define FSM_State_H

#include<iostream>
using namespace std;
#include "ControlFSMData.h"
// struct ControlFSMData {
//     double a ;
//     double b;
// };


class FSM_State
{ 
public:
    FSM_State(ControlFSMData* _controlFSMData);

    ControlFSMData* _data;
};

#endif 