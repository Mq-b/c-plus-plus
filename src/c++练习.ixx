#include"lib/sundry.hpp"
#include"fmt/color.h"

template<auto Func, class...Args>
constexpr auto F_ = [](Args...args) {
	return Func(std::forward<Args>(args)...);
};

int main() {
	std::cout << "6666\n";
}