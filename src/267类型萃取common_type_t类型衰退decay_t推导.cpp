#include<iostream>
#include<vector>
#include<type_traits>
#include<string>
#include<algorithm>

void function() {};

auto func() ->std::vector<int> {
	return { 1,2,3,4,5,6 };
}

auto func2() {
	return std::vector<int>(10, 100);
}

template<typename T>
void demo2(T& n) {
	std::cout << typeid(std::decay_t<T>).name() << std::endl;
}

template<typename T>
void demo2_(T& n) {
	std::cout << typeid(T).name() << std::endl;
}

template<typename T>
void demo3(T& n) {
	std::cout << typeid(std::decay_t<T>).name() << std::endl;
}
template<typename T>
void demo3_(T& n) {
	std::cout << typeid(T).name() << std::endl;
}

int main() {
	int num[10]{ 0 };

	std::vector<int>test(func());
	for (auto i : test)std::cout << i << ' ';
	std::cout << std::endl;

	std::vector<int>test2(func2());
	for (auto i : test2)std::cout << i << ' ';
	std::cout << std::endl;

	std::cout << typeid(std::common_type_t<int, double, float>).name() << std::endl;
	std::cout << typeid(std::common_type_t<std::string, std::string>).name() << std::endl;

	//decay_t是	数组到指针，函数到函数指针，remove_cvref
	demo2(num);
	demo2_(num);
	//我们可以看出来打印的结果	未使用decay_t衰退的类型是int[10] 使用了的是int* 记住得使用引用才能推导
	demo3(function);
	demo3_(function);
	//和预料的情况一样 再次强调都得使用引用

	//我们一般这些东西都是推导返回类型的 我们现在写成这样只是为了说明它们的作用 不用在意
}