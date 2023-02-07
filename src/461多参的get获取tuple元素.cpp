#include <fmt/ranges.h>
#include<iostream>
#include<string>
#include<tuple>
using namespace std::literals;

template<size_t...idx, typename...Args>
[[nodiscard]] constexpr decltype(auto) get(std::tuple<Args...>& t) noexcept {
	return std::forward_as_tuple(std::get<idx>(t)...);
}

int main() {
	std::tuple t{ "0"s,"1"s,"2"s,"3"s,"4"s };
	auto [a, b, c] = ::get<1, 3, 0>(t);
	a = "🐴";
	fmt::print("{} {} {}\n", std::get<1>(t), b, c);
}