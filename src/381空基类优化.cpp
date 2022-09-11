#include <cassert>
#include<iostream>

struct Base {}; // 空类

struct Derived1 : Base {
    
};
struct Derived3 : Base {
    Derived1 c; // 从 Base 派生，占用 sizeof(int) 字节
    int i;
};

struct Empty {}; // 空类

struct X {
    int i;
    [[no_unique_address]] Empty e;/*如果空成员子对象使用属性 [[no_unique_address]]，那么允许像空基类一样优化掉它们。取这种成员的地址会产生可能等于同一个对象的某个其他成员的地址*/
};
int main()
{

    std::cout << sizeof(Derived1) << std::endl;//正常的1，优化空基类

    std::cout << sizeof(Derived3) << std::endl;//正常的8，空基类优化掉，4+1，对齐就是8

    std::cout << sizeof(X) << std::endl;//文档的说法是”允许优化掉“，那么打印的是4，但MSVC并没有这么做，还是8(GCC是4)，注意这是c++20的
}
//https://zh.cppreference.com/w/cpp/language/ebo