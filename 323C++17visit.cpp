#include<iostream>
#include<variant>
#include<string>

int main() {
	auto func = [](auto a) {std::cout << typeid(a).name() << std::endl; };
	std::variant<int, double, std::string>var1(42), var2(3.14), var3("visit");

	std::visit(func, var1);		//必须使用variant作为参数传递
	std::visit(func, var2);
	std::visit(func, var3);
}