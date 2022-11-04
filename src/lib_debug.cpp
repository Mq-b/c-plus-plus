#include"lib/mylib.h"
int f(int a) {
	fmt::print("{} \n", a);
	return a;
}

int main() {
	fmt::print("{} \n", my::max(1, 2, 3, 4));
	fmt::print("{} \n", my::min(1, 2, 3, 4));

	fmt::print("{} \n", my::min(10.2, 2.9, 3.9, 4));
	constexpr auto N = my::min(10.2, 2, 3.9, 4);

	fmt::print("{} \n", my::max(10.2, 2.9, 3.9, 4));
	constexpr auto N2 = my::max(10.2, 2, 3.9, 4);

	fmt::print("{} \n", my::sum(1.1, 2));

	std::function F = f;
	auto p = my::bind(F, 1);
	p();

	auto p2 = my::bind(f, 10);
	p2();

	auto p3 = my::bind([](int v) {return f(v); }, 10);
	p3();

}