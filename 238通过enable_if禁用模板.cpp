//从C++11 开始，通过C++标准库提供的辅助模板std::enable_if<>，可以在某些编译期条件下
//忽略掉函数模板。

#include<iostream>
#include<string>
//比如，如果函数模板foo<>的定义如下：

//template<typename T>
//typename std::enable_if<(sizeof(T) > 4)>::type
//foo() {
//}

//这一模板定义会在sizeof(T) > 4 不成立的时候被忽略掉。如果sizeof<T> > 4 成立，函数模板
//会展开成：

//template<typename T>
//void foo() {
//}

/*也就是说std::enable_if<>是一种类型萃取（type trait），它会根据一个作为其（第一个）模
板参数的编译期表达式决定其行为：
 如果这个表达式结果为true，它的type 成员会返回一个类型：
-- 如果没有第二个模板参数，返回类型是void。
-- 否则，返回类型是其第二个参数的类型。
 如果表达式结果false，则其成员类型是未定义的。根据模板的一个叫做SFINAE
（substitute failure is not an error，替换失败不是错误，将在8.4 节进行介绍）的规则，
这会导致包含std::enable_if<>表达式的函数模板被忽略掉。*/


/*但是由于将enable_if 表达式放在声明的中间不是一个明智的做法，因此使用std::enable_if<>
的更常见的方法是使用一个额外的、有默认值的模板参数：*/
template<typename T, typename = std::enable_if_t<(sizeof(T) > 4)>>
void foo() {
	std::cout << "first" << std::endl;
}
//如果sizeof(T) > 4，它会被展开成：
//template<typename T, typename = void>
//void foo() {
//}
/*如果你认为这依然不够明智，并且希望模板的约束更加明显，那么你可以用别名模板（alias
template）给它定义一个别名：*/
template<typename T>
using EnableIfSizeGreater4 = std::enable_if_t<(sizeof(T) > 4)>;
template<typename T, typename = EnableIfSizeGreater4<T>>
void foo2() {
	std::cout << "two" << std::endl;
}

int main()
{
	foo<double>();
	//foo<int>();//无效模板实例化
	foo<long long>();

	foo2<double>();
	//foo2<int>();//无效模板实例化
	foo2<long long>();

	//32行和44行的方式可以任选一种
	return 0;
}