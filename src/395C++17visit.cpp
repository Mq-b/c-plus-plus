#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

// 要观览的 variant
using var_t = std::variant<int, long, double, std::string>;

// 观览器 #3 的辅助常量
template<class> inline constexpr bool always_false_v = false;

// 观览器 #4 的辅助类型
template<class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;//把构造函数都拉进来
};
// 显式推导指引（ C++20 起不需要）
template<class... Ts> overloaded(Ts...)->overloaded<Ts...>;

int main() {
    std::vector<var_t> vec = { 10, 15l, 1.5, "hello" };
    for (auto&& v : vec) {
        // 1. void 观览器，仅为其副效应调用,会直接执行这个lambda，传入v作为参数，不接收返回值
        std::visit([](auto&& arg) {std::cout << arg; }, v);

        // 2. 返回值的观览器，返回另一 variant 的常见模式，v是传入参数，返回的是一个std::variant，值是执行完lambda后的，也就是值乘了2后的
        var_t w = std::visit([](auto&& arg) -> var_t {return arg + arg; }, v);

        std::cout << ". After doubling, variant holds ";
        // 3. 类型匹配观览器：亦能为带 4 个重载的 operator() 的类
        std::visit([](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, int>)
                std::cout << "int with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, long>)
                std::cout << "long with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, double>)
                std::cout << "double with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, std::string>)
                std::cout << "std::string with value " << std::quoted(arg) << '\n';
            else
                static_assert(always_false_v<T>, "non-exhaustive visitor!");
            }, w);
    }

    for (auto&& v : vec) {
        // 4. 另一种类型匹配观览器：有三个重载的 operator() 的类
        // 注：此情况下 '(auto arg)' 模板 operator() 将绑定到 'int' 与 'long' ，
        //    但若它不存在则 '(double arg)' operator() *亦将* 绑定到 'int' 与 'long' ，
        //    因为两者均可隐式转换成 double 。使用此形式时应留心以正确处理隐式转换。
        std::visit(overloaded{
            [](auto arg) { std::cout << arg << ' '; },
            [](double arg) { std::cout << std::fixed << arg << ' '; },//精确显示浮点
            [](const std::string& arg) { std::cout << std::quoted(arg) << ' '; },//双引号
            }, v);
    }
    std::endl(std::cout);
    auto c = overloaded{ [](int arg) { std::cout << arg << ' '; },
                         [](double arg) { std::cout << arg << ' '; },
                          [](auto arg) { std::cout << arg << ' '; } 
    };
    c(10);
    c(15.1);
    c("傻子傻子");
}
/*visit(C++17)以一或多个 variant 所保有的各实参调用所提供的函数对象 这个很简单没什么好说的
* 我们解释一下overloaded，其实这是一个c++17的特性，using 声明符序列，以前只能using一个，我们传入的lambda实际上是一个匿名类，这里使用可变参数，overloaded继承自他们
* ，这些匿名的类全部都有operator()，那么就需要一次性引入多个函数 using Ts::operator()...; 
* 我们介绍一下什么情况需要using，比如父类和子类有同名的成员函数，那么父类的默认会隐藏，如果想要它暴露的话，可以使用using，还有合并重载集的时候，也就是我们这种多继承，
* 继承的父类们是互相重载，都有operator()的，这个时候也用using
* */