#include"lib/sundry.hpp"
//#include"lib/mylib.h"

//using namespace my::literals;
using namespace std::literals;

struct X {
	X() { puts("X"); }
	~X() { puts("~X"); }
	X(X&&) { puts("X&&"); }
	X(const X&) { puts("const X&"); }
};

int main() {
	X&& x = X();
	[x] {};
}