#include<iostream>
struct A{};
struct B {};

template<class T = A>
struct X;

template<>
struct X<A> {
	static void f() { std::cout << 1; }
};
template<>
struct X<B> {
	static void f() { std::cout << 2; }
};
template<template<class T = B>class C>//传入的X类型，它的默认模板类型是A
void g() {
	C<>::f();//调用A的f(),打印1
}
int main() {
	g<X>();//这就相当于函数默认参数，我传入了，那么肯定以我传入的为准，只不过我传入的是“类型”而非“值”，即:在模板定义中的template模板参数的专门化，模板参数参数的任何默认类型都将被忽略
}
/*值得一提的是，经过测试，如果使用gcc编译器，那么会打印2，且如果去掉了16行的T=B这个B的默认参数，无法通过编译，这对MSVC倒是没影响，推测是标准并没有对此有详细规定*/