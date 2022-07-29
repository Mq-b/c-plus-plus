#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	//所见即所得
	cout << R"(hello,\n
		word)";
	string str = R"(hello\4\r
	abc,mike
	hello\n)";
	cout << str;
	return 0;
}