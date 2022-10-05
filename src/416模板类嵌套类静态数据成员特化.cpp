#include<iostream>

template<class T>
struct X {
	constexpr static int x{};
	template<class T>
	struct Y {
		constexpr static int i{};
	};
	enum Z {
		i = 0
	};
};

template<>
constexpr int X<int>::x = 100;

template<>
constexpr int X<double>::x = 666;

template<>
template<>
constexpr int X<int>::Y<int>::i = 10;

//template<>				//成员枚举的特化无法使用
//enum struct X<int>::Z {
//	i = 250
//};

int main() {
	std::cout << X<int>::x << ' ' << X<double>::x << std::endl;
	std::cout << X<int>::Y<int>::i << std::endl;
}