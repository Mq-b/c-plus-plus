#include<iostream>
consteval int func() {
	return 10;
}

template<typename ...T>
consteval int sum(T... n) {
	return (... + n);
}

/*consteval*/constexpr auto func2(int a) {
	return a;
}

int main() {
	int a[func()];//OK
	auto l = []()consteval noexcept {return 7; };
	constexpr int b = l();
	constexpr int d = sum(1, 2, 3, 4, 5, 6, 7, 8, 91, 0);

	int i(0);
	std::cin >> i;
	auto ret=func2(i);//显然这是运行期得到的结果，如果修饰函数的换成consteval，那么编译都无法通过
	//constexpr int num = ret;//error
}

/*consteval - 指定函数是立即函数（immediate function），即每次调用该函数必须产生编译时常量*/
/*consteval不允许对变量或静态数据成员声明使用，不能像constexpr一样修饰变量

他们区别是，因为加了 constexpr 的函数不一定就在编译期计算完成了，也可能编译期没有计算，留到运行期计算的。它要求函数(比如你不能在函数里面写std::cout，这明显是运行期)和变量可编译期计算，
但是不要求所有调用必须都是编译期计算。修饰函数的话你可以传一个编译期不可计算的参数进去调用，这个时候就跟普通函数一样了，如果参数是编译期可计算，那么constexpr函数必然是编译期可计算的要求。

如果你要求必须要编译期计算，那可以用C++20的新关键字consteval，这个修饰的函数如果调用之后不是编译期计算出结果直接就报错。
*/