#include <concepts>
#include <iostream>
#include <type_traits>

constexpr std::floating_point auto x2(std::floating_point auto x) {
    return x + x;
}

constexpr std::integral auto x2(std::integral auto x) {
    return x << 1;
}

//我们回忆一下concept配合普通模板使用
template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>//其实也就是用concept修饰了模板的类型,既要求插入参数满足要求，也要求了返回值满足要求
T inc(T a)
{
    return a+=10;
}

int main() {
    constexpr auto d = x2(1.1);
    static_assert(std::is_same_v<double const, decltype(d)>);
    std::cout << d << '\n';

    constexpr auto f = x2(2.2f);
    static_assert(std::is_same_v<float const, decltype(f)>);
    std::cout << f << '\n';

    constexpr auto i = x2(444);
    static_assert(std::is_same_v<int const, decltype(i)>);
    std::cout << i << '\n';

    //constexpr auto ret=x2("c");//error

    inc(10);
    //inc(5.);
}
//std::floating_point是一个内建的concept约束，要求传入的参数必须是浮点数,传出的参数也是