#include<iostream>
#include<string>
#include <type_traits>
//从C++17 开始，标准库用变量模板为其用来产生一个值（布尔型）的类型萃取定义了简化方
//式。比如为了能够使用：
//std::is_const_v<T> // since C++17
//而不是：
//std::is_const<T>::value //since C++11
//标准库做了如下定义：
//namespace std {
//	template<typename T>
//	constexpr bool is_const_v = is_const<T>::value;
//}
int main()
{
	std::is_const_v<int>;
	std::cout << std::is_const_v<int> << std::endl;
	return 0;
}