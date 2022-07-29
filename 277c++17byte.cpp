#include<iostream>
#include<list>
#include<vector>
int main()
{
	std::byte Byte{ 100 };
	std::cout << sizeof Byte << std::endl;
	std::cout << std::to_integer<unsigned char>(Byte) << std::endl;
	std::cout << std::to_integer<unsigned int>(~Byte) << std::endl;
}