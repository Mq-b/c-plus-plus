#include<iostream>//阶段 4

int main() {
	auto str = "\u0030";//已经是基础源字符集了,这是实现定义的
	auto str2 = "0";//在第一个阶段将源文件的各个单独字节映射为基础源字符集
	std::cout << str << ' ' << str2 << std::endl;
	std::cout << (*str == *str2) << std::endl;

	//下面这种在第二阶段
	auto str3 = "6666 \
					66";
	int n = \
		10;

	auto str4 = R"(\u0030)";//在阶段3撤回在任何原始字符串字面量的首尾双引号之间在阶段 1 和 2 期间进行的所有变换
	std::cout << str4 << std::endl;

	int foo = 1;
	int bar = 0xE + foo;   // 错误：非法的预处理数字 0xE+foo
	int baz = 0xE + foo; // OK

	std::cout << bar << std::endl;

	auto str5 = "a""b";//阶段6

}
/*
这里只是稍微举例，具体看文档
https://zh.cppreference.com/w/cpp/language/translation_phases
*/