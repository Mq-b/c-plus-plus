#include<iostream>

template <typename T>
auto multiply(T x, T y)->decltype(x* y)//auto只是占位符，后面的decltype获取表达式运算后的类型作为返回值
{
	return x * y;
}

int main() {
	decltype(1) a;//a是int

	struct {
		int a;
		int b;
	}c;//匿名类对象

	decltype(c) d;//decltype得到类型再创建
	d.a = 100;
	std::cout << d.a << std::endl;

	using type = decltype(c);//给匿名的类取别名
	type e;//创建对象
}