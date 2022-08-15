#include<iostream>
#include<string>
#include<optional>
using Value = std::string;

std::optional<Value> getMeAValue(bool i) {
    if (i) {
        return Value{ "value" };
    }
    else {
        return std::nullopt;//std::nullopt返回一个空的std::optional
    }
}
int main() {
    auto i = getMeAValue(true);
    i = "6666";//赋值
    std::cout << i.value() << std::endl;
}
//https://zh.cppreference.com/w/cpp/utility/optional