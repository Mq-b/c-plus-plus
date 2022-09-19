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
}
//在new的时候，我们不能对表达式使用decltype，然后new，但是可以auto，比如new auto(1)
//约束这个事情，比如std::integral，这些都是c++20的concept,它要求的是返回值类型必须是int