#include<iostream>
using namespace std;
class Person
{
public:

    Person(int age){
        //this指针指向　被调用的成员函数　所属的对象
        //上面这句话很难理解，解释一下:
        //＂被调用的成员函数＂指的是 Person(int age)这个函数
        //"所属的对象"指的是p1
        //因此this->指向p1
        this->age = age;
    }

    Person& PersonAddAge(Person &p){
        this->age += p.age;
        return *this;
        //return *this返回的是当前对象的克隆或者本身（若返回类型为A, 则是克隆，若返回类型为A&，则是本身 ）。
        //return this返回当前对象的地址（指向当前对象的指针）
        //由于这里是＂Person&＂，则返回的是当前对象本身　也就是p2　
        //这里可以尝试将　"return *this"->"return this"  以及　＂Person& ＂->＂Person＂试一试
    }

    int age;
};
void test01()
{
    Person p1(18);
    cout<<"nianling==" << p1.age <<endl;

}
void test02()
{
    Person p1(10);
    Person p2(10);
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout<<"p2的年龄==" <<p2.age <<endl;
}
int main()
{
    // test01();

    test02();
}