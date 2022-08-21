#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> data = { 1, 2, 4, 5, 5, 6 };
	auto i = std::lower_bound(data.begin(), data.end(), 5);//返回第一个不小于5的元素位置，此算法时间复杂度是log
	std::cout << *i << std::endl;
	data.erase(i);
	std::ranges::copy(data, std::ostream_iterator<int>(std::cout, " "));
}