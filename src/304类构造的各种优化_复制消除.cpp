#include<iostream>
#include<vector>
class Person {
public:
	Person(int i) :a(i) {
		std::cout << "有参构造" << std::endl;
	}
	Person() {
		std::cout << "默认构造" << std::endl;
	}
	void operator=(Person& n) {
		this->a = n.a;
		std::cout << "operator=" << std::endl;
	}
	Person(Person&&p) {
		this->a = p.a;
		std::cout << "移动构造" << std::endl;
	}
	int a = 0;
};

auto test()->Person&& {//这里的auto只是用作占位而已 ->指明调用谁的构造函数
	return 5;
}

int main() {
	Person a = 10;//有参构造 优化的杰作
	Person b = Person();//默认构造 优化的杰作
	std::cout << test().a << std::endl;//有参构造 优化
	//总结 对于编译器来说 【类名 对象名(参数)】 和 【类名 对象名=参数】调用的是同一个有参构造函数 是一个意思
	//且Person b = Person();这种会直接优化为默认构造
}
/*这里其实是c++11的复制消除
https://zh.cppreference.com/w/cpp/language/copy_elision*/