#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
	fs::copy("D:/汇编语言 第四版.pdf", "D:/汇编.pdf");
}