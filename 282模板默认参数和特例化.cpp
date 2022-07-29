#include<iostream>
template<typename T=int>
class Test {
public:
	Test(T i):a{i}{}
	T getNum() {
		return a;
	}
private:
	T a;
};
template<>
class Test<void> {
public:
	void operator()() {
		std::cout << "66666666" << std::endl;
	}
};
int main() {
	int a = 10;
	Test i(110);
	std::cout << i.getNum() << std::endl;
	Test<void>()();//特例化调用
}