#include<iostream>
#include<vector>
#include<execution>//提供执行策略
#include<algorithm>

int main() {
	std::vector V(100, 0);
	std::for_each_n(std::execution::par, V.begin(), 20, [](auto& i) {//它也支持并行
		int n = 0;
		i = ++n;
		});

	for (auto i : V)
		std::cout << i << ' ';
	int n = 5;

}