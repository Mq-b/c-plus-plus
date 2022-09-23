#include <iostream>
#include <fstream>
#include<filesystem>

int main() {
	std::ofstream of{ "test.txt" };
	static constexpr auto& str = U"嘿嘿归故里";
	of.write((const char*)str, sizeof(str));
	of.close();

	std::ifstream is{ "test.txt" };
	char32_t buff[sizeof(str) / sizeof(char32_t)]{};
	is.read((char*)buff, sizeof(str));
	std::cout << std::filesystem::path(buff).string();

	is.close();
}
