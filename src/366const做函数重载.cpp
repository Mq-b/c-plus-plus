class Test {
public:
	auto operator[](int i) {
		return "operator[]";
	}
	auto operator[](int i)const {
		return "opetator[]const";
	}
};
class Test2 {
public:
	void c(){}
};

void f(const Test2& v) {
	//v[0];//error
}

#include<iostream>
int main() {
	Test a;
	const Test b;
	std::cout << a[0] << '\n' << b[0];//通过编译

	const Test2 b2;
	//b2.c();//error
}
/*之前遗漏的，const也可以做重载，且一条非常重要的概念是：const对象无法调用非const成员函数*/