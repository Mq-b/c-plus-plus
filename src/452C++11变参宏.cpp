#include<iostream>

#define showlist(...) puts(#__VA_ARGS__)
#define call(F,...) F(__VA_ARGS__);

int main() {
	showlist(1, 2, ***, 189);
	auto ret = call([](int a, int b) {return a + b; }, 10, 11);
	std::cout << ret << '\n';
}