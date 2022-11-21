#include<iostream>
template<class...T>
auto f(T&&...args) {
	static auto p = { args + args... };
	return p;
}
int main() {
	auto p = f(1, 2, 3, 4, 5);
	for (const auto& i : p) {
		std::cout << i << ' ';
	}
}