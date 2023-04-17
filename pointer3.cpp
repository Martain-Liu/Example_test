#include<iostream>
#include<string>
using namespace std;
void swapr(int &a, int &b);
void swapp(int* a, int* b);
int main()
{
	int left=123, right=321;
	cout << "no swap:\t" << left << "::" << right << endl;//123::321
	swapr(left, right);
	cout << "swap:\t\t" << left << "::" << right << endl;//321::123
	swapp(&left, &right);
	cout << "swap again:\t" << left << "::" << right << endl;//123::321
	cin.get();
	return 0;
}
void swapr(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swapp(int* a, int* b)
{
	int temp = *a;
    cout<<"temp==" <<temp <<endl;
	*a = *b;
	*b = temp;
}