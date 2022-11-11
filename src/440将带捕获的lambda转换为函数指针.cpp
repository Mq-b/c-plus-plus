#include<fmt/core.h>
#include"lib/mylib.h"

using voidfun = void();

template<typename Ty>
voidfun* lambda_(Ty lambda) {
	static auto tmp = lambda;
	return [] {tmp(); };
}

int main() {
	int num = 11;
	auto f = lambda_([&] {num = 66; });
	f();
	fmt::print("{}\n", num);
	auto ff = my::bind([&] {num = 77; });
	ff();
	fmt::print("{}\n", num);
}