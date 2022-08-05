#include<iostream>
#include<string>
#include<chrono>

using namespace std::string_literals;
using namespace std::literals;	//这相当于引入所有的预定义字面量运算符

struct A {		//自定义的字面量类型，只要字面量类型里面的构造函数以constexpr修饰，且成员都是字面量类型，那么它就是字面量类型
	int i = 0;
	constexpr A(int i) :i(i) {}
};

template<std::size_t N>
struct Test {	//Test是字面量类型，因为A和char都是字面量类型，且构造函数以constexpr修饰，且构造函数无运行时代码，比如std::cout
	A a = 100;
	char p[N * 2 - 1]{};
	constexpr Test(char const(&pp)[N])//数组引用，N的值自动推导
	{
		std::ranges::copy(pp, p);//将字符串字面量拷贝给p
		std::ranges::copy(pp, p + N - 1);//再拷贝一次，拷贝到p的后方
	};
	constexpr int getN()noexcept { return N; }
};

template<Test A>//字符串字面量运算符模板只能以字面量类型作为类型，如Test
constexpr auto operator"" _x2() {
	return A.p;
}

int main() {
	auto a = "哈哈哈哈"s;
	auto b = L"哈哈哈哈"s;
	auto d = u"哈哈哈哈"s;
	auto e = u8"哈哈哈哈"s;
	auto f = U"哈哈哈哈"s;

	/*以上这些是在std::string_literals命名空间内的预定义字面量后缀运算符，推导的类型*/
	std::cout << "abc"_x2 << std::endl;	//abcabc

	Test aa("哈哈");
	std::cout << aa.getN() << std::endl;
}
/*https://zh.cppreference.com/w/cpp/language/user_literal*/