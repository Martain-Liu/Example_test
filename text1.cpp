#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
#include<Eigen/Core>
#include<Eigen/Dense>
#include<Eigen/Geometry>
#define MATRIX_SIZE 50
#include <vector>
#define MAX(a,b) (a>b)?(a):(b);
 
Eigen::Matrix3d Euler_2_rotation(Eigen::Vector3d euler)
{
  double heading, attitude, bank;
  heading = euler(0);
  attitude = euler(1);
  bank = euler(2);
  // Assuming the angles are in radians.
  double ch = cos(heading); //heading  y
  double sh = sin(heading);
  double ca = cos(attitude); //attitude z
  double sa = sin(attitude);
  double cb = cos(bank); //bank
  double sb = sin(bank);

  Eigen::Matrix3d rot;

  rot(0, 0) = ch * ca;
  rot(0, 1) = sh * sb - ch * sa * cb;
  rot(0, 2) = ch * sa * sb + sh * cb;
  rot(1, 0) = sa;
  rot(1, 1) = ca * cb;
  rot(1, 2) = -ca * sb;
  rot(2, 0) = -sh * ca;
  rot(2, 1) = sh * sa * cb + ch * sb;
  rot(2, 2) = -sh * sa * sb + ch * cb;

  return rot;
}

int main()
{
  Eigen::Vector3f a;
  Eigen::Vector3f b;
  Eigen::MatrixXf c(7,1);
  Eigen::DiagonalMatrix<float, 6> d;d.setZero();
  Eigen::Matrix<float, 6, 6> e;e.setIdentity();
  Eigen::Matrix<float, 6, 6> f;f.setIdentity();
  a << 1, 1, 1;
  b<< 2, 2, 2;
  std::cout<<"a==="<<a.transpose() <<std::endl;
  std::cout<<"b==="<<b.transpose() <<std::endl;
  c <<a, b, 9.8;
  std::cout<<"c==="<<c.transpose() <<std::endl;
  d.diagonal() = a.replicate(2,1);
  std::cout<<"d=== \n" << d.toDenseMatrix()  <<std::endl;
  f = d*e;
  std::cout<<"f=== \n"<<f<<std::endl;



}
// int main()
// {
//     Test* t1 = new Test();
//     t1->a = 10;
    
//     Test* t2 = new Test();
//     t2->a = 5;
    
//     cout << "&t1:" << t1 << " a = " << t1->a << endl;
//     cout << "&t2:" << t2 <<  " a = " << t2->a <<endl;
    
//     cout << "------------------------------" << endl;
//     t2 = t1;
//     cout << "&t1:" << t1 << " a = " << t1->a << endl;
//     cout << "&t2:" << t2 <<  " a = " << t2->a <<endl;
    
//     cout << "------------------------------" << endl;
    
//     t1->a = 111;
//     t2->a = 222;
//     cout << "&t1:" << t1 << " a = " << t1->a << endl;
//     cout << "&t2:" << t2 <<  " a = " << t2->a <<endl;
    
// }
// int main ()
// {
// 	std::vector<int> myvector (5);

// 	int* p = myvector.data();

// 	*p = 10;
// 	// ++p;
// 	// *p = 20;
// 	p[2] = 100;
	
// 	std::cout << "myvector contains:";
// 	for (unsigned i=0; i<myvector.size(); ++i)
// 		std::cout << ' ' << myvector[i];
// 	std::cout << '\n';
	
// 	return 0;
// }
/*
int main(int argc,char** argv)
{
    //cout<<"hello world"<<endl;
    //return 0;
//   Eigen::Matrix<float,2,3> matrix_23;
//   Eigen::Vector3d v_3d;
//   Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();
//   
//  // matrix_23 << 1,2,3,4,5,6;
//   //cout << matrix_23 << endl;
//   
//   Eigen::Matrix<double,2,1> result = matrix_23.cast<double>() * v_3d;
//   //cout<< result << endl;
//   
//    matrix_33 = Eigen::Matrix3d::Random();
//    //cout<< matrix_33 << endl;
//    
//    //cout<< "matrix_33.transpose="<< endl;
//    //cout<< matrix_33.determinant() << endl;
//    
//    Eigen::AngleAxised rotation_vector(M_PI/4,Eigen::Vector3d(0,0,1));
// 
//    cout<< rotation_vector.matrix() << endl;
   
     double heading,attitude,bank;
	heading=M_PI/4;
	attitude=M_PI/2;
	bank=0;//M_PI/4;
  // Assuming the angles are in radians.
  double ch = cos(heading);//heading  y
  double sh = sin(heading);
  double ca = cos(attitude);//attitude z
  double sa = sin(attitude);
  double cb = cos(bank);//bank 
  double sb = sin(bank);

  Eigen::Matrix3d rot;

  rot(0,0) = ch * ca;
  rot(0,1) = sh*sb - ch*sa*cb;
  rot(0,2) = ch*sa*sb + sh*cb;
  rot(1,0) = sa;
  rot(1,1) = ca*cb;
  rot(1,2) = -ca*sb;
  rot(2,0) = -sh*ca;
  rot(2,1) = sh*sa*cb + ch*sb;
  rot(2,2) = -sh*sa*sb + ch*cb;
  cout<< "rot= \n"<< rot <<endl;
                    //yaw     pitch   row
  Eigen::Vector3d ea0(attitude,heading,bank);
  Eigen::Matrix3d R;
      R = Eigen::AngleAxisd(ea0[0], ::Eigen::Vector3d::UnitZ())
        * Eigen::AngleAxisd(ea0[1], ::Eigen::Vector3d::UnitY())
        * Eigen::AngleAxisd(ea0[2], ::Eigen::Vector3d::UnitX());
  cout<< "R= \n" << R <<endl;
}
*/