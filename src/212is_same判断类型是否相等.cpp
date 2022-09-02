#include<iostream>
#include<type_traits>//需要头文件提供原型
#include<string>
int main()
{
	typedef int int32;
	using my_int = int;
	std::cout << std::is_same<int, int>::value << std::endl;
	std::cout << std::is_same<my_int, int32>::value << std::endl;
	std::cout << std::is_same<rsize_t, int>::value << std::endl;
	return 0;
}
