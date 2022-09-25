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

    // 错误：无法推导函数类型
    //std::cout << std::apply(add_generic, std::pair(2.0, 3.0f)) << '\n'; 

    // OK
    std::cout << std::apply([](auto first, auto second) { return first + second; }, std::pair(2.0f, 3.0f)) << '\n';//5

    // 进阶示例
    std::tuple myTuple(25, "Hello", 9.31f, 'c');
    std::cout << myTuple << '\n';
}