#include<iostream>
struct Test {
	Test() {
		puts("构造函数");
	}
	~Test() {
		puts("析构函数");
	}
	int v = 0;
};
int main() {
	Test();/*注意 prvalue 如果不用来初始化类型相同的对象，就会隐式转换到 xvalue （此时初始化一个临时对象），甚至放着不管也会转换，造成一次构造一次析构*/
	std::cin.get();
}
/*
C++继 glvalue 可以隐式转换到 prvalue 之后，现在 prvalue 也可以隐式转换到 xvalue 了
*/