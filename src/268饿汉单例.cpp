#include<iostream>
class Test {
public:
	int num;
	static Test* t;
private:
	Test() = default;
	Test(Test& a) = delete;
};
Test* Test::t = new Test;
int main() {
	Test* T = Test::t;
	Test* T2 = Test::t;
	std::cout << (T == T2) << std::endl;
	T->num = 10;
	std::cout << T->num << ',' << T2->num << std::endl;
	return 0;
}