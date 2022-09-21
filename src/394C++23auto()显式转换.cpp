#include<iostream>
auto ff() {
    return auto(10);///c++23
}
int main() {
    int ret = ff();
    std::cout << ret << std::endl;
    auto v{ auto(1) + int(2) + double(3.4) + auto(5.4) };
    std::cout << v;
}
//MSVC还未实现此特性，gcc和clang可以