/*
运算符 typeid、sizeof、noexcept 和 decltype (C++11 起) 的操作数是不求值表达式（除非运算符是 typeid 且操作数是多态泛左值），因为这些运算符只会查询它们的操作数的编译期性质。

因此，std::size_t n = sizeof(std::cout << 42); 不进行控制台输出。

requires 表达式也是不求值表达式。(C++20 起)

当应用于多态类型的表达式时，typeid表达式的值除了虚表查找会涉及运行时开销，其他事件typeid都在编译时解决
*/
#include<iostream>
int main() {
	std::size_t n = sizeof(std::cout << 42);
	std::cout << n << std::endl;
}