#include <type_traits>
#include <cmath>
#include <iostream>

constexpr double power(double b, int x){
    if (std::is_constant_evaluated() && !(b == 0.0 && x < 0)) {
        // 常量求值语境：使用 constexpr 友好的算法。
        if (x == 0)
            return 1.0;
        double r = 1.0, p = x > 0 ? b : 1.0 / b;
        auto u = unsigned(x > 0 ? x : -x);
        while (u != 0) {
            if (u & 1) r *= p;
            u /= 2;
            p *= p;
        }
        return r;
    }
    else {
        // 令代码生成器生成。
        return std::pow(b, double(x));
    }
}

int main(){
    // 常量表达式语句
    constexpr double kilo = power(10.0, 3);
    int n = 3;
    // 非常量表达式，因为 n 不能在常量表达式语境中转换成右值
    // 等价于 std::pow(10.0, double(n))
    double mucho = power(10.0, n);

    std::cout << kilo << " " << mucho << "\n"; // (3)
}