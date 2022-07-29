#include<iostream>
class Test {
public:
	enum T {
		A=-1,
		B,
		C,
		D,
		E,
		F,
		G
	};
};
void func(Test::T num) {
	
	std::cout << num << std::endl;
}
int main() {
	using a = decltype(Test::T());
	std::cout << typeid(a).name() << std::endl;
	std::cout << Test::T(100) << std::endl;
	//func(5);//error
	func(Test::T(5));
}
