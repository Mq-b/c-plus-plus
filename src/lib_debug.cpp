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

	struct Test_bind {
		void t(int n) {
			for (; n; n--)
				std::cout << "t\n";
		}
		void t() {
			std::cout << "重载的t\n";
		}
		void operator()(int n) {
			std::cout << n << '\n';
		}
	};

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
		std::function F2 = p;
		F2();

		auto p2 = my::bind(ff, 10);
		p2();
		std::function F3 = p2;
		F3();

		//可以传递带捕获的lambda
		auto p3 = my::bind([=](int v) {return ff(v); }, 10);
		p3();
		std::function F4 = p3;
		F4();

		Test_bind t_b;
		auto p4 = my::bind((void(Test_bind::*)(int)) & Test_bind::t, &t_b, 2);
		p4();
		std::function F5 = p4;
		F5();

		auto p5 = my::bind(Test_bind(), 2);
		p5();
		std::function F6 = p5;
		F6();
	}

	void Test_forward() {
		f(X());
	}

	void file_copy() {
		mylibf::copy(R"(D:\自用\vs的c++\c++2022_1_19\src\文件2.txt)", R"(D:\自用\vs的c++\c++2022_1_19\src\文件.txt)");
	}

};

int main() {
	Test t;
	t.Test_max_min_bind_sum();
	t.Test_forward();
	t.file_copy();
}