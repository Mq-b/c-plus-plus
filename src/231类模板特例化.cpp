#include<iostream>
template <typename T>
class Test {
public:
	void print() {
		std::cout << "General template object" << std::endl;
	}
};

template<>   // 对int型特例化
class Test<int> {
public:
	void print() {
		std::cout << "Specialized template object" << std::endl;
	}
};

template<typename T,typename A>
class Test2 {
public:
	void print() {
		std::cout << "111111" << std::endl;
	}
};

template<typename T>
class Test2<T,int> {
public:
	void print() {
		std::cout << "666666" << std::endl;
	}
};
int main()
{
	Test<int> a;
	Test<char> b;
	Test<float> c;
	a.print();//Specialized template object
	b.print();//General template object
	c.print();//General template object
	//这是一个简单的例子，可以看出这里和函数模板特例化也没啥大区别，这些都是特化为绝对类型

	//我们写一个偏特化的类模板
	Test2<double,float>v1;//111111
	Test2<double, int>v2;//666666
	v1.print();
	v2.print();
	return 0;
}
//引用，指针等方式我们不再赘述