#include<iostream>
using namespace std;

class Base
{
public:
    int m_A;//int占四个字节
private:
    int m_B;
protected:
    int m_C;
};

class son : public Base
{
public:
    int m_D;
};
void test01()
{
    //在父类中　所有非静态成员变量　都会被子类继承下去
    //父类中私有成员属性　被编译器隐藏了　所以访问不到　但是确实被子类继承了
    cout << "子类的size为:" <<sizeof(son) << endl;
}
int main()
{
    test01();
}