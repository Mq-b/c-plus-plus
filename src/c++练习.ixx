#include<iostream>
#include<ranges>
#include<vector>
#include<print>

int main() {
	std::vector<std::vector<int>>r{ {1,2},{3,4},{5,6} };
	for (auto&& [index, elem] : r | std::views::join | std::views::reverse | std::views::enumerate) {
		std::print("index: {} value: {}\n", index, elem);
	}
}