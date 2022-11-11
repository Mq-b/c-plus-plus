#include"lib//mylib.h"
#include<iostream>
#include<thread>
using namespace stdl;
__declspec(thread) int a = 6;//完成c++11的thread_local关键字的功能，但行为并不完全一样，GCC和clang用__thread
thread_local int b = 6;

int main() {
	std::jthread thread{ []
		{
			a = 0,b = 0;
			std::cout << a << ' ' << b << '\n';//0 0
		}
	};
	std::this_thread::sleep_for(20ms);
	std::cout << a << ' ' << b << '\n';//6 6
}