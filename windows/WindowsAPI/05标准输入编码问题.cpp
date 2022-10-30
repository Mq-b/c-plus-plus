#include <iostream>
#include<Windows.h>
/*
控制台本身是支持的utf-8输入，utf-16输出，但是stdout和stdin不支持
使用Windows的API可以正常
std的则不行
*/
int main(){
    DWORD dwChars;
    TCHAR buf[64]{};
    ReadConsole(GetStdHandle(STD_INPUT_HANDLE), buf, 99, &dwChars, nullptr);
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), buf, lstrlen(buf), &dwChars, nullptr);

    //无法正确读入
    char str[64]{};
    std::cin >> str;
    std::cout << str << '\n';
}