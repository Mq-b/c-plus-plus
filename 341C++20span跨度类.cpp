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
	//span典型实现只保有两个成员：指向 T 的指针和大小。
	//view对象，不拥有所有权，拷贝轻
	//把起始地址和长度包装在一起，避免遗漏。
}