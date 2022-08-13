#include <iostream>
#include <vector>
#include <numeric>  // for reduce()
#include <execution>

void printSum(size_t num)
{
	// 用数字序列1 2 3 4创建coll：
	std::vector<size_t> coll;
	coll.reserve(num * 4);
	for (long i = 0; i < num; ++i) {
		coll.insert(coll.end(), { 1, 2, 3, 4 });
	}

	auto sum = std::reduce(std::execution::par, coll.begin(), coll.end(), 0L);//第一个额外参数表示并行
	std::cout << "reduce():     " << sum << '\n';
}

int main()
{
	printSum(1);
	printSum(1000);
	printSum(1000000);
	printSum(10000000);
}