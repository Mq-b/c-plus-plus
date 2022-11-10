#include<new>
#include<iostream>
#include<string>
struct alignas(32) MyType32 {//如果不设置32对齐，那么默认就是4，即4+1对齐8，然后40*40 160 160+8=168
    int i;
    char c;
    std::string s[4];
};


int main() {
    auto* p = ::new(std::align_val_t(64), std::nothrow) std::string{}; // 64字节对齐
    ::operator delete(p, std::align_val_t(64), std::nothrow);

    auto* p2 = new MyType32;  // 自从C++17起分配32字节对齐的内存
    std::cout << sizeof(std::string) << ' ' << sizeof(MyType32) << ' ' << alignof(MyType32) << '\n';//40 192 32
}