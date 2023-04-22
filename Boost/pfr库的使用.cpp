#include<iostream>
#include<string>
#include<boost/pfr/functions_for.hpp>

//C++20计算成员个数的方式
struct AnyType {
    template<typename T>
    operator T();
};
template<typename T>
consteval size_t CountMember(auto&&...Args) {
    if constexpr (!requires{T{ Args... }; }) {//不符合语法就进入分支，即Args的数量超过数据成员
        return sizeof...(Args) - 1;
    }
    else {
        return CountMember<T>(Args..., AnyType{});
    }
}

struct X {
    template<class T>
    void operator()(T& a) {
        if constexpr (std::is_same_v<T, std::string>) {
            a.append("🤣");
        }
        else a += 1;
    }
};
int main() {
    struct test {
        int f1;
        long f2;
        size_t f3;
        std::string f4;
    };
    test var{ 42, 43,44,"笑" };
    
    std::cout << boost::pfr::tuple_size_v<test> << '\n';
    std::cout << boost::pfr::get<1>(var) << '\n';
    boost::pfr::for_each_field(var, X{});
    std::cout << boost::pfr::io_fields(var) << '\n';
    std::cout << CountMember<test>() << '\n';
}