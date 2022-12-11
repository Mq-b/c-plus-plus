#include"lib/sundry.hpp"
#include"lib/mylib.h"
void __stdcall f(int&)noexcept{}
int main() {
	std::cout << my::type_name_v<const volatile int> << '\n';
	std::cout << my::type_name_v<const volatile int&> << '\n';
	std::cout << my::type_name_v<const int&&> << '\n';
	const volatile int a = 6;
	std::cout << typeid(a).name() << '\n';
	std::cout << typeid(f).name() << '\n';
}