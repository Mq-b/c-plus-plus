#include <compare>//提供三路比较返回的类类型
#include <iostream>
/*三路比较
三路比较运算符表达式的形式为

左操作数 <=> 右操作数
表达式返回一个对象，使得

如果 左操作数 < 右操作数，那么 (a <=> b) < 0
如果 左操作数 > 右操作数，那么 (a <=> b) > 0
而如果 左操作数 和 右操作数 相等/等价，那么 (a <=> b) == 0。
如果操作数之一是 bool 类型而另一个不是，程序非良构。

如果两个操作数均具有算术类型，或一个具有无作用域枚举类型而另一个具有整型类型，那么对各操作数应用一般算术转换，然后

如果需要进行除了从整型类型到浮点类型之外的窄化转换，那么程序非良构。
否则，如果各操作数均具有整型类型，那么运算符产出 std::strong_ordering 类型的纯右值：
如果两个操作数算术上相等则为 std::strong_ordering::equal，
如果第一操作数算术上小于第二个则为 std::strong_ordering::less
否则为 std::strong_ordering::greater。
否则，操作数均具有浮点类型，而运算符产出 std::partial_ordering 类型的纯右值。表达式 a <=> b 产出
如果 a 小于 b 则为 std::partial_ordering::less，
如果 a 大于 b 则为 std::partial_ordering::greater，
如果 a 等价于 b 则为 std::partial_ordering::equivalent（-0 <=> +0 为等价），
否则为 std::partial_ordering::unordered（NaN <=> 任何值 为无序）。
如果两个操作数都具有相同的枚举类型 E，那么运算符产出将各操作数转换到 E 的底层类型再对转换后的操作数应用 <=> 的结果。

如果至少一个操作数是指针或成员指针，那么按需应用数组到指针转换、派生类到基类指针转换、函数指针转换和限定性转换，以将它们转换到同一指针类型，且结果指针类型是对象指针类型，那么 p <=> q 返回 std::strong_ordering 类型的纯右值：

如果 p == q 则为 std::strong_ordering::equal
如果 q > p 则为 std::strong_ordering::less
如果 p > q 则为 std::strong_ordering::greater。
如果未指明这些指针值的比较（例如它们不指向同一对象或数组之中时），那么结果未指明。
否则程序非良构。*/
class Test {
	int value = 0;
public:
	Test(int v) :value{ v } {}
	int operator-(const Test&v)const {
		return this->value - v.value;
	}
};
auto operator<=>(const Test& a, const Test& b)->int {//注意：非成员运算符要求类类型或枚举类型的参数
	return (a - b) > 0 ? 1 : (a - b) < 0 ? -1 : 0;
}
int main()
{
	double foo = -0.0;
	double bar = 0.0;

	auto res = foo <=> bar;
	auto ret = 1 <=> 2;
	if (res < 0)
		std::cout << "-0 小于 0\n";
	else if (res > 0)
		std::cout << "-0 大于 0\n";
	else // (res == 0)
		std::cout << "-0 与 0 相等\n";

	std::cout << int((10<=>10)._Value) << std::endl;//其实我们看到这个_开头大写就知道不简单，这属于是编译器给std::strong_ordering内部实现的方法，我们不该使用它，知道即可，转为int只是方便打印值

	std::cout << (Test(10) <=> Test(10)) << std::endl;
	std::cout << (Test(30) <=> Test(9)) << std::endl;
	std::cout << (Test(1) <=> Test(10)) << std::endl;
}
/*
https://zh.cppreference.com/w/cpp/language/operator_comparison 三路比较
https://zh.cppreference.com/w/cpp/utility/compare/partial_ordering std::partial_ordering
*/