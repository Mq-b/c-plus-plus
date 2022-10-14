#include<iostream>
#include<source_location> 

void f(int n= 66666); //默认实参不是函数类型的一部分

void log(const std::source_location& so = std::source_location::current()) {
	//默认实参会在每次在未向对应形参提供实参的情况下调用函数时求值。
	std::cout << so.function_name() << std::endl;//main
	std::source_location ss = std::source_location::current();
	std::cout << ss.function_name() << std::endl;//log
}

int main() {
	f();
	log();
}

void f(int n) {
	std::cout << n << std::endl;
}