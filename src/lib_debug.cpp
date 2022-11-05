#include"lib/mylib.h"

struct X {
	X() { puts("X"); }
	~X() { puts("~X"); }
};

static int ff(int a) {
	fmt::print("{} \n", a);
	return a;
}

void f1(X&&);
void f2(X&&);
void f3(X&&);
void f4(X&&);

static void f(X&& x) {
	std::cout << &x << '\n';
	f1(my::forward<X>(my::move(x)));
}
static void f1(X&& x) {
	std::cout << &x << '\n';
	f2(my::forward<X>(x));
}
static void f2(X&& x) {
	std::cout << &x << '\n';
	f3(my::forward<X>(x));
}
static void f3(X&& x) {
	std::cout << &x << '\n';
	f4(my::forward<X>(x));
}
static void f4(X&& x) {
	std::cout << &x << '\n';
}

struct Test {
	constexpr Test()noexcept = default;

	void Test_max_min_bind_sum() {
		fmt::print("{} \n", my::max(1, 2, 3, 4));
		fmt::print("{} \n", my::min(1, 2, 3, 4));

		fmt::print("{} \n", my::min(10.2, 2.9, 3.9, 4));
		constexpr auto N = my::min(10.2, 2, 3.9, 4);

		fmt::print("{} \n", my::max(10.2, 2.9, 3.9, 4));
		constexpr auto N2 = my::max(10.2, 2, 3.9, 4);

		fmt::print("{} \n", my::sum(1.1, 2));

		std::function F = ff;
		auto p = my::bind(F, 1);
		p();

		auto p2 = my::bind(ff, 10);
		p2();

		//可以传递带捕获的lambda
		auto p3 = my::bind([=](int v) {return ff(v); }, 10);
		p3();
	}

	void Test_forward() {
		f(X());
	}

};

int main() {
	Test t;
	t.Test_max_min_bind_sum();
	t.Test_forward();
}