#include<iostream>
using namespace std;
void foo(int m, int n)
{
	//异常处理
	try {
		//抛出异常
		//int t = m / n;

		//0x0000005异常
		//char* p = nullptr;
		//*p = 123;

		//人为抛出异常
		//throw 1;
		//throw 1.0f;
		//throw "Hello";

	}
	catch (int n)
	{
		//在catch块中写出你所关心的异常类型
		cout << n << endl;
		//在catch抛异常，当然一般而言不要在catch块里抛异常
		throw "123";
	}
	//三个点，表示能接收所有类型的异常
	catch (...) {
		cout << "error" << endl;
	}
}
int main(int argc, char* argv[])
{
	try {
		foo(1, argc - 1);
		//throw std::exception("hello123");
	}
	catch (std::exception& e) {
		//接住了，然后打印
		cout << e.what() << endl;
	}
	return 0;
}