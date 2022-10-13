#include<iostream>

void call() {
}
struct T {
	~T() { std::cout << "析构"; };
};
int main()noexcept
{
	//(&call).~decltype(&call)();
	int x = 10;
	(&x).~decltype(&x)();
	T c;
	(&c).~decltype(&c)();
	std::cout << x << std::endl;;//伪析构函数不会破坏对象

	typedef int t;
	t a = 42;
	a.t::~t();//我们还可以使用这种语法进行调用伪析构函数
	std::cout << a; //42,如果是gcc，那么它的结果就是未定义的
}
/*
伪析构函数调用，作为对普通析构函数的调用，不会结束它所应用的对象的生命周期，如同普通类直接调用析构函数不会有什么影响
同时您实际上不能为标量调用析构函数，因为它们没有析构函数（参见 [class.dtor]）。该语句仅允许用于调用不知道类型的对象的析构函数的模板代码 - 
它消除了为标量类型编写专门化的必要性。
标准规定：析构函数用于销毁其类类型的对象。
https://stackoverflow.com/questions/24000710/pseudo-destructor-call-does-not-destroy-an-object
*/

//拜伪析构函数调用所赐，所有标量类型都满足可析构 (Destructible) 的要求，而数组类型和引用类型则不满足。

/*
E1.E2
当 E1 是标量类型而 E2 是一个 ~ 之后跟着代表（移除 cv 限定后）相同类型的类型名或 decltype 说明符，可选地有限定时，它的结果是一种特殊的纯右值，它只能用作函数调用运算符的左操作数，
而不能用于其他目的。所构成的函数调用表达式被称为伪析构函数调用（pseudo destructor call）。它不接受任何实参，返回 void ，求值 E1 后结束它的结果对象的生存期。这是唯一使 operator. 
的左操作数具有非类类型的情形。允许进行伪析构函数调用，使得编写代码时无须了解某个给定类型是否存在析构函数成为可能。
https://zh.cppreference.com/w/cpp/language/operator_member_access#.E5.86.85.E5.BB.BA.E7.9A.84.E6.88.90.E5.91.98.E8.AE.BF.E9.97.AE.E8.BF.90.E7.AE.97.E7.AC.A6
*/