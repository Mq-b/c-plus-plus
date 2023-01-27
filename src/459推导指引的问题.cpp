#include<iostream>
#include<fmt/core.h>

template<class...Args>
struct X {
	X(Args&&...args) {
		(fmt::print("{} ", typeid(args).name()), ...);
		fmt::print("\n");
	}
};

template<class...Args>
X(Args...) -> X<Args...>;

template<class...Args>
void f(Args&&...args) {}

int main() {
	X x{ 1,1.2,'*' };

	int a{};
	//X x2{ a };//error

	int arr[10]{}, arr2[10]{};
	double arr3[10]{};
	X x3{ arr,arr2,arr3 };
	f(1);
	f(a);
}