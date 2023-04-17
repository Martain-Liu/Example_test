
#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <Eigen/Core>
#include <Eigen/Dense>   
#include <Eigen/Sparse>


#include <unsupported/Eigen/MatrixFunctions>
#include <iostream>
using namespace std;



int main () {
    // /***********************Exmple 1**********************************/
    // using namespace boost::numeric::ublas;
    // matrix<double> m (6, 6);
    // // std::cout << m << std::endl;
    // matrix_range<matrix<double> > mr (m, range (0, 6), range (0, 6));
    // for (unsigned i = 0; i < mr.size1 (); ++ i)
    //     for (unsigned j = 0; j < mr.size2 (); ++ j)
    //         mr (i, j) = 3 * i + j;
    // // std::cout << mr << std::endl;
    // matrix_range<matrix<double> > mb (m, range (0, 3), range (0, 3));
    // // std::cout << mb << std::endl;


    // /***********************Exmple 2**********************************/
    // Eigen::MatrixXd A1(3,3);
    // Eigen::MatrixXd A2(3,3);
    // Eigen::VectorXd B(6);
    
    // A1 << 1,2,3,
    //       4,5,6,
    //       7,8,9;
    // A2 << 1,2,3,
    //       4,5,6,
    //       7,8,9;
    // B << 0,1,1,1,1,1;
    // cout<< B << endl;

    /***********************Exmple 3**********************************/
    // Vec3 =  Eigen::Matrix<double, 3, 1>;
    // std::vector<Eigen::Vector3d > A;
    // A.push_back(Eigen::Vector3d(0,0,0));
    // A.push_back(Eigen::Vector3d(1,1,1));
    // A.push_back(Eigen::Vector3d(2,2,2));
    // A.push_back(Eigen::Vector3d(3,3,3));
    // double b;
    // b = A.size();
    // cout<<"b==" <<b <<endl;

    /***********************Exmple 3**********************************/
    // Eigen::Matrix3d a;
    // a << 1,0,0,
    //      0,1,0,
    //      0,0,1;
    // cout<< a.exp() <<"\n\n";
    /***********************Exmple 4**********************************/
//     Eigen::Matrix<double,2,2> A[2];
//     A[0]<<0,0,
//           0,0;
//     A[1]<<0,1,
//           1,0;
// //     cout<< A[0] <<endl;
// //     cout<< A[1] <<endl;
// //     cout<< A <<endl;
//       Eigen::Matrix<double,3,3> B;
//       B.setZero();
//       cout<< B<<endl;
    /***********************Exmple 5**********************************/
    Eigen::Matrix<Eigen::Matrix<double,2,2>, 3, 3 > A;
    // Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A;
    Eigen::Matrix<double, 2, 2> B;
    B<< 1,1,
        1,1;
    A(0,1) = B;
    cout<<A(2,2) <<endl;
      
}