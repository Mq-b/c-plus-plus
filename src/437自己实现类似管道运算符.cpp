#include<iostream>
#include<vector>
#include<functional>
template<typename U, typename F>
	requires std::regular_invocable<F, U&>
std::vector<U>& operator | (std::vector<U>& vl, F f) {
	for (auto& i : vl) {
		f(i);
	}
	return vl;
}

int main() {
	std::vector v{ 1,2,3,4,5 };
	std::function f([](int& i) { i = i * i; });
	std::function f2([](int& i) {i = i + i; });
	std::function f3([](int i) {std::cout << i << ' '; });
	v | f | f2 | f3;
	std::cout << '\n';

	v | [](int& i) { i = i * i; } | [](int i) {std::cout << i << ' '; };

	std::cout << '\n';
	for (auto i : v | [](int& i) {i = i / 10; }) {
		std::cout << i << ' ';
	}
}