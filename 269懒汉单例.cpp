#include<iostream>
class Test {
public:
	int num;
	static Test* getInstance() {
		if (t == nullptr) {
			t = new Test;
		}
		return t;
	}
private:
	Test() = default;
	Test(Test& a) = delete;
	static Test* t;
};
Test* Test::t = nullptr;
int main() {
	Test* T = Test::getInstance();
	Test* T2 = Test::getInstance();
	std::cout << (T == T2) << std::endl;
	T->num = 10;
	std::cout << T->num << ',' << T2->num << std::endl;
	return 0;
}