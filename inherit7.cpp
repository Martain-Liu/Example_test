#include <iostream>
#include <cstring>
using namespace std ; 
/*
父类指针指向子类实例对象

本例程无法运行 仅作为演示

父类指针指向子类实例对象，对于普通重写函数时，会调用父类中的函数。而调用被子类重写虚函数时，会调用子类中的函数。
这是因为子类中被重写的虚函数的运行方式是动态绑定的，与当前指向类实例的父类指针类型无关，仅和类实例对象本身有关。

1 静态绑定发生在编译期，动态绑定发生在运行期；
2 对象的动态类型可以更改，但是静态类型无法更改；
3 在继承体系中只有虚函数使用的是动态绑定，其他的全部是静态绑定（成员变量也是静态绑定）；

*/
class A{
public:
    void func_a();
    virtual void func_b();
    int n;
};

class B : public A{
public:
    void func_a();
    virtual void func_b();
    int n;
};

class C : public A{
public:
    void func_a();
    virtual void func_b();
    int n;
};

B* b = new B();
C* c = new C();
A* a = b;    // 此时，a的静态类型是A*, 动态类型是B*

a->func_a();// 指向的是基类A的func_a, 因为func_a是普通函数，是静态绑定的
a->func_b(); // 指向B中的func_b, virtual修饰的虚函数，是动态绑定，在运行时确定所属具体的实例
a->n;		 // 指向基类的n，成员变量是静态绑定
a = c;       // 动态类型是可以修改的，此时是C*

 
int main(int argc , char **argv)
{

	return 0 ;
}