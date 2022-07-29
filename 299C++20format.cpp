#include<iostream>
#include<string>
#include<format>
int main() {
	auto a = std::format("姓名:{} 年龄:{} 身高:{}", "傻子", 123, 51.2);//字符串拼接
	std::cout << a << std::endl;

	std::string s{ std::format("1 {}",12.1) };
	std::cout << s << std::endl;

	char c = 120;
	auto s0 = std::format("{:6}", 42);    // s0 的值为 "    42"
	auto s1 = std::format("{:6}", 'x');   // s1 的值为 "x     "
	auto s2 = std::format("{:*<6}", 'x'); // s2 的值为 "x*****"
	auto s3 = std::format("{:*>6}", 'x'); // s3 的值为 "*****x"
	auto s4 = std::format("{:*^6}", 'x'); // s4 的值为 "**x***"
	auto s5 = std::format("{:6d}", c);    // s5 的值为 "   120"
	auto s6 = std::format("{:6}", true);  // s6 的值为 "true  "

}