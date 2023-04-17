#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;

#include"main.h"
#include "ControlFSMData.h"
void test01()
{
    data.a = 1;
    data.b = 2;

    locomotion = new FSM_State_Locomotion(&data);
    recoveryStand = new FSM_State_RecoveryStand(&data);
}
int main()
{
    test01();

}