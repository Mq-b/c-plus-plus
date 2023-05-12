#include <iostream>

int main() {
	using t = int;
	t a = 1;
	a.~t();
	std::cout << a << '\n';
	
}