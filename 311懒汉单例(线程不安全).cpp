#include<iostream>
class singleton {
private:
	singleton() {}
	static singleton* p;
public:
	static singleton* instance() {
		if (p == nullptr)
			p = new singleton;
		return p;
	}
};

singleton* singleton::p = nullptr;//类外定义初始化

int main() {
	auto a = singleton::instance();
	delete a;
}