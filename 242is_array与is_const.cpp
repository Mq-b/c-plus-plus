#include<iostream>
#include<string>
template<typename T>
auto func(T& a) {
	std::cout << typeid(a).name() << " ";
	if (std::is_array<T>::value) {
		std::cout  << "是数组" << std::endl;
	}
	else
		std::cout << "不是数组" << std::endl;
}

template<typename T>
auto func2(T& v) {
	std::cout << typeid(v).name() << " ";
	if (std::is_const<T>::value) {
		std::cout << "是const" << std::endl;
	}
	else
		std::cout << "不是const" << std::endl;
}


int main()
{
	int a[5]{ 0 };
	int const a2[5]{ 0 };
	std::string str;
	std::string const str2;
	func(a);
	func(a2);
	//对于string类创建的对象，typeid没有办法区别cv限定符
	func(str);
	func(str2);
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	func2(a);
	func2(a2);
	//虽然打印的类型看起来一样，但是is_const还是能够区分是否为const
	func2(str);
	func2(str2);
	return 0;
}
