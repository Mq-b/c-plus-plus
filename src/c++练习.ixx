#include"lib//mylib.h"
#include<map>
#include<string>
#include<deque>
#include<Windows.h>
#include<thread>
#include<vector>

template<typename T>
struct X {
	static_assert(std::is_integral_v<T>,"???");
};
static_assert(std::is_integral_v<int>, "???");
struct S {
	int n;
	
};


int main() {
	std::deque d{ 1,2,3,4,5 };
	std::cout << d[1] << '\n';
	X<int>x;
	std::vector v{ 1,2,3 };
	std::cout << v[3];

}