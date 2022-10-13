#include"Int.hpp"
using namespace mylib::literal;
int main() {
	mylib::Int<int> i(10);
	//实参依赖查找
	std::cout << i << ' ' << i << std::endl;

	std::cout << 10_int << std::endl;

	std::cout << '6'_int << std::endl;

	std::cout << 10 + i << std::endl;

	std::cout << i + 10 << std::endl;

	std::cout << i.toType<char>() + 'a' << std::endl;

	auto i2(i);

	mylib::uInt64 i3;
	std::cout << i3 << std::endl;

	std::cout << 1234_int << std::endl;
	
	mylib::Int<int>b(15);
	i.swap(b);
	std::cout << i << ' ' << b << std::endl;
}