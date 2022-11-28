#include"lib//mylib.h"
#include<array>
#include<string>
#include<ranges>
#include<vector>
#include<iostream>

template<class F,class ptr =void*>
struct X {
	X() = delete;
	X(F f) {
		this->func = f;
	}
	X(F func, ptr p) {
		this->func = func;
		this->p = p;
	}
	template<class...Args>requires (std::is_pointer_v<F> || std::is_class_v<F>)
	auto operator()(Args&&...args) {
		return func(args...);
	}
	template<class...Args>
	auto operator()(Args&&...args) {
		return (p->*func)(args...);
	}
private:
	F func;
	ptr p;
};
struct Test {
	void f() { std::cout << "666\n"; }
};
int main() {
	auto f = [](int n) {std::cout << n << '\n'; };
	auto f2 = +[](int n) {std::cout << n << '\n'; };
	X x = f;
	x(1);
	X x2 = f2;
	x2(5.6);
	Test t;
	X x3 = { &Test::f,&t };
	x3();
}