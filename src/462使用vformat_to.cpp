#include<iostream>
#include<string>
#include<format>

int main() {
	std::string s{};
	auto t = std::vformat_to(std::back_inserter(s), "{}", std::make_format_args("乐呵"));
	std::cout << s << '\n';
	t = 'a';
	t = 'b';
	std::cout << s << '\n';
}