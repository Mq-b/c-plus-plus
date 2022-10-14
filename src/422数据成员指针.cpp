#include<iostream>

struct C { int m; };

void f(C& c, int C::* p) {
	c.*p = 10;
	std::cout << c.*p << std::endl;
}

int main() {
	int C::* p = &C::m;         //p指针指向类C的数据成员
	C c{ 7 };
	std::cout << c.*p << '\n';   // 7

	f(c, p);
	f(c, &C::m);
}
// https://zh.cppreference.com/w/cpp/language/pointer#.E6.88.90.E5.91.98.E6.8C.87.E9.92.88