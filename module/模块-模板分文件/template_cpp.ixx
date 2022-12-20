export module lib:A;

import<iostream>;
void print(std::integral auto t) {
	std::cout << __func__ << ' ' << t << '\n';
}

void print(auto...args) {
	std::cout << "print(auto...args)\n";
	((std::cout << args << ' '), ...);
	endl(std::cout);
}