#include<iostream>
class singleton {
private:
	singleton() {}
	static singleton* p;
public:
	static singleton* instance() {
		return p;
	}
};

singleton* singleton::p = new singleton();//在定义的时候就实例化

int main() {
	auto a = singleton::instance();
	delete a;
}
/*单例分为两种实现方法：
	懒汉
		第一次用到类实例的时候才会去实例化
	饿汉
		单例类定义的时候就进行了实例化。*/