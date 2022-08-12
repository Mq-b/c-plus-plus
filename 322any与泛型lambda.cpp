#include<iostream>
#include<string>
#include<any>
#include<vector>

int main() {

	auto a = [](auto a, auto b) {return a + b; };
	a(10, 20);					//我们能直接使用a 猜测是lambda匿名类返回了自己的对象,这个匿名类没有成员变量，是空类，所以a是一个字节
	std::cout << sizeof(a) << std::endl;
	using Type = decltype(a);	//获得泛型lambda的类型 lambda是一个匿名类
	auto i = Type()(10, 20);	//这相当于直接先构造了一个对象，然后调用了operator()
	std::cout<<i<<std::endl;

	std::vector<std::any>V;
	V.push_back(a);		//将泛型lambda插入到容器中，any 类为任何可复制构造类型的单个值描述了一个类型安全的容器。

	auto ret = std::any_cast<Type>(V[0])(10, 20);						//调用泛型lambda
	auto ret2 = std::any_cast<Type>(V[0])(std::string("傻子:"), "666");	//调用泛型lambda
	std::cout << ret << std::endl;
	std::cout << ret2 << std::endl;

	V.push_back(100);	//any可以接收任何类型
	std::cout << std::any_cast<int>(V[1]) << std::endl;	//使用std::any_cast将类型转换回来即可

	int b = 0;
	double c;
	auto a = [=]() {std::cout << b << c << std::endl; };
	std::cout << sizeof a << std::endl;									//16，这不是空类，它有着捕获的成员变量，同时遵守正常的内存对齐
}
//不能对进行了捕获的lambda调用构造函数 不管是& 还是=