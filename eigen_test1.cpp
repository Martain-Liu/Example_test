#include <iostream>
#include <Eigen/Core>
using namespace Eigen;
/***********Eigen库类类型作为函数参数 ******************/
/*
https://blog.csdn.net/zhouhan812/article/details/67640909
MatrixBase: 所有稠密矩阵表达式的共有基类(不是数组表达式,也不是稀疏和特殊矩阵类)。
                         在函数中使用它，意味着只能使用稠密矩阵。
ArrayBase: 所有密集数组表达式的共有基类(不是矩阵表达式,等等)。在函数中使用它，意味着只能使用数组。
DenseBase: 所有稠密矩阵、数组表达式的共有基类,即MatrixBase和ArrayBase的基类。
                          它可以用于使用矩阵和数组的函数。
EigenBase: 所有类型的对象的统一基类，可以被提升为稠密矩阵或数组,
                       例如特殊矩阵类,如对角矩阵（diagonal matrices）,置换矩阵（permutation matrices）等。
                      它可用于使用任何这样的一般类型的函数。
*/
/*
EigenBase
打印在Eigen库中最常用的对象的维数. 它可以是任何矩阵表达式,任何稠密或稀疏矩阵和数组
*/
template <typename Derived>
void print_size(const EigenBase<Derived>& b)
{
  std::cout << "size (rows, cols): " << b.size() << " (" << b.rows()
            << ", " << b.cols() << ")" << std::endl;
}

/*
DenseBase
打印稠密表达式的子块。接受任何稠密矩阵和数组表达,不接受稀疏矩阵和特殊矩阵类，如DiagonalMatrix等
*/
// template <typename Derived>
// void print_block(const DenseBase<Derived>& b, int x, int y, int r, int c)
// {
//   std::cout << "block: " << b.block(x,y,r,c) << std::endl;
// }

/*
ArrayBase
打印数组或数组表达式的最大系数
*/
// template <typename Derived>
// void print_max_coeff(const ArrayBase<Derived> &a)
// {
//   std::cout << "max: " << a.maxCoeff() << std::endl;
// }

/*
MatrixBase
打印给定矩阵或矩阵表达式的逆矩阵条件数
*/
// template <typename Derived>
// void print_inv_cond(const MatrixBase<Derived>& a)
// {
//   const typename JacobiSVD<typename Derived::PlainObject>::SingularValuesType&
//   sing_vals = a.jacobiSvd().singularValues();
//   std::cout << "inv cond: " << sing_vals(sing_vals.size()-1) / sing_vals(0) << std::endl;
// }

int main()
{
    Vector3f v;
    print_size(v);
    // v.asDiagonal() returns a 3x3 diagonal matrix pseudo-expression
    print_size(v.asDiagonal());
}