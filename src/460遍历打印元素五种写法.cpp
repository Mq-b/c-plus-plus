#include<iostream>
#include<fmt/core.h>

//C++17以前
template<typename...Args>
void print1(Args&&...args) {
	auto _ = { (std::cout << args << ' ' ,0)... };
	endl(std::cout);
}
void print2() {}
template<typename T, typename...Args>
void print2(T&& v, Args&&...args) {
	std::cout << v << ' ';
	print2(std::forward<Args>(args)...);
}
//C++17以后
template<typename...Args>
void print3(Args&&...args) {
	((std::cout << args << ' '), ...);
	endl(std::cout);
}
template<typename...Args>
void print4(Args&&...args) {
	(std::cout << ... << args) << std::endl;
}
template<typename T, typename...Args>
void print5(T&& v, Args&&...args) {
	std::cout << v << ' ';
	if constexpr (sizeof...(args) > 0) {
		print5(std::forward<Args>(args)...);
	}
}

int main() {
	print1("🥵", 1, 3.14);
	print2("🥵", 1, 3.14);
	endl(std::cout);

	print3("🥵", 1, 3.14);
	print4("🥵", 1, 3.14);
	print5("🥵", 1, 3.14);
}