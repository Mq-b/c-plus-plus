#include<iostream>
/*
静态生命周期的变量有两种初始化方式：静态初始化 以及 动态初始化。
采用静态初始化初始化的变量，其初始化表达式是一个常量表达式，其值可以在编译期计算出。采用动态初始化初始化的变量，其初始化表达式将会在运行时以声明顺序求值。
constinit的作用在于显式地指定变量的初始化方式为静态初始化，
比如动态初始化的缺陷
// A.cpp
int a = doSomething();

// B.cpp
extern int a;
int b = a + 1;
如果编译器决定首先初始化b而不是a，初始化顺序的错误将产生未定义行为

*/
consteval int foo() {
	return 10;
}

int bar() { return 10; };

constinit int a = 10;    // OK
constinit int b = foo(); // OK
constinit thread_local int c = 20; // OK constinit对线程存储持续时间也有效
//constinit int d = bar(); // Error: `bar()` is not a constant expression
void baz() {
	//constinit int e = 20;  // Error: e is not static
	constinit static int e = 20;//全局变量都是静态的，所以直接被constinit修饰没问题，在局部得加上static才行
	//与consteval不同的是，constinit修饰的变量允许被修改
	a = 100;
}
/*constinit仅对具有静态或线程存储持续时间的变量的声明有效!!*/