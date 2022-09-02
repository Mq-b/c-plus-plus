#include <tuple>
#include <iostream>
#include <array>
#include <utility>

// 调试辅助
template<typename T, T... ints>
void print_sequence(std::integer_sequence<T, ints...> int_seq)
{
    std::cout << "The sequence of size " << int_seq.size() << ": ";
    ((std::cout << ints << ' '), ...);//折叠表达式
    std::cout << '\n';
}

// 转换数组为 tuple
template<typename Array, std::size_t... I>
auto a2t_impl(const Array& a, std::index_sequence<I...>)//using index_sequence = std::integer_sequence<std::size_t, Ints...>;所以这里是保证了类型
{
    return std::make_tuple(a[I]...);
}

template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
auto a2t(const std::array<T, N>& a)
{
    return a2t_impl(a, Indices{});
}

// 漂亮地打印 tuple
template<class Ch, class Tr, class Tuple, std::size_t... Is>
void print_tuple_impl(std::basic_ostream<Ch, Tr>& os,const Tuple& t,std::index_sequence<Is...>)//这里的最后一个参数实际是std::integer_sequence<size_t,0,1,2,3>
{
    ((os  << std::get<Is>(t)<<" "), ...);
}

template<class Ch, class Tr, class... Args>//Args捕获的是元组的类型用以构造std::index_sequence_for
auto& operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t)
{
    os << "(";
    print_tuple_impl(os, t, std::index_sequence_for<Args...>{});//注意这里的for，它实际会使用sizeof...(Args...)得到参数个数然后传参
    return os << ")";
}

int main()
{
    print_sequence(std::integer_sequence<unsigned, 9, 2, 5, 1, 9, 1, 6>{});//传递模板参数创建临时对象
    print_sequence(std::make_integer_sequence<int, 20>{});//0-19，看文档
    print_sequence(std::make_index_sequence<10>{}); //这个其实就是std::make_integer_sequence用using了一下，不过模板参数是size_t
    print_sequence(std::index_sequence_for<float, std::iostream, char,int,int,int>{});//以转换任何类型参数包为同长度的下标序列，这是一个变参类，看源码

    std::array<int, 4> array = { 1,2,3,4 };
    auto tuple = a2t(array);
    static_assert(std::is_same_v<decltype(tuple),std::tuple<int, int, int, int>>);

    // 打印到 cout
    std::cout << tuple << '\n';
}
/*我们只需要这一堆辅助模板，其实都是std::integer_sequence用using出来的，有少数不同罢了*/
/*https://zh.cppreference.com/w/cpp/utility/integer_sequence
*/