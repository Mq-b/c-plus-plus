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

singleton* singleton::p = new singleton();//静态成员的初始化器可以访问类的私有与保护成员,所以这里可以使用new定义并初始化静态成员
int main() {
	auto a = singleton::instance();
	delete a;
}
/*单例分为两种实现方法：
	懒汉
		第一次用到类实例的时候才会去实例化
	饿汉
		单例类定义的时候就进行了实例化。*/