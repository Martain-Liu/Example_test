#include<Eigen/Core>
#include<Eigen/Dense>
#include<Eigen/Geometry>
#include<iostream>
using namespace std;
bool ComputeIK(int leg, const Eigen::Vector3d& pf, Eigen::Vector3d& qj) {
  float l1;
  float l2;
  float l3;
  float l4;

  if ((leg == 0) || (leg == 1)) {
    l1 =0.2375;
    l2 =0.226;
    l3 =0.31;
    l4 = 0;
  } else {
    l1 =0.2375;
    l2 =0.255;
    l3 =0.31;
    l4 = 0;
  }

  // pf:  foot position w.r.t the hip
  float side_sign = 1;
  if ((leg == 0) || (leg == 2)) { side_sign = -1; }

  float square_alpha = pf(2) * pf(2) + pf(1) * pf(1) - l1 * l1;
  if (square_alpha < 0) { return false; }

  float alpha = std::sqrt(square_alpha);
  qj(0) = std::atan2(alpha, side_sign * l1) - std::atan2(fabs(pf(2)), pf(1));
  float temp_c3 = (square_alpha + pf(0) * pf(0) - l2 * l2 - l3 * l3) / (2 * l2 * l3);
  if (temp_c3 * temp_c3 > 1) { return false; }
  float temp_s3 = std::sqrt(1 - temp_c3 * temp_c3);

  // O configuration for PX
  if (leg == 0 || leg == 1) {
    qj(2) = std::atan2(-temp_s3, temp_c3);
  } else {
    qj(2) = std::atan2(temp_s3, temp_c3);
  }
  qj(2) = -qj(2);

  if (leg == 0 || leg == 1) { temp_s3 = -temp_s3; }

  float temp_s2 = ((l2 + l3 * temp_c3) * pf(0) - l3 * temp_s3 * alpha) / (square_alpha + pf(0) * pf(0));
  float temp_c2 = ((l2 + l3 * temp_c3) * alpha + l3 * temp_s3 * pf(0)) / (square_alpha + pf(0) * pf(0));
  qj(1) = std::atan2(temp_s2, temp_c2);
  qj(1) = -qj(1);

  return true;
}

int main(){
    int leg =0;
    Eigen::Vector3d pf; pf<<-0.3, -0.2375,-0.4;
    Eigen::Vector3d qj; qj<<0,0,0;
    bool res = ComputeIK(leg, pf, qj);
    std::cout<<"qj == "<< qj.transpose()<<std::endl;

    Eigen::Vector3f p[4];
    p[0] << 1,1,1;
    p[1] << 2,2,2;
    p[2] << 3,3,3;
    p[3] << 4,4,4;
    std::cout<<"p==" <<p[1][1] <<std::endl;
}