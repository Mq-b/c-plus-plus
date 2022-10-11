#include<iostream>

namespace S {
	extern int n;
	int f();
}
struct X {//本翻译单元的定义，只是为了去查找外部链接的value
	static int value;//只是声明value
};
int main() {
	std::cout << S::n << std::endl;
	std::cout << S::f() << std::endl;
	std::cout << X::value << std::endl;
}