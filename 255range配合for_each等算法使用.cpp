#include<algorithm>
#include<iostream>
#include<ranges>
#include<vector>
int main() {
	std::vector<int>i{ 1,2,3,4,5 };
	std::ranges::for_each(i, [](auto v) {std::cout << v << " "; });//利用ranges的写法
	std::cout << std::endl;
	std::for_each(i.begin(), i.end(), [](auto v) {std::cout << v << " "; });//老式写法
	return 0;
}