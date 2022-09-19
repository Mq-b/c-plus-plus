#include<iostream>
#include<type_traits>
template<typename T>
concept Integral = std::is_integral<T>::value;//返回bool类型，根据是否为integral

template<Integral T>
T inc(T a)
{
	return ++a;
}

int main(int argc, const char* argv[])
{
	int a = 0;
	std::cout << int(a) << std::endl;
	return 0;
}
