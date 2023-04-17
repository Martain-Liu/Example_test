#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
#include<Eigen/Core>
#include<Eigen/Dense>
#include<Eigen/Geometry>
#define MATRIX_SIZE 50
#include <vector>
/*
https://www.cnblogs.com/yanlingyin/archive/2011/12/07/2278961.html
https://www.iteye.com/blog/xinklabi-653643 
*/
/*
指针：指针就是一个变量，如果非要说是一个特殊的变量也不为过，因为指针的初始化和解引用等不同的操作方式而已。就内存的分布来说，指针和一个变量在内存中存放是没有任何区别的，无非指针存放的是变量的地址。

传值：传值无非就是实参拷贝传递给形参，单向传递（实参->形参），赋值完毕后实参就和形参没有任何联系，对形参的修改就不会影响到实参。

传地址：为什么说传地址也是一种传值呢？因为传地址是把实参地址的拷贝传递给形参。还是一句话，传地址就是把实参的地址复制给形参。复制完毕后实参的地址和形参的地址没有任何联系，对实参形参地址的修改不会影响到实参, 但是对形参地址所指向对象的修改却直接反应在实参中，因为形参指向的对象就是形参的对象。

传引用：传引用本质没有任何实参的拷贝，一句话，就是让另外一个变量也执行该实参。就是两个变量指向同一个对象。这是对形参的修改，必然反映到实参上。
*/

/*
传值：将实参复制一份给形参 因此改变形参的地址以及值对实参没有任何影响
传地址：将实参地址复制一份给形参 因此改变形参(这个时候形参是地址)所指向的值 就是改变实参 
传引用：没有任何复制 
*/
void AddOne(int x){
    x=x+1;
    cout<<"值传递--函数操作地址"<<&x<<endl;
}
void AddTwo(int *x){
    *x=*x+1;
     cout<<"指针传递--函数操作地址 "<<x<<endl;
}

void AddThree(int& x){
    x=x+1;
    cout<<"引用传递--函数操作地址"<<&x<<endl; 
}

int main()
{
    int a,b,c;
    a=1;
    b=2;
    c=3;
    cout<<"a的地址为:" <<&a <<endl;
    cout<<"b的地址为:" <<&b <<endl;
    cout<<"c的地址为:" <<&c <<endl;

    cout<<"加之前a==" <<a <<endl;
    //传入的是a的复制(copy)
    AddOne(a);
    cout<<"加之后a==" <<a <<endl;

    cout<<"加之前b==" <<b <<endl;
    //传入的是b的地址
    AddTwo(&b);
    cout<<"加之后b==" <<b <<endl;

    cout<<"加之前c==" <<c <<endl;
    //传入的是c本身
    AddThree(c);
    cout<<"加之后c==" <<c <<endl;
}
