#include<iostream>
struct Test {
	Test(int a) {}
	int c = 10;
};

int main() {
	auto a = Test(1);
	auto b = (Test)1;
	auto c = static_cast<Test>(1);
}
/*不以说明符 explicit 声明且可以用单个参数调用 (C++11 前)的构造函数被称为转换构造函数
https://zh.cppreference.com/w/cpp/language/converting_constructor
*/