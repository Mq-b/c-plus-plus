#include<iostream>
int main() {
	auto lambda = [x = 0](int c) {std::cout << c << std::endl; };
	auto pLambda = std::make_shared<decltype(lambda)>(lambda);
	(*pLambda)(10);

	auto p = new auto([x = 0](int c) {std::cout << c << std::endl; });//注意这里的auto()是推导这个lambda的类型，也可以换成decltype(auto),但是在这里没什么区别
	(*p)(10);
	delete p;
}