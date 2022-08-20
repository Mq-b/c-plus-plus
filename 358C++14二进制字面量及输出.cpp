#include<iostream>
#include<format>
int main() {
	auto n = 0b101010;//c++14
	std::cout << std::format("{:b}", n);//b表示二进制
}