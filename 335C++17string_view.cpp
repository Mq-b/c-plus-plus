#include<string_view>
#include<string>
#include<iostream>

using namespace std::literals::string_view_literals;	// 字面量定义在此命名空间 operator""sv

void func(std::string_view s) {
	std::cout << (void*)s.data() << std::endl;
}

int main() {
	const char* str = "abc";
	constexpr std::string_view unicode("abc");
	std::cout << (void*)str << "," << (void*)unicode.data() << std::endl;

	auto ss = "abc"sv;
	std::cout << (void*)ss.data() << std::endl;

	std::string string("A");
	std::string_view strr(string);
	std::cout << (void*)string.data() << "," << (void*)strr.data() << std::endl;

	std::string_view view("0123456789");
	std::cout << view.size() << std::endl;
	std::cout << view.max_size() << std::endl;
	std::cout << view.substr(0, 5) << std::endl;

	std::cout << (void*)view.data() << std::endl;	/* 结果与传入到函数中的一样 */
	func(view);
}
/* string_view是只读的，同时它能带来更高的性能 */

/* https://zh.cppreference.com/w/cpp/string/basic_string_view */