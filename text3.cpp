#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <math.h>

#include<Eigen/Core>
#include<Eigen/Dense>
#include<Eigen/Geometry>

#include <qpOASES.hpp>

using namespace boost::numeric::ublas;
using namespace std;
using namespace Eigen;
using namespace qpOASES;

// int main()
// {

//     MatrixXf M1 = MatrixXf::Random(3,8);
//     cout << "Column major input:" << endl << M1 << "\n";
//     cout << M1.outerStride() <<endl;

//     Map<MatrixXf,0,OuterStride<> > M2(M1.data(), M1.rows(), (M1.cols()+2)/3, OuterStride<>(M1.outerStride()*3));
//     cout << "1 column over 3:" << endl << M2 << "\n";
    
//     // typedef Matrix<float,Dynamic,Dynamic,RowMajor> RowMajorMatrixXf;
//     // RowMajorMatrixXf M3(M1);
//     // cout << "Row major input:" << endl << M3 << "\n";

//     // Map<RowMajorMatrixXf,0,Stride<Dynamic,3> > M4(M3.data(), M3.rows(), (M3.cols()+2)/3,
//     //                                             Stride<Dynamic,3>(M3.outerStride(),3));
//     // cout << "1 column over 3:" << endl << M4 << "\n";

//     // Eigen::Matrix<double ,6, 3> A;
//     // A<<1, 2, 3,
//     //    4, 5, 6,
//     //    7, 8, 9,
//     //    3, 2, 1,
//     //    6, 5, 4,
//     //    9, 8, 7;
//     // cout<<A.outerStride() <<endl;
//     // cout<<"----------------" <<endl;

//     // Map<MatrixXd,0,OuterStride<> > B(A.data(), 3, 3,  OuterStride<>(A.outerStride()*3));

//     // cout<<B <<endl;
// }



/** Example for qpOASES main function using the QProblem class. */
int main( )
{
	USING_NAMESPACE_QPOASES

	/* Setup data of first QP. */
	real_t H[2*2] = { 1.0, 0.0, 0.0, 0.5 };
	real_t A[1*2] = { 1.0, 1.0 };
	real_t g[2] = { 1.5, 1.0 };
	real_t lb[2] = { 0.5, -2.0 };
	real_t ub[2] = { 5.0, 2.0 };
	real_t lbA[1] = { -1.0 };
	real_t ubA[1] = { 2.0 };

	/* Setup data of second QP. */
	real_t g_new[2] = { 1.0, 1.5 };
	real_t lb_new[2] = { 0.0, -1.0 };
	real_t ub_new[2] = { 5.0, -0.5 };
	real_t lbA_new[1] = { -2.0 };
	real_t ubA_new[1] = { 1.0 };


	/* Setting up QProblem object. */
	QProblem example( 2,1 );

	Options options;
	example.setOptions( options );

	/* Solve first QP. */
	int_t nWSR = 10;
	example.init( H,g,A,lb,ub,lbA,ubA, nWSR );

	/* Get and print solution of first QP. */
	real_t xOpt[2];
	real_t yOpt[2+1];
	example.getPrimalSolution( xOpt );
	example.getDualSolution( yOpt );
	printf( "\nxOpt = [ %e, %e ];  yOpt = [ %e, %e, %e ];  objVal = %e\n\n", 
			xOpt[0],xOpt[1],yOpt[0],yOpt[1],yOpt[2],example.getObjVal() );
	
	/* Solve second QP. */
	nWSR = 10;
	example.hotstart( g_new,lb_new,ub_new,lbA_new,ubA_new, nWSR );

	/* Get and print solution of second QP. */
	example.getPrimalSolution( xOpt );
	example.getDualSolution( yOpt );
	printf( "\nxOpt = [ %e, %e ];  yOpt = [ %e, %e, %e ];  objVal = %e\n\n", 
			xOpt[0],xOpt[1],yOpt[0],yOpt[1],yOpt[2],example.getObjVal() );

	example.printOptions();
	/*example.printProperties();*/

	/*getGlobalMessageHandler()->listAllMessages();*/

	return 0;
}