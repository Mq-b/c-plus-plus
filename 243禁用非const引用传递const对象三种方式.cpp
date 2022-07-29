#include<iostream>
#include<string>

template<typename T>
void outR(T& arg) {
	static_assert(!std::is_const<T>::value, "T is const");
	std::cout << typeid(T).name() << " not is const" << std::endl;
}

template<typename T, typename = std::enable_if_t<!std::is_const<T>::value>>
void outR2(T& arg) {
	std::cout << typeid(T).name() << " not is const" << std::endl;
}

template<typename T>
requires (!std::is_const_v<T>)
void outR3(T& arg) {
	std::cout << typeid(T).name() << " not is const" << std::endl;
}

int main()
{
	int const a{ 0 };
	int b{ 0 };
	//outR(a);	//使用静态断言产生编译错误
	outR(b);
	//outR2(a);	//使用endle_if_t禁用模板
	outR2(b);
	//outR3(a);	//使用concepts 来禁用该模板
	outR3(b);
	return 0;
}