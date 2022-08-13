#include<iostream>
#include<string>
//从C++14 开始，变量也可以被某种类型参数化。称为变量模板。
//例如可以通过下面的代码定义pi，但是参数化了其类型：

template<typename T=int>//我们写作默认int 
T pi{};//初始化列表 为0
//注意，和其它几种模板类似，这个定义最好不要出现在函数内部或者块作用域内部。
int main()
{
	std::cout.precision(16);
	pi<int> = 20;//pi<>=20;效果一样
	std::cout << pi<int> << std::endl; //20
	pi<double> = 3.14159265358;
	std::cout << pi<double> << std::endl;//3.14159265358
	std::cout << pi<float> << std::endl;//0
	return 0;
}
//变量模板不是局部变量，是另一种全局变量,main函数内是使用不是实例化也不是创建