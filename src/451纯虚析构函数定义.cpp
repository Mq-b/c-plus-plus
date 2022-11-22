#include<iostream>
struct X {
	virtual ~X() = 0;
	virtual void f() = 0;
};

inline X::~X() {
	std::cout << "X::~X\n";
}

inline void X::f() {
	std::cout << "X::f\n";
}

struct Y :X {
	void f() {
		X::f();
	}
};
int main() {
	Y y;
	y.f();
}
/*可以为纯虚函数提供定义（而且如果纯虚函数是析构函数就必须提供）：派生类的成员函数可以自由地用有限定的函数标识调用抽象基类的纯虚函数。
此定义必须在类体之外提供（函数声明的语法不允许纯说明符 = 0 和函数体一起出现）。
从抽象类的构造函数或析构函数中进行纯虚函数的虚调用是未定义行为（无论纯虚函数是否拥有定义）。*/