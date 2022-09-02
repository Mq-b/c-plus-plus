#include<iostream>
/*
	聚合体 有两种：
   1. 数组类型
   2. 满足下列条件的类类型（通常是结构体（struct）或者联合体（union））：
		没有私有或保护的非静态数据成员
		没有用户提供的构造函数
		没有基类
		没有虚函数
*/

/*
	std::array 是一个聚合体

	所以其实 std::array 之所以可以使用列表初始化的原因是它是一个聚合体，也就是说 这个模板的所有成员都是 public，理论上你可以直接访问他们，
	不过C++标准没有规定 它的成员变量的名称，使用他们是未定义的行为，不具有可移植性。
*/

struct C
{
	union
	{
		int a;
		const char* p;
	};

	int x;
} c = { .a = 1, .x = 3 }; // 以 1 初始化 c.a 并且以 3 初始化 c.x


union u { int a; const char* b; };
u a = { 1 };                   // OK：显式初始化成员 a
	//u b = { 0, "asdf" };           // 错误：显式初始化两个成员
	//u c = { "asdf" };              // 错误：不能以 "asdf" 初始化 int

	// C++20 指派初始化器列表
u d = { .b = "asdf" };         // OK：可以显示初始化非开头元素
//u e = { .a = 1, .b = "asdf" }; // 错误：显式初始化两个成员


struct A { int x; int y; int z; };
//A a{ .y = 2, .x = 1 }; // 错误：指派符的顺序不匹配声明顺序
A b{ .x = 1, .z = 2 }; // OK：b.y 被初始化为 0


// 聚合体
struct base1 { int b1, b2 = 42; };

// 非聚合体
struct base2
{
	base2() : b3(42) {}

	int b3;
};

// C++17 里是聚合体
struct derived : base1, base2 { int d; };

derived d1{ {1, 2}, {}, 4 }; // d1.b1 = 1，d1.b2 = 2 ，d1.b3 = 42，d1.d = 4
derived d2 = { {}, {}, 4 };     // d2.b1 = 0，d2.b2 = 42，d2.b3 = 42，d2.d = 4


int main() {
	int n[10]{ n[0] = 1 };	//C语言的写法

	int a{};
	int b = { 10 };		//加不加 = 没区别

	std::cout << a << "," << b << std::endl;
}
/* 从初始化列表初始化聚合。它是列表初始化的一种形式。 (C++11 起) */

//C++11开始聚合初始化不需要使用 = 而是直接可以{}进行聚合初始化
//C++98的时候 {}聚合初始化 只能用作数组，结构体，联合体这些，C++11的时候就可以用作所有的基本数据类型了

//如何判断是使用的 "初始化列表" 还是 "聚合体初始化" ?
//在C++11以后 "={}" 和 直接"{}"效果完全一样 
//不管是聚合初始化还是使用std::initializer_list<T>的初始化列表，都一样

//聚合初始化只能对直接的值初始化，不能有显性的函数等 聚合体一定能聚合初始化 能聚合初始化的一定是聚合体

//我们常说的聚合体和聚合类是指一个东西，只是聚合类不包括数组，聚合类型和聚合体在文档是近义词

//强调一点，在C语言中union不是聚合类型，

/*
	Note that aggregate type does not include union type because an object with union type can only contain one member at a time.
	C++union能是聚合类型, 应该是有激活成员这个概念导致的
	c的union就没有激活成员这个概念, 所有成员的生命周期是相同的
	聚合类型：数组类型和结构体类型
*/