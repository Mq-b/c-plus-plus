#include<string>
#include<iostream>

int main() {
    //logic_error构造函数的字符串会显示在控制台，用throw抛出异常
    std::cout << (2 + 3 == 4 ? "OK" : throw std::logic_error("2+3!=4"));
}