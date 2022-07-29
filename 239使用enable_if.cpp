/*通过使用enable_if<>可以解决6.2 节中关于构造函数模板的问题。
我们要解决的问题是：当传递的模板参数的类型不正确的时候（比如不是std::string 或者可
以转换成std::string 的类型），禁用如下构造函数模板：*/

//emplate<typename STR>
//Person(STR&& n);
/*为了这一目的，需要使用另一个标准库的类型萃取，std::is_convertiable<FROM, TO>。在C++17
中，相应的构造函数模板的定义如下：*/
//template<typename STR, typename =
//	std::enable_if_t<std::is_convertible_v<STR, std::string>>>
//	Person(STR&& n);
//如果STR 可以转换成std::string，这个定义会扩展成：
//template<typename STR, typename = void>
//Person(STR&& n);
#include<iostream>
#include<string>
int main()
{

	return 0;
}