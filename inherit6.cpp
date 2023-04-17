#include <iostream>
#include <cstring>
using namespace std ; 
//英雄联盟类 
class Hero
{
	private :
	int blood ; 
	string name ;
	public :
	Hero(int blood = 100, string name = "man wang")
	{
		this->blood = blood ; 
		this->name = name ;
	}
	~Hero()
	{
		if(this->blood < 0){
			cout << "Hero blood error!\n" << endl ;
			return ;
		}
		cout << "Hero name is:" << this->name << endl ; 
		cout << "Hero blood is :" << this->blood << endl ;	
	}	
}; 
//德玛类，继承于英雄类 
class Dema : public Hero
{
	private :
	int blood ; 
	string name ;
	public :
	Dema(int blood , string name);
	~Dema();
};
 
//在实现子类的构造函数时，可以同时向父类的构造函数传参
//例如这个例子的 : Hero(58,JS),相当于向父类的构造函数传参
 
//当然，子类也可以给本类的的成员传参
Dema::Dema(int blood , string name) : Hero(89 , "JS") , blood(58) , name("dema")
{
	this->name = name ;
	this->blood = blood ; 
}
 
Dema::~Dema()
{
	if(this->name != "dema"){
		cout << "This Hero are no dema!" << endl;
		return ;
	}
	if(this->blood < 0){
		cout << "Dema blood error!\n" << endl ;
		return ;
	}
	cout << "Dmea name is:" << this->name << endl ; 
	cout << "Dema blood is :" << this->blood << endl ;	
}
 
int main(int argc , char **argv)
{
	Dema player1(79,"dema");
	return 0 ;
}