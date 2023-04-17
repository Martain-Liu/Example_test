#include<iostream>
using namespace std;

void test01()
{
    int a = 10;
    cout <<"a==" <<a<<endl;
    int * p ;
    p = &a;
    //解引用：就是利用指针来修改所指向的内容
    *p = 1000;
    cout <<"a==" <<a<<endl;
}

void test02()
{
    //空指针
    //１　空指针用于给指针变量初始化
}

void test03()
{
    //const修饰指针：常量指针　指针的指向可以修改　指针指向的值不可以修改
    //const修饰常量：指针常量
    //const既修饰指针，又修饰常量

}

int main()
{
    test01();
}