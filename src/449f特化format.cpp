#include<iostream>
#include<format>
#include<string>
#include <format>
#include <iostream>
#include<array>

// 类型 T 的包装
template<class T>
struct Box {
    T value;
};

// 能用被包装值的格式说明格式化包装 Box<T>
template<class T, class CharT>
struct std::formatter<Box<T>, CharT> : std::formatter<T, CharT> {
    // 从基类继承 parse()
    // 通过以被包装值调用基类实现定义 format()
    template<class FormatContext>
    auto format(Box<T> t, FormatContext& fc) {
        return std::formatter<T, CharT>::format(t.value, fc);
    }
};

// 多类型参数模板类Box2
template <typename _Ty1, typename _Ty2>
struct Box2 {
    _Ty1 value1;
    _Ty2 value2;
};

template<typename T, typename F> // (2)
inline constexpr void forEach(T&& obj, F&& f) {
    forEach(std::forward<T>(obj),
        std::forward<F>(f),
        std::make_index_sequence<std::decay_t<T>::_field_count_>{});
}
/*参数1：传递反射的对象T&& obj
参数2：一个函数f，对对象各个字段进行访问、操作，*/

// Box2的特化
template <typename _Ty1, typename _Ty2, typename _CharT>
struct std::formatter<Box2<_Ty1, _Ty2>, _CharT> : std::formatter<_Ty1, _CharT>
{	// 继承其中一个类型特化即可，前提是该类型拥有特化的格式化器
    // 若为内置类型，format库已提供，自定义类型需要自己特化
    template <typename _FormatContext>
    auto format(const Box2<_Ty1, _Ty2>& v, _FormatContext& format_context)
    {
        auto Ite = std::formatter<_Ty1, _CharT>::format(v.value1, format_context);
        Ite = ' ';
        Ite = std::formatter<_Ty2, _CharT>().format(v.value2, format_context);
        return Ite;
    }
};

int main1() {
    Box<int> v = { 42 };
    std::cout << std::format("{:#x}\n", v);
    Box2<int, double>v2{ .value1 = 66,.value2 = 66.66 };
    std::cout << std::format("{} \n", v2);
    return 0;
}