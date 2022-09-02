#include<iostream>
#include <vector>

template<typename Type>//思想就是非多态类型使用dynamic_cast会报错，也就是不是可行的语句，requires返回false
inline constexpr bool is_polymorphic_v =
	requires{
	dynamic_cast<const volatile void*>(static_cast<Type*>(nullptr));
};

int main() {
	auto a = is_polymorphic_v<std::exception>;
	auto b = is_polymorphic_v<std::vector<int>>;

	auto  c = std::is_polymorphic_v<std::exception>;
	auto  d = std::is_polymorphic_v<std::vector<int>>;
}