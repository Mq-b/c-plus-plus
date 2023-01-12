#include<iostream>

template<size_t n>
struct factorial {
	enum {
		value = factorial<n - 1>::value * n
	};
	const int n = 10;
};
template<>
struct factorial<0> {
	enum {
		value = 1
	};
};

int main() {
	std::cout << factorial<5>::value << '\n';
}