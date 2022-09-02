#include<iostream>
#include<string>
template<typename T>
class MyClass {
public:
	static constexpr int max = 1000;
};

template<typename T>
int myMax = MyClass<T>::max;
//这意味着对于一个标准库的类：
namespace std {
	template<typename T>
	class numeric_limits {
	public:
		
			static constexpr bool is_signed = false;
		
	};
}
//可以定义：
template<typename T>
constexpr bool isSigned = std::numeric_limits<T>::is_signed;
//这样就可以用：
//isSigned<char>;
//代替：
//std::numeric_limits<char>::is_signed;

int main()
{

	//应用工程师就可以使用下面这样的代码：
	auto i = myMax<std::string>;
	std::cout << i << std::endl;
	//而不是：
	//auto i = MyClass<std::string>::max;
	//std::cout << i << std::endl;
	return 0;
}