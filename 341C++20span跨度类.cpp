#include<iostream>
#include<span>
#include<vector>
#include<string>

template<typename T>
void print(std::span<T>span)noexcept {
	for (const auto& i : span)
		std::cout << i << ' ';
	std::cout << std::endl;
	std::cout << span.size() << std::endl;
}

int main() {
	std::vector v{ 1,2,3,4,5,6,7,8 };
	int n[]{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<std::string>s{ "**", "@@", "&&"};
	print<int>(v);
	print<int>(n);
	print<std::string>(s);
	//此类只是view 开销更小，它只保存数据的开始位置和长度
}