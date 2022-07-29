#include<iostream>
#include<string>
template<unsigned p, unsigned d> // p：要检查的数字，d：当前除数
struct DoIsPrime {
	static constexpr bool value = (p % d != 0) && DoIsPrime<p, d - 1>::value;
};
template<unsigned p> // 如果除数为 2，则结束递归
struct DoIsPrime<p, 2> {
	static constexpr bool value = (p % 2 != 0);
};
template<unsigned p> // 主模板
struct IsPrime {
	// 从 p/2 开始用除数开始递归：
	static constexpr bool value = DoIsPrime<p, p / 2>::value;
};

//类模板特例化，防止这些特殊情况
template<>//
struct IsPrime<0> { static constexpr bool value = false; };
template<>
struct IsPrime<1> { static constexpr bool value = false; };
template<>
struct IsPrime<2> { static constexpr bool value = true; };
template<>
struct IsPrime<3> { static constexpr bool value = true; };

void test01() {
	int num[IsPrime<5>::value]{ 10 };	//因为编译期就已经得出结果，所以可以做数组下标
	std::cout << *num << std::endl;
	std::cout << IsPrime<21>::value << std::endl;
	std::cout << IsPrime<3>::value << std::endl;
}

//使用函数编译期判断
constexpr bool doIsPrime(unsigned p, unsigned d) // p：要检查的编号，d：当前
{
	return d != 2 ? (p % d != 0) && doIsPrime(p, d - 1) // check this and smaller
		: (p % 2 != 0); // 如果除数为 2，则结束递归
}
constexpr bool isPrime(unsigned p)
{
	return p < 4 ? !(p < 2) // 处理特殊情况	如果小于4，那么1 2 3只有1不是质数，所以这样设计
		: doIsPrime(p, p / 2); // 使用除数 fromp / 2 开始递归
}

//c++14以后constexpr函数可以使用常规C++代码中大部分的控制结构，所以我们直接使用一个for循环也行
constexpr bool isPrime_(unsigned int p)
{
	for (unsigned int d = 2; d <= p / 2; ++d) {
		if (p % d == 0) {
			return false;
		}
	}
		return p > 1;
}

void test02() {
	std::cout << isPrime(21) << std::endl;
	std::cout << isPrime(3) << std::endl;

	std::cout << isPrime_(21) << std::endl;
	std::cout << isPrime_(3) << std::endl;
}
int main()
{
	//test01();	//类
	test02();	//函数
	return 0;
}