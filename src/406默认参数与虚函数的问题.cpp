#include<iostream>
struct A {
	virtual void f(int val = 1) {
		std::cout << "A " << val << std::endl;
	}
	virtual void test() {
		f();
	}
};
struct B :A {
	void f(int val = 0) {
		std::cout << "B " << val << std::endl;
	}
};

struct Base
{
	virtual void f(int a = 7) { std::cout << "Base " << a << std::endl; }
};

struct Derived : Base
{
	void f(int a) override{ std::cout << "Derived " << a << std::endl; }
};
int main() {
	B b;
	b.test();	//B 1
	b.f();		//B 0

	Derived d;
	Base& b2 = d;
	b2.f();// OK：调用 Derived::f(7) 
	//d.f();//// 错误：没有默认实参
}
/*
虚函数的覆盖函数不会从基类定义获得默认实参，而在进行虚函数调用时，默认实参根据对象的静态类型确定
https://zh.cppreference.com/w/cpp/language/default_arguments
*/