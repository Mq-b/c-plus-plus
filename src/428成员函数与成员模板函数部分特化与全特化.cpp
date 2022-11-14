#include<iostream>
template<class T, int I> // 主模板
struct A
{
	void f(); // 成员声明
};

template<class T, int I>
void A<T, I>::f() {}      // 主模板成员定义

// 部分特化
template<class T>
struct A<T, 2>
{
	void f();//只有声明
	void g();
	void h();
};

// 部分特化的成员
template<class T>
void A<T, 2>::g() {}

// 部分特化的成员的显式（全）特化
template<>
void A<char, 2>::h() {}

template <typename T1>
class B
{
public:
	template <typename T2>
	B(T2 v1, T2 v2)
	{
		std::cout << "A::A(T2,T2)执行了!" << std::endl;
	}

	template <typename T3, typename T4>
	void myft(T3 tmpt, T4 tmpt2)
	{
		std::cout << "myft()泛化版本" << std::endl;
		std::cout << tmpt << std::endl;
		std::cout << tmpt2 << std::endl;
	}

};

template <>
template <>
void B<int>::myft<int, float>(int tmpt, float tmpt2)
{
	std::cout << "myft(int,float)全特化版本" << std::endl;
	std::cout << tmpt << std::endl;
	std::cout << tmpt2 << std::endl;
}

int main()
{
	A<char, 0> a0;
	A<char, 2> a2;
	a0.f(); // OK，用主模板的成员定义
	a2.g(); // OK，用部分特化的成员定义
	a2.h(); // OK，用部分特化的成员的全特化定义
	//a2.f(); // 错误：部分特化 A<T, 2> 中没有 f() 的定义（没有使用主模板）

	B<int>a(6, 6);
	a.myft(6, 6.f);//类模板模板成员函数全特化
}