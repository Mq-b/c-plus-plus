#include<iostream>
#include<string>
//当特例化一个函数模板时，必须为原模板中的每个模板参数都提供实参。使用关键字template后跟一个空尖括号<>，即template <>，以指出我们正在特例化一个模板。
template <typename T>
void fun(T a)
{
	std::cout << "The main template fun(): " << a << std::endl;
}

template <>   // 对int型特例化
void fun(int a)
{
	std::cout << "Specialized template for int type: " << a << std::endl;
}


template <>   // 对int型特例化
void fun(int* a)
{
	std::cout << "Specialized template for int type: " << a << std::endl;
}


template<typename T,typename A>
void av1(T a, A b) {
	std::cout << a << "," << b << std::endl;
}

template<typename T>//偏特化
void av1(T a, int b)
{
	std::cout << "66666\t" << a << "," << b << std::endl;
}
int main()
{
	double a = 1.0;
	float b = 2.0f;
	int c = 3;
	fun(a);
	fun(b);
	fun(0);
	fun(&a);//也可以使用指针的特例化，当然，这个可能貌似也许更像重载
	//根据输出结果我们得以明白这个简单的函数模板特例化的作用

	//函数模板特例化就是写出一个自己要特殊处理的数据类型，自己专门的写，而不是通用模板
	
	//下面这个例子是如何使用偏特化
	av1(a, b);
	av1(c, b);
	av1(a, c);
	av1(b, c);
	//注意观察偏特化的语法即可

	return 0;
}