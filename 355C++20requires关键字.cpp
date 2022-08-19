#include<iostream>
#include<type_traits>
#include<vector>

template<typename T>
	requires true
T add(T a, T b) {
	return a + b;
}
template<typename T>
	requires std::is_integral_v<T>  //基本表达式
T add(T a, T b) {
	return a + b;
}
template<typename... Args>
	requires (std::is_integral_v<Args> && ...)   //折叠表达式 fold expression
int add(Args... a) {
	return (a + ...);
}

template<typename T>
	requires requires(T a) { ++a; }  //require表达式(这里是防止传入bool字面量)
T add2(T a) {
	return ++a;
}

template<typename T>
	requires std::is_integral_v<T> && (sizeof(T) >= 4)//可以判断多个条件
T add3(T a) {
	return ++a;
}

int main() {
	/*
	* 1.requires expression
	requires是一种表达式，它很像一个lambda表达式，一个未命名元函数，例如下面这种:

	其中：（）部分是参数列表，{ }部分是需求列表。这个表达式是在编译期求值的，表达式的结果是true或者false。它的工作机制是：对于{ }内的若干条语句检查可行性，如果都能通过，
	则本条requires expression的值为true。在本例中，a+b；是提出了需求，即：有关两个int要求能相加。显然是满足的。则本例的表达式值为true。

	这个静态断言，证明了此种表示式是编译期求值的特性
	*/
	static_assert(requires(int a, int b) { a + b; });

	//且()部分是可选的，记住我们不关心被检查的表达式的结果，只关心它是否可行
	static_assert(requires{false; });
	static_assert(requires{new int; });

	//而当我们不但要检查表达式是否可行，还要检查表达式是否抛例外，需要用到复杂需求形式。可以像这样写：
	//static_assert(requires{ (new int) noexcept; );  //ERROR

	//当我们需要表达式的值的类型符合某种要求时，这样写：
	static_assert(
		requires{ {new int} -> std::same_as<int*>;  }//std::same_as是一个约束，concept，这里是int*形参,{new int}->表示需要满足类型符合int*
	);
	

	//2.requires clause
	//C++对关键字充分榨取价值，往往一个关键字在多个场合使用。此处使用的是需求从句场合。用于限定模板函数的类型参数。
	//基本原理是，requires 之后一个常量表达式，当此表达式为true时，模板函数被选用。requires true恒成立，相当于对T没有限制。clause表达式可以使用的操作数为：1）基本表达式

	add(10.2, 20.1);
	add(10, 20, 30, 4, 05, 0, 2);
	//add2(false);  //自C++17开始，bool型无++运算，因此触发constraint报警
	//add3(short(1));///因为short长度2字节，不符合>=4字节的这条限制，故触发报警
}
//可以去看看和concept一起配合使用