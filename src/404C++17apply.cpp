#include <iostream>
#include <tuple>
#include <utility>

int add(int first, int second) { return first + second; }

template<typename T>
T add_generic(T first, T second) { return first + second; }

template<typename... Ts>
std::ostream& operator<<(std::ostream& os, std::tuple<Ts...> const& theTuple)
{
    std::apply
    (
        [&os](Ts const&... tupleArgs)
        {
            os << '[';
            std::size_t n{ 0 };
            ((os << tupleArgs << (++n != sizeof...(Ts) ? ", " : "")), ...);
            os << ']';
        }, theTuple
    );
    return os;
}

int main()
{
    std::cout << std::apply(add, std::tuple(1, 2)) << '\n';//3

    // 错误：函数模板无法推导函数类型
    //std::cout << std::apply(add_generic, std::pair(2.0, 3.0f)) << '\n'; 
    //解决方案，1:转函数指针
    std::cout << std::apply(static_cast<int(*)(int, int)>(add_generic), std::pair(7, 8)) << std::endl;

    //或者直接指明std::apply的类型为具体函数类型，而非函数指针(其实指明函数指针类型也可)
    std::cout << std::apply<int(int, int)>(add_generic, std::pair(7, 8)) << std::endl;

    //最简单的方式是直接指明模板函数的类型
    std::cout << std::apply(add_generic<int>, std::pair(7, 8)) << std::endl;

    // OK
    std::cout << std::apply([](auto first, auto second) { return first + second; }, std::pair(2.0f, 3.0f)) << '\n';//5

    // 进阶示例
    std::tuple myTuple(25, "Hello", 9.31f, 'c');
    std::cout << myTuple << '\n';
}