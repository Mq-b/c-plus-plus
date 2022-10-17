#include<iostream>
void g(int, double, float) {}

template<class... Args>
void f(Args... args)
{
	auto lm = [&args...] { return g(args...); };
	lm();
}

int main() {
	f(1, 1.0, 1.f);
}