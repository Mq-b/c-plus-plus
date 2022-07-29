#include<ppl.h>
#include<iostream>
#include<thread>
using namespace concurrency;
int main() {
	//我们可以在parallel_invoke里面运行多个任务，每一个任务都会开启一个线程
	concurrency::parallel_invoke(
		[] {_sleep(1000); std::cout << std::this_thread::get_id() << std::endl; },
		[] {_sleep(1000); std::cout << std::this_thread::get_id() << std::endl; },
		[] {_sleep(1000); std::cout << std::this_thread::get_id() << std::endl; },
		[] {_sleep(1000); std::cout << std::this_thread::get_id() << std::endl; },
		[] {_sleep(1000); std::cout << std::this_thread::get_id() << std::endl; },
		[] {_sleep(1000); std::cout << std::this_thread::get_id() << std::endl; },
		[] {_sleep(1000); std::cout << std::this_thread::get_id() << std::endl; },
		[] {_sleep(1000); std::cout << std::this_thread::get_id() << std::endl; },
		[] {_sleep(1000); std::cout << std::this_thread::get_id() << std::endl; }
		);
}