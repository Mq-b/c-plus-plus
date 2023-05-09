#include <iostream>
#include <utility>
#include <type_traits>
#include <vector>
#include<string>

struct X {
	void* operator new  (std::size_t count, void* p, std::string s) {//可以有任意个额外参数
		std::cout << "调用自定义的布置 new" + s + '\n';
		return p;
	}
	void operator delete(void* p, void* p2, std::string s) {
		std::cout << "调用自定义的布置 delete" + s << '\n';
	}

	void* operator new(std::size_t count, std::string s) {
		std::cout << "调用自定义的布置分配new" + s + '\n';
		return ::operator new(count);
	}
	void operator delete(void* p, std::string s) {
		std::cout << "调用自定义的布置解分配delete" + s + '\n';
		::operator delete(p);
	}

	void operator delete(void* p) {//如果不写这个，连普通的delete p;这句连编译都过不了
		std::cout << "调用自定义的普通operator delete\n";
		::operator delete(p);
	}

	int n{};
	X(int v) :n{ v } { puts("构造函数"); throw std::logic_error("噶了"); }
	~X() { puts("析构函数"); }
};

int main() {
	alignas(X) char buf[sizeof(X)]{};
	//如果初始化因抛出异常而终止（例如来自构造函数），那么 new 表达式在已经分配了任何存储的情况下会调用适当的解分配函数
	try {
		auto p = new(buf, "🤣🤣")X{ 1 };
	}
	catch (const std::exception&) {}

	try {
		auto p = new("笑") X{ 1 };
	}
	catch (const std::exception&) {}

	// auto p = new("笑") X{ 1 };
	// delete p;
}
//布置new其实并不是说不分配内存，有不分配内存的布置new，但是“布置”其实只是个名字，给个参数就算布置new了。