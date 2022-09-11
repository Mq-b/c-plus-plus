#include<iostream>
#define this_t std::remove_reference_t<decltype(*this)>//在类内获取自身的”注入类名“，注入类名就是指当前类作用域类自己的名字而已

int X;//如果去除这个全局变量，那么::A*也就不会产生错误了
struct X
{
	void f()
	{
		X* p;   // OK：X 指代注入类名
		//::X* q; // 错误：名称查找找到全局作用域的X变量了，它隐藏结构体名
		using c = this_t;
	}
};
struct A {};
struct B : private A {};
struct C : public B
{
	//A* p;   // 错误：无法访问注入类名 因为B是私有继承A，然后C继承了B，等于在本类C里面是没有A的，如果B继承A使用的是public就没有问题
	::A* q; // OK：不使用注入类名，::为了访问全局作用域
};
//注入类名是在类的作用域内该类自身的名字
//类定义的时候 类作用域可以使用该类的名字

//顺带说一句，模板类同样有效
//https://zh.cppreference.com/w/cpp/language/injected-class-name