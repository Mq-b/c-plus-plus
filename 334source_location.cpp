#include <iostream>
#include <string_view>
#include <source_location>

void log(std::string_view message)
{
	const auto location = std::source_location::current();
	std::cout << "info:"
		<< location.file_name() << ':'		/* 路径和文件名 */
		<< location.line() << ' '			/* 7行 */
		<< location.function_name() << ' '	/* log */
		<< location.column() << ' '			/* 46列 */
		<< message << '\n';
}
//		function_name和line column这些返回的是调用者，调用了当前函数的的信息
void abc()
{
	log("Hello world!");
	auto a = std::source_location::current();
	std::cout << a.file_name() << std::endl;		/* 路径和文件名 */
	std::cout << a.line() << std::endl;				/* 18行 */
	std::cout << a.function_name() << std::endl;	/* abc */
	std::cout << a.column() << std::endl;			/* 33列 */

}
auto main()->int {
	abc();
}
/*
	 current
	[静态]
	构造对应调用点位置的新 source_location
	(公开静态成员函数)
	域访问
	line
		返回此对象所表示的行号，这里都是指调用的函数
	(公开成员函数)
	column
		返回此对象所表示的列号
	(公开成员函数)
	file_name
		返回此对象所表示的文件名
	(公开成员函数)
	function_name
		若此对象表示函数体内的位置，则返回对应函数名的实现定义的空终止字节字符串。否则，返回空字符串。
	(公开成员函数)
*/