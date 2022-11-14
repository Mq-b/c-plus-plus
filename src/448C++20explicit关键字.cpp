#include<iostream>

template<typename T>
struct S {
    T v{};
    explicit (std::is_same_v<T, int>)(operator int()) {
        std::cout << "int\n";
        return v;
    }
    explicit(std::is_same_v<T, double>) (operator double)() {
        std::cout << "double\n";
        return v;
    }
};
int main() {
    //explicit 说明符可以与常量表达式一同使用。函数在且只会在该常量表达式求值为 true 时是显式的
    S<int>s;
    std::cout << s << '\n';//int,因为operator int的explicit常量表达式为true，所以无法隐式转换，重载走double
    S<double>s2;
    std::cout << s2 << '\n';//double
}