#include<iostream>
#include<thread>

template<typename T>
struct Test {
	static T* get() {
		static T object;
		return &object;
	}
protected:
	Test() = default;
	Test(const Test&) = default;
	Test& operator=(const Test&) = default;
};

struct X :public Test<X> {//使用继承单例

};

int main() {
	auto f = [=]<typename T>(T) {
		std::cout << X::get() << '\n';
	};
	std::jthread thread1{ f,1 };
	std::jthread thread2{ f,1 };
	std::jthread thread3{ f,1.0 };
	std::jthread thread4{ f,1.0 };
}