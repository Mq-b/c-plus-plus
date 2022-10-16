#include<iostream>
struct X {
	X(const char* str) :s(str) { puts("X"); }
	virtual const char* what() {
		return s;
	}
	const char* s;
};

struct Y :X {
	Y(const char* str) :X(str) { puts("Y"); }
};

int main() {
	X x = Y("6666");//子类初始化器初始父类对象
	std::cout << x.what() << std::endl;//6666

	X* x2 = new Y{ "66" };
	x2->what();//空
}
//其实这样写没什么意义