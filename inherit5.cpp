#include<iostream>
using namespace std;
//继承同名成员的处理方式
class Base
{
    public:
        Base()
        {
            m_A = 100;
        }
        ~Base(){
            
        }

        int m_A;

        void func()
        {
            cout << "Base作用于下的成员函数" << endl;
        }
};

class Son : public Base
{
    public:
        Son()
        {
            m_A = 200;
        }
        ~Son()
        {
        
        }
        int m_A;

        void func()
        {
            cout << "Son作用于下的成员函数" << endl;
        }

        void func(int a)//函数重载
        {
            cout << "Son作用于下的成员函数" << endl;
        }

};


void test01()
{
    Son s;
    cout <<"Son下面的m_A=="  <<s.m_A <<endl;//200
    cout <<"Base下面的m_A=="  <<s.Base::m_A <<endl;//100
}
void test02()
{
    Son s;
    s.func();
    s.Base::func();
    //假如子类中没有func()，就只有父类有func()  那么s.func();就直接调用父类的
    /*
        假如子类中有func()这个名称的函数　那么子类的func()函数会将父类所有这个名称的函数隐藏掉
        是无法通过直接访问的，就算是s.func(100);也不行，需要要加上作用域．
    */
}

int main()
{
    // test01();
    test02();
}