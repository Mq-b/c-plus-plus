#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>

using namespace std::literals::chrono_literals;

std::mutex MyMutex;
extern thread_local std::atomic n(0);

struct X {//声明，用来引入X的静态数据成员
	static int value;
};

void test() {
	std::lock_guard lo(MyMutex);
	n++;
	std::cout << n << std::endl;
}
int main() {
	std::jthread a1(test);//1
	std::jthread a2(test);//1
	std::jthread a3(test);//1
	std::this_thread::sleep_for(100ms);
	std::cout << n << std::endl;//0

	std::cout << X::value << std::endl;
}
//有且只有 thread_local 关键字修饰的变量具有线程存储期(只有只有声明为 thread_local 的对象拥有此存储期)，这些变量在线程开始的时候被生成，在线程结束的时候被销毁，
//并且每一个线程都拥有一个独立的变量实例能,它能与 static 或 extern 结合，以分别指定内部或外部链接（但静态数据成员始终拥有外部链接,我们这里写了一个例子，在一个源文件static_data_member.cpp
//内定义了一个类和静态数据成员，在本文件进行声明引入，也就证明了静态数据成员拥有外部链接）。
//文档对静态数据成员的说明: https://zh.cppreference.com/w/cpp/language/static