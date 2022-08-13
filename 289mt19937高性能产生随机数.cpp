#include <random>
#include <iostream>
#include<Windows.h>

int main() {
	std::mt19937 rand(time(0));
	for (int i = 0; i < 10; i++)
		std::cout << rand() << std::endl;
}
//此方式生成的随机数无法设置范围