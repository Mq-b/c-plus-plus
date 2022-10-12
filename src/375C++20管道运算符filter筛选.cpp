#include <ranges>
#include <iostream>

int main()
{
    auto const ints = { 0,1,2,3,4,5 };
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };

    // 组合视图的“管道”语法：
    for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    // 传统的“函数式”组合语法,filter是筛选，然后再用transform筛选
    for (int i : std::views::transform(std::views::filter(ints, even), square)) {
        std::cout << i << ' ';
    }
    endl(std::cout);

    auto f = std::views::transform([](int n) { return n *= n; });
    auto ret = ints | f;//并没有改变ints，只是返回一个序列
    for (auto i : ret) {
        std::cout << i << ' ';
    }
}