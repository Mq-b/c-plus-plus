#include <functional>
#include <iostream>

int minus(int a, int b) {
    return a - b;
}

struct S{
    int val;
    int minus(int arg) const noexcept { return val - arg; }
};

int main()
{
    auto fifty_minus = std::bind_front(minus, 50);
    std::cout << fifty_minus(3) << '\n';

    auto member_minus = std::bind_front(&S::minus, S{ 50 });


    std::cout << member_minus(3) << '\n';

    // 保持 noexcept 说明！
    static_assert(!noexcept(fifty_minus(3)));
    static_assert(noexcept(member_minus(3)));

    // 绑定 lambda
    auto plus = [](int a, int b) { return a + b; };
    auto forty_plus = std::bind_front(plus, 40);
    std::cout << forty_plus(7) << '\n';
}