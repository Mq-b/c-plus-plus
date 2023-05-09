#include<iostream>
struct { int max{},  min{}; } f() {
	return { 2,1 };
}

int main() {
	auto result = f();
	std::cout << result.max << ' ' << result.min << '\n';
}