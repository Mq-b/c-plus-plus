#include<charconv>
#include<iostream>
#include<algorithm>
#include<string>

void test() {
	const char* str = "123456";
	int value{ 0 };
	std::from_chars(str, str + 6, value);//字符串转数字
	std::cout << value << std::endl;

	char s[10]{ 0 };
	std::to_chars(s, s + 10, value);//数字转字符串
	std::cout << s << std::endl;
}
int main() {
	test();//只能用作c风格，不能用作string,当然，如果你用data然后加size偏移得到原始指针范围也是可以的
}