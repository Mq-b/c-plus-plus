#include<iostream>
#include<random>
#include<algorithm>
#include <execution>//提供执行策略

int main() {
	std::mt19937 rand(time(0));
	std::vector V(1000, 0);
	for (auto& i : V)
		i = rand();

	std::sort(std::execution::par, V.begin(), V.end(), [](auto a, auto b) {
		return a > b;
		});

	for (auto i : V)
		std::cout << i << std::endl;
}
/*你也可以向并行STL算法传递不同的 执行策略(execution policies) 作为第一个参数。 它们定义在头文件<execution>中。 表执行策略列出了所有标准的 执行策略 。
策略 	含义
std::execution::seq 	顺序执行
std::execution::par 	并行化顺序执行
std::execution::par_unseq 	并行化乱序（矢量化）执行*/