#include<iostream>
struct Test {
	void a(double x) {}
	void a(int x) = delete;
	template<class T>
	void f(T c){}
	
	template<>
	void f(int c) = delete;
};
void a(double x) {}
void a(int x) = delete;
int main() {
	//Test().a(10);//error
	Test().a(10.0);

	//Test().f(10);//error
	Test().f(10.0);

	//a(10)//error
	a(10.0);
}
/*这种写法很有趣且简洁，要比约束之类的更加直观，且还能作用于全局函数，成员函数重载的情况，与模板特例化的情况*/