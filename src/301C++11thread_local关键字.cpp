#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>

using namespace std::literals::chrono_literals;

std::mutex MyMutex;
extern thread_local std::atomic n(0);

struct X {//本翻译单元的定义
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

/*关于这个引入静态数据成员的方式，我们需要明确一些问题:
1.ODR本身就允许类在不同翻译单元重复定义
2.类内部提供的是静态成员的声明
3.默认extern

总结来说就是，我们需要在当前翻译单元再次定义X类，但是不需要定义静态数据成员，它已经在static_data_member.cpp文件定义了，它是外部链接的，我们使用X::value的时候自然就能找到
这跟你写extern int i;没什么大区别
文档说明:https://zh.cppreference.com/w/cpp/language/definition
*/