#include<iostream>
template<class T>
constexpr T value{};

template<>
constexpr int value<int> = 100;//变量模板全特化版本

template<class T>
constexpr int value<T*> = 6;	//变量模板偏特化版本
int main() {
	std::cout << value<int> << std::endl;
	std::cout << value<int*> << std::endl;
	std::cout << value<double*> << std::endl;
}