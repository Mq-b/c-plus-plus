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