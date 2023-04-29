#include <iostream>
#include<exception>

struct MyException :std::exception {
	const char* data{};
	MyException(const char* s) :data(s) { puts("MyException()"); }
	~MyException() { puts("~MyException()"); }
	char const* what()const noexcept{ return data; }
};

void f()try {
	throw MyException("乐");
}
catch (const std::exception& e) {
	std::cerr << e.what() << '\n';
}
int main() {
	f();
}