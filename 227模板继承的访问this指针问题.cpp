#include<iostream>
#include<string>
template<typename T>
class Base {
public:
	void bar() { std::cout << "111" << std::endl; };
};
template<typename T>
class Derived : public Base<T> {
public:
	void foo()
	{
		//this->bar();

		bar();//错误写法，访问不到
	}
};

class A {
public:
	void bar() { std::cout << "111" << std::endl; };
};
class B :public A {
public:
	void foo()
	{
		bar(); 
	}
};

int main()
{
	Derived<int> i;
	i.foo();
	i.bar();

	B v;
	v.bar();
	v.foo();
	return 0;
}
//由此得出，如果要父类是模板要调用它的方法得使用this，普通的继承则不需要