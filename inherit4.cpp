#include<iostream>
using namespace std;
//继承中的构造和析构的顺序
class Base
{
public:
    Base()
    {
        cout << "Base的构造函数" <<endl;
    }
    ~Base(){
        cout << "Base的析构函数" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son的构造函数" <<endl;
    }
    ~Son()
    {
        cout << "Son的析构函数" <<endl;
    }
};
void test01()
{
    // Base B;

    Son S;
    /*
    Base的构造函数
    Son的构造函数
    Son的析构函数
    Base的析构函数
    */

}
int main()
{
    test01();
}