#include<iostream>
using namespace std;
class A
{
public:
	//第一个虚函数(这里是纯虚函数)，没有重写，不能用voerride修饰
	virtual void func(int a) = 0;
};
class B:public A
{
public:
	//在重写虚函数的地方加上override，要求重写的虚函数和基类一模一样，不然无法通过编译
	virtual void func()override
	{

	}
};
int main()
{
	
}