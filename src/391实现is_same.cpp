#include<iostream>
template<class T, class T2>
struct is_same {
	static constexpr bool value = false;
};
template<class T>
struct is_same<T, T> {
	static constexpr bool value = true;
};
template<class T, class T2>
constexpr bool is_same_v = is_same<T, T2>::value;

struct Test {};
int main() {
	std::cout << is_same<int, int>::value << std::endl;
	std::cout << is_same_v<double, double> << std::endl;
	std::cout << is_same_v<Test, double> << std::endl;
}
//非常简单，只需要特例化一下即可