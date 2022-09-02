#include<iostream>
#include<string>
/*这是一个期待已久的语言特性concepts，允许我们用它自己的简单语法来表达模板的条件或者限制。
不幸的是，尽管讨论了很久，直到C++17， concepts依然没有成为标准库的一部分。一些编译器为这
一特性提供了试验性的支持，并且concepts在C++20中成为了标准库的一部分。*/
class Person {
public:
	template<typename STR>
		requires std::is_convertible_v<STR, std::string>
	Person(STR&& n) : name(std::forward<STR>(n)) {

	}
private:
	std::string name;
};

//我们也可以将该要求指定为通用的concept：

template<typename T>
concept ConvertibleToString = std::is_convertible_v<T, std::string>;

//然后将该concept指定为要求的条件：

//template<typename STR>
//	requires ConvertibleToString<STR>
//Person(STR&& n) : name(std::forward<STR>(n))
//{
//	...
//}

//也可以这样写：

//template<ConvertibleToString STR>
//Person(STR&& n) : name(std::forward<STR>(n))
//{
//	...
//}


int main()
{

	return 0;
}
