#include<iostream>
using namespace std;
//1、变长模板声明
template<auto...last>
class Test
{

};
//2、变长模板类定义
template<auto first, auto...last>
class Test<first, last...>
{
public:
	static const auto val = first * Test<last...>::val;
};
//边界条件
template<>
class Test<>
{
public:
	static const auto val = 1;
};
//变长模板类折叠表达式解包
template<auto... args>
struct Mul
{
	constexpr static auto value = (... * args);
};

template<auto... args>
constexpr auto Mul_ = (...*args);
//计算可变参数个数,同时打印传入的值，递归
void func() {}
template<class T, class ...argv>
void func(T num, argv...args)
{
	//cout << "num=" << sizeof...(args) << endl;
	cout << num << endl;
	func(args...);
}

int main()
{
	//cout << Test<2, 3, 4, 5>::val << endl;

	cout << Mul<5, 6, 7, 8, 10.0>::value << std::endl;

	cout << Mul_<5, 6, 7, 8, 10.0> << std::endl;

	//func(10, 1, "jjj");
	return 0;
}
//递归方式的解包一定要把出口写在模板上面