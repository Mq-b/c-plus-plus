#include<iostream>
#include<format>
#include <string>
#include<ranges>
#include<vector>
#include<fmt/color.h>

namespace stdv = std::views;
namespace stdr = std::ranges;

int main() {
	std::vector<std::string>strs{ "🐴","🤣","🐭","🥵" };

	stdr::copy(strs | stdv::reverse, std::ostream_iterator<std::string>(std::cout, " "));

	endl(std::cout);
	for (const auto& i : strs | stdv::reverse)std::cout << i << ' ';

	endl(std::cout);
	stdr::reverse_copy(strs.begin(), strs.end(), std::ostream_iterator<std::string>(std::cout, " "));

	endl(std::cout);
	fmt::print("{}\n", fmt::join(strs | std::views::reverse, " "));
}