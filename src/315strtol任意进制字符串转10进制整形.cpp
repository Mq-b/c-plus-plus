#include<string>
#include<iostream>

int main() {
	std::string str("648");
	auto num = strtol(str.data(), nullptr, 10);
	std::cout << num << std::endl;

	auto num2 = std::stoi(str);//对比，只能将string抓换为int
	std::cout << num2 << std::endl;

	str = "1a";
	//str = "1A";	//不在乎大小写
	num = strtol(str.data(), nullptr, 16);//strtol可以转换不同进制,第三个参数表示当前是什么进制，然后转换为对应的10进制
	std::cout << num << std::endl;
}