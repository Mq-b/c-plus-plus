#include <iostream>
#include <sstream>
#include <string>
#include<vector>

auto main()->int {
	std::vector<int> V;
	std::string s = "10 20 30 40 50 60 70 80 100";

	std::istringstream out(s);
	int i(0);
	while (out >> i)//遍历放入容器
		V.push_back(i);

	std::ranges::copy(V, std::ostream_iterator<int>(std::cout, " "));
}