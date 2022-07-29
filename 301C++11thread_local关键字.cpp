#include<iostream>
#include<thread>
#include<atomic>
void test() {
	thread_local std::atomic n(0);
	n++;
	std::cout << n << std::endl;
}
int main() {
	std::jthread a1(test);
	std::jthread a2(test);
	std::jthread a3(test);
}
/*有且只有 thread_local 关键字修饰的变量具有线程（thread）周期，这些变量在线程开始的时候被生成，在线程结束的时候被销毁，并且每一个线程都拥有一个独立的变量实例*/
//所以打印了三个1,不管是类，还是基本数据类型都一样