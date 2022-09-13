#include<iostream>
struct Test {
	static inline int v = 0;
	//静态数据成员可以声明为 inline。 inline 静态数据成员可以在类定义中定义，而且可以指定初始化器。它不需要类外定义
};
int main() {
	Test c;
	std::cout << c.v << std::endl;
	Test::v = 100;
	std::cout << c.v << std::endl;
	
	Test d;
	std::cout << d.v << std::endl;
	d.v = 2;
	std::cout << Test::v << std::endl;
	//和普通的static变量一样，它是所有对象共享
}