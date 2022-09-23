#include<iostream>
#include<ranges>
#include<vector>
void f(std::ranges::range auto& e) {//它一个concept，用来约束，注意这里需要使用auto&，否则会退化为指针就不满足要求
	std::cout << e[0] << std::endl;
}
int main() {
	int n[10]{10};
	f(n);
}


/*
std::ranges::range指定类型为范围，即它同时提供 begin 迭代器和 end 哨位
*/