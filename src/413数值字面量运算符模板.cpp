#include<iostream>
#include<string>
#include<initializer_list>

template<char... chars>
std::string operator "" _x()
{
	return { chars... };
}

template<char... chars>
double operator "" _v()
{
	return (... + static_cast<double>(chars - '0'));
}

int main() {
	std::cout << 100_x << std::endl;
	std::cout << 1234567_v << std::endl;
}