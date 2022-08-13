#include<type_traits>//提供原型
#include <iostream>
template<typename T1, typename T2>
std::common_type_t<T1, T2> max(T1 a, T2 b)//c++14
{
	return b < a ? a : b;
}
template<typename T1,typename T2>
auto max1(T1 a, T2 b) -> typename std::decay<decltype(true ? a : b)>::type//c++11
{
	return b < a ? a : b;
}
template<typename T1, typename T2>
auto max2(T1 a, T2 b) -> decltype(b < a ? a : b)
{
	return b < a ? a : b;
}
template<typename T1, typename T2>
auto max3(T1 a, T2 b)
{
	return b < a ? a : b;
}
template<typename T1, typename T2,typename T3>
T3 max4(T1 a, T2 b)
{
	return b < a ? a : b;
}
template<typename T1, typename T2, typename RT =std::decay_t<decltype(true ? T1() : T2())>>//默认模板参数，其实就是c++11那个
RT max5(T1 a, T2 b)
{
	return b < a ? a : b;
}
template<typename T1, typename T2, typename RT =std::common_type_t<T1, T2>>//默认模板参数，是c++14类型萃取
RT max6(T1 a, T2 b)
{
	return b < a ? a : b;
}
template<typename T1, typename T2>
decltype(auto) max7(T1 a, T2 b)//decltype(auto)的意思是右边的东西类型不decay，意思就是不退化，可以直接推导返回引用
{
	return b < a ? a : b;
}
auto max8(auto x, auto y) -> decltype(x < y ? y : x)//c++20的特性，众多的auto，直接不需要模板了
{
	return x < y ? y : x;
}
auto max9(auto x, auto y) //而且也可以不加推导
{
	return x < y ? y : x;
}

int main()
{
	std::cout << typeid(::max(10, 10u)).name() << std::endl;
	std::cout << typeid(::max1(10, 10u)).name() << std::endl;
	std::cout << typeid(::max2(10, 10u)).name() << std::endl;
	std::cout << typeid(::max3(10, 10u)).name() << std::endl;
	std::cout << typeid(::max4<int,double,unsigned int>(10, 5.7)).name() << std::endl;//这个最麻烦
	std::cout << typeid(::max5(10, 10u)).name() << std::endl;
	std::cout << typeid(::max6(10, 10u)).name() << std::endl;
	std::cout << typeid(::max7(10, 10u)).name() << std::endl;
	std::cout << typeid(::max8(10, 10u)).name() << std::endl;
	std::cout << typeid(::max9(10, 10u)).name() << std::endl;

	//std::max(10, 20);//std库下的，别重定义就好
	return 0;
}
//类型会退化的，不用担心类型为引用的问题