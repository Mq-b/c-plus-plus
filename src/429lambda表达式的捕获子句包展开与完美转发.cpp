#include<iostream>

#include<iostream>

struct X {
	X() { puts("X"); }
	~X() { puts("~X"); }
	X(X&&)noexcept { puts("X&&"); }
	X(const X&) { puts("const X&"); }
};

template<class...Args>
void g(Args&&...args) {}

template<class... Args>
void f(Args&&... args) {
	[args...] { g(args...); }();
}

template<class... Args>
void f_(Args&&... args) {
	[... args = std::forward<Args>(args)] {g(args...); }();
}

int main() {
	X x;
	f(std::move(x));
	X x_;
	f_(std::move(x_));
}