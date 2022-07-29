#include<iostream>
#include<string>

int main()
{
	using ArrayInt = std::basic_string<int>;
	ArrayInt num(10,2);
	for (auto i : num)
		std::cout << i << ' ';
	std::endl(std::cout);
	std::cout << num[0] << std::endl;
}