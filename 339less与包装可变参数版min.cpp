#include <functional>
#include <iostream>
#include<algorithm>

template <typename A, typename B, typename C = std::less<>>
bool fun(A a, B b, C cmp = C{})
{
	return cmp(a, b);
}

template<typename...Ts>
auto min(Ts&&... xs) {
	return std::min({ std::forward<Ts>(xs)... }, std::less<>());	//这里用不用forward都行，使用的是min的std::initializer_list重载版本，直接构造了一个
}

int main()
{
	std::cout
		<< std::boolalpha
		<< fun(1, 2) << ' ' // true
		<< fun(1.0, 1) << ' ' // false
		<< fun(1, 2.0) << ' ' // true
		<< std::less<int>{}(5, 5.6) << ' ' // false ： 5 < 5 （警告：隐式转换）
		<< std::less<double>{}(5, 5.6) << ' ' // true  ： 5.0 < 5.6
		<< std::less<int>{}(5.6, 5.7) << ' ' // false ： 5 < 5 （警告：隐式转换）
		<< std::less{}(5, 5.6) << ' ' // true  ： less<void>: 5.0 < 5.6
		<< '\n';

	std::cout << min(100, 2, 3, 4, 5, 67, 8, 9, 10) << std::endl;
}
/*
	根据std::less的源码我们可以知道它就是单纯的<比较，是operator()，一个二元谓词
*/