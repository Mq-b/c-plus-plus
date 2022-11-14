#include<iostream>

template<class Derived>
struct Base { void name() { static_cast<Derived*>(this)->impl(); } };

struct D1 :Base<D1> { void impl() { std::cout << "D1::impl()\n"; } };
struct D2 :Base<D2> { void impl() { std::cout << "D2::impl()\n"; } };

int main() {
	Base<D1>b1;
	b1.name();
	Base<D2>b2;
	b2.name();
	D1 d1;
	d1.name();
	D2 d2;
	d2.name();

	static_cast<D1*>((void*)6)->impl();
}
//很诡异 https://zh.cppreference.com/w/cpp/language/crtp