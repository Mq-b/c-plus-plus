#include"lib/sundry.hpp"
#include<numbers>

void f(int n) {
	std::cout << n << '\n';
}

int main() {
	Call(f, int)(1);
}