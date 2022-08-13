#include<iostream>
/*
std::enable_if 顾名思义，满足条件时类型有效。作为选择类型的小工具，其广泛的应用在 C++ 的模板元编程（meta programming）中
*/

template <typename T,typename A>
struct check;

template <typename T>
struct check<T, typename std::enable_if<T::value>::type> {
	static constexpr bool value = T::value;
};
int main()
{
	std::cout<<check<int,true>
}