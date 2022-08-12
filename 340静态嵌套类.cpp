#include<iostream>
class Test {
public:
	static class T {
	public:
		int a = 0;
	};
	int a=0;
};
int main() {
	Test::T a;
	a.a = 100;
	Test c;
	c.a = 100;
	std::cout << a.a << "," << c.a << std::endl;
}
//这应该算作编译器扩展，按照标准这应该报错，而不是MSVC这样只是警告
//warning C4091: “static ”: 没有声明变量时忽略“Test::T”的左侧