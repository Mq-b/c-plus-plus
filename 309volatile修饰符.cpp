#include<iostream>
/*
	volatile 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素（操作系统、硬件、其它线程等）更改。所以使用 volatile 告诉编译器不应对这样的对象进行优化!!!。

	volatile 关键字声明的变量，每次访问时都必须从内存中取出值（没有被 volatile 修饰的变量，可能由于编译器的优化，从 CPU 寄存器中取值）

	const 可以是 volatile （如只读的状态寄存器）

	指针可以是 volatile
*/

//3）下面的函数有什么错误？

int square1(volatile int* ptr)
{
	return *ptr * *ptr;
}

//这段代码有点变态，其目的是用来返回指针ptr指向值的平方，但是，由于ptr指向一个volatile型参数，编译器将产生类似下面的代码：

int square2(volatile int* ptr)
{
	int a, b;
	a = *ptr;
	b = *ptr;
	return a * b;
}

//由于* ptr的值可能被意想不到地改变，因此a和b可能是不同的。结果，这段代码可能返回的不是你所期望的平方值！正确的代码如下：

int square3(volatile int* ptr)
{
	int a = *ptr;
	return a * a;
}
int main() {

}