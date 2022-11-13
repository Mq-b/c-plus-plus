#include<iostream>
#include<format>

// "({}, {})"_f(2, 4.5) 变成  std::format("({}, {})", 2, 4.5)
struct A {
	constexpr A(const char* s)noexcept :str(s) {}
	const char* str;
};

template<A a>
constexpr auto operator""_f() {
	return[=]<typename... T>(T... Args) { return std::format(a.str, Args...); };
}

int main() {
	auto ret = "({},{},{},{})"_f(2, 4.5, 10, "***");
	std::cout << ret << '\n';
}
