#include<iostream>
struct Test {
	int a, b, c, d;
	bool operator==(const Test&) const = default;
	bool operator!=(const Test&) const = default;
	bool operator>(const Test&v1)const = default;
	auto operator<=>(const Test&) const = default;
	friend bool operator<(const Test& v1,const Test& v2) = default;

	friend bool operator<=(const Test& v1,const Test& v2) = delete;//显式删除也行，正常

};
void f(int){}
void f(double) = delete;
int main() {
	Test t{ 1,2,3,4 };
	Test t2{ 1,2,3,4 };
	std::cout << (t == t2) << std::endl;
	std::cout << (t != t2) << std::endl;
	t.c = 100;
	std::cout << (t > t2) << std::endl;
	std::cout << (t < t2) << std::endl;
}
/*
https://zh.cppreference.com/w/cpp/language/default_comparisons
详细看文档说明
*/