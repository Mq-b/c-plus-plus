#include<iostream>

namespace S {
	extern int n;
	extern const int v;//命名空间作用域内未声明为 static 或 const(包括constexpr) 变量都具有内部链接
	int f();
}
struct X {//本翻译单元的定义，只是为了去查找外部链接的value
	static int value;//只是声明value
};
int main() {
	std::cout << S::n << std::endl;
	std::cout << S::f() << std::endl;
	//std::cout << S::v << std::endl;//error 无法打印
	std::cout << X::value << std::endl;
}
// 参考: https://zh.cppreference.com/w/cpp/language/storage_duration