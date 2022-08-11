#include<iostream>
class Test {
public:
	enum T {
		A = -1,
		B,
		C,
		D,
		E,
		F,
		G
	};
};
void func(Test::T num) {

	if (num >= 10) {
		std::cout << num / 10 << "," << num % 10 << std::endl;
	}
}
auto operator | (Test::T a, Test::T b) {
	return Test::T(a * 10 + b);
}
int main() {
	using a = decltype(Test::T());
	std::cout << typeid(a).name() << std::endl;
	std::cout << Test::T(100) << std::endl;
	//func(5);//error
	func(Test::T(5));

	func(Test::T(9) | Test::T(5));
}
