#include <iostream>
#include<type_traits>

struct X {
	X() = default;
	X(const X&) = default;
	X(X&&) = delete;
};
X f() {
	X x;
	return x;
}

int main() {
	X x = f();
}