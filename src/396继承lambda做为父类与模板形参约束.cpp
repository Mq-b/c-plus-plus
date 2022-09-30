#include<iostream>

using Lambda = decltype([] {std::cout << "lambda\n"; });
struct overloaded : Lambda
{
	using Lambda::operator();
};

template<typename T>
struct foo : T {
	foo(T t) :T{ t } {};//同时调用了父类的构造函数
};

int main() {
	//普通继承lambda，不带捕获不用模板
	overloaded c;
	c();
	//传入lambda继承，带捕获使用模板
	int n = 10;
	auto r = foo([&n] {n += 1; std::cout << n; });
	r();

	auto c = []<std::integral T>(T n) { std::cout << n << std::endl; };
	void(*p)(char) = c;//这里调用了转换函数
	c('6');
	p(128);
	p(48);
}