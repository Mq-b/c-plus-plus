#include<iostream>
#include<string>
int main()
{
	//静态断言编译器检测，减少开销
	//static_assert(常量表达式条件,"提示的字符串"),为真继续，为假就提示错误
	static_assert(sizeof(void*) == 4, "64位系统不支持");
	std::cout << "hello C++" << std::endl;
	return 0;
}