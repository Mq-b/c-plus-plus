#include<bitset>
#include<iostream>

int main() {
	std::bitset<10>byte{ 0b01010101 };
	std::cout << byte << '\n';

	std::bitset<10>byte2{ "01010101" };
	std::cout << byte2 << '\n';

	std::bitset<10>byte3{ 0XA };
	std::cout << byte3 << '\n';

	byte3 |= 0b0100;
	std::cout << byte3 << '\n';

	byte2.set();//设置全部位true或设置的值
	std::cout << byte2 << '\n';

	byte2.reset();//全部位为false
	std::cout << byte2 << '\n';

	byte2.flip();//翻转全部位
	std::cout << byte2 << '\n';

	byte2[2] = false;//按位操作
	std::cout << byte2 << '\n';

	std::cout << byte2.to_string() << ' ' << byte2.to_ulong() << ' ' << byte2.to_ullong() << '\n';
}