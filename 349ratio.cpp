#include<iostream>
#include<ratio>
int main() {
	//1.std::ratio
	std::ratio<1, 5> r;//用来表示精确的有理分数
	std::cout << r.num << "," << r.den << std::endl;//num是分子，den是分母

	//2.两个ratio相加
	using ratio_add = std::ratio_add<std::ratio<1, 5>, std::ratio<1, 5>>;
	std::cout << "1/5 + 1/5= " << ratio_add::num << "/" << ratio_add::den << std::endl;

	//3.两个ratio相减
	using ratio_subtract = std::ratio_subtract<std::ratio<2, 5>, std::ratio<1,10>>;
	std::cout << "2/5 - 1/10= " << ratio_subtract::num << "/" << ratio_subtract::den << std::endl;

	//4.两个ratio相乘
	using ratio_multiply = std::ratio_multiply<std::ratio<2, 5>, std::ratio<1, 10>>;
	std::cout << "2/5 * 1/10= " << ratio_multiply::num << "/" << ratio_multiply::den << std::endl;
	
	//5.两个ratio相除
	using ratio_divide = std::ratio_divide<std::ratio<2, 5>, std::ratio<1, 10> > ;
	std::cout << "2/5 ÷ 1/10= " << ratio_divide::num << "/" << ratio_divide::den << std::endl;

	//6.比较两个ratio是否相等
	auto ret = std::ratio_equal_v<std::ratio<1, 5>, std::ratio<2, 10 >> ? "1/5 == 2/10\n" : "1/5 != 2/10\n";
	std::cout << ret;

	//7.比较两个ratio是否不相等
	ret = std::ratio_not_equal_v<std::ratio<3, 5>, std::ratio<2, 10 >> ? "3/5 != 2/10\n" : "3/5 == 2/10\n";
	std::cout << ret;

	//8.比较两个ratio小于
	if constexpr(std::ratio_less_v<std::ratio<23, 37>, std::ratio<57, 90>>)
		std::cout << "23/37 < 57/90\n";

	//9.比较两个ratio小于或等于
	if constexpr(std::ratio_less_equal_v<std::ratio<1, 5>, std::ratio<1, 5>>)
		std::cout << "1/5 <= 1/5\n";

	//10.比较两个ratio大于
	if constexpr (std::ratio_greater_v<std::ratio<1, 2>, std::ratio<1, 3>>)
		std::cout << "1/2 > 1/3\n";

	//11.比较两个ratio大于等于
	if constexpr (std::ratio_greater_equal_v<std::ratio<1, 5>, std::ratio<1, 5>>)
		std::cout << "1/5 >= 1/5\n";
}
//std::ratio这些行为全部都可编译期完成
//https://zh.cppreference.com/w/cpp/header/ratio