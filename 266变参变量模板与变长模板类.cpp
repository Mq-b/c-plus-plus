#include<iostream>
//变长模板类折叠表达式解包
template<auto... args>
struct Mul
{
	constexpr static auto value = (... * args);
};

//变参变量模板,折叠表达式解包
template<auto... args>
constexpr auto Mul_ = (...*args);

int main() {
	std::cout << Mul<5, 6, 7, 8, 10.0>::value << std::endl;

	std::cout << Mul_<5, 6, 7, 8, 10.0> << std::endl;

	system("pause");
}