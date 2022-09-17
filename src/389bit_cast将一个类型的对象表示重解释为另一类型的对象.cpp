#include <cstdint>
#include <bit>
#include <iostream>
#include<string>

constexpr double f64v = 19880124.0;
constexpr auto u64v = std::bit_cast<std::uint64_t>(f64v);

constexpr std::uint64_t u64v2 = 0xfe9000000000000ull;

constexpr auto f64v2 = std::bit_cast<double>(u64v2);

int main()
{
    /*流操作符 fixed，它表示浮点输出应该以固定点或小数点表示法显示,而不是自动变成科学计数法*/
    std::cout
        << std::fixed <<f64v << "f64.to_bits() == 0x"
        << std::hex << u64v << "u64\n";

    std::cout
        << "f64::from_bits(0x" << std::hex << u64v2 << "u64) == "
        << std::fixed << f64v2 << "f64\n";

    constexpr auto n=std::bit_cast<std::uint64_t>(9.0);//其实也能用来类型转换
    std::cout << n << std::endl;
}
/*
将一个类型的对象表示重解释为另一类型的对象表示
相信你看到这里就有疑问了，reinterpret_cast不能用吗？，它其实不一定能生成常量表达式

关于这个的作用，得对基础的IEEE754浮点格式有了解(其实我现在也忘了，以后再说)

https://zh.cppreference.com/w/cpp/numeric/bit_cast
*/