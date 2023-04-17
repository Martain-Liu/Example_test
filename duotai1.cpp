#include<iostream>
using namespace std;
/*
动态多态满足关系：
1 有继承关系
2 子类要　重写　父类的　虚函数
注意：＂重写＂和＂重载＂不一样　
函数的返回值类型＆函数名＆参数列表　这三个完全相同　才叫重写
*/
class Animal
{
public:
    virtual void speak()
    {
    /*
        如果函数前面不加virtual　那么就是地址早绑定　
        test01()中无论传入的是哪个子类　doSpeak()都会调用父类的speak()函数
    */
        cout<<"动物在说话"<<endl;
    }
};

class Cat : public Animal 
{
public:
    void speak()
    {
        cout<<"小猫在说话"<<endl;
    }

};

void doSpeak(Animal &animal) 
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);
}

int main()
{
    test01();
}
/*
    当父类成员函数前面加上virtual之后，父类结构就出现变化了，
    父类里面新增了一个指针(vfptr)和一个表(vftable)，该指针指向这个表，表内装有虚函数的地址，
    该表和该指针同样被子类继承了，当子类重写这个虚函数的时候，
    从父类那儿继承下来的表内的虚函数的地址　就被子类所重写的函数的地址给覆盖了
*/