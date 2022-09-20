#include<iostream>
struct X {
	 operator std::integral auto() {//这其实也是一种转换函数，转换函数不需要写返回值类型
		return 10000;
	}
};

int main() {
	double* p = new double[] {1, 2, 3}; // 创建 double[3] 类型的数组
	auto p2 = new auto('c');          // 创建单个 char 类型的对象。p 是一个 char*
	auto q = new std::integral auto(1);         // OK: q 是一个 int*
	//auto q = new std::floating_point auto(true) // 错误：不满足类型约束
	auto r = new std::pair(10, true); // OK: r 是一个 std::pair<int, bool>*

	auto r2 = new auto(X{});
	std::cout << *r2 << std::endl;
	
	X c;
	std::cout << int(c) + 1 << std::endl;
	decltype(auto) r4 = *r2;
	std::cout << int(r4) + 10 << std::endl;
}
//在new的时候，可以auto，比如new auto(1),也就是new一个int
//概念这个事情，比如std::integral，这些都是c++20的concept,它要求的是返回值类型必须是int；auto()与类型约束(就是概念)相结合，在new的文档有介绍
//  https://zh.cppreference.com/w/cpp/language/new

//operator std::integral auto(),std::integral要求返回值类型是int。另外msvc是有bug的，明明没有用explicit修饰，它不会进行隐式转换，必须显式的，
//但是如果使用cout，它又能隐式转换了，比如16行这个，如果你使用的是gcc，那么19和21行的显式转换都不需要加，可以隐式转换

//注意:转换函数模板不允许具有推导的返回值类型

//用户定义转换函数中有这方面的介绍: https://zh.cppreference.com/w/cpp/language/cast_operator