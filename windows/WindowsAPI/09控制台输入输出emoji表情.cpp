#include<Windows.h>
#include<iostream>
#include<filesystem>
#include<io.h>
#include<fcntl.h>
#include<string>
int main() {
	_setmode(_fileno(stdin), _O_U16TEXT);
	std::wstring l;
	std::getline(std::wcin, l);
	std::wcout << std::filesystem::path(l).string().c_str();
}