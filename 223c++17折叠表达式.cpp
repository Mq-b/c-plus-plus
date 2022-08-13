#include<iostream>
template<typename... Args>
auto left_sub(Args&&... args) {
    return (... - args);//左折叠
}

template<typename... Args>
auto right_sub(Args&&... args) {
    return (args - ...);//右折叠
}

template<typename...Args>
auto print(Args&&...args) {
    (std::cout << ... << args) << std::endl;//打印输出的折叠表达式得使用小括号
}
int main() {
    auto a = left_sub(2, 3, 4);  // ((2 - ) -3 ) - 4) = -5
    auto b = right_sub(2, 3, 4); // (2 - (3 - 4)) = 3
    std::cout << a << "," << b << std::endl;

    print(1, 2, 3, 4, 5, 6,"哈哈哈");
}
//这种可比c++11的可变参数模板要好的多