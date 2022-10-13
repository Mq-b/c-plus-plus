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

}