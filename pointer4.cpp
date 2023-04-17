#include<iostream>
#include<ctime>
#include<cmath>
#include<Eigen/Core>
#include<Eigen/Dense>
#include<Eigen/Geometry>
#include <vector>
using namespace std;

class RobotController{
    public:
        void daying()
        {
            cout << "13456" << endl;
        }
};

void helper(RobotController* ctrl)
{
    ctrl->daying();
}

int main()
{
    helper(new RobotController());
}