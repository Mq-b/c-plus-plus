#include"lib/sundry.hpp"
#include"lib/mylib.h"

struct X{
	//explicit X(std::initializer_list<int>) { LOG << "initializer_list\n"; }
	explicit  X(int a, int b) :a(a), b(b) { LOG << "X(int a,int b)\n"; }

	int a{};
	int b{};
};

int main() {
	X x{ 1,2 };
	X x2( 1,2 );
	/*using T = decltype({1,2,3})*/

	
}