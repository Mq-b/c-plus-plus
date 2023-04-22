#include<iostream>
#include<future>
#include<future>
#include<chrono>
using namespace std::chrono_literals;

std::future<void>wait_async() {
	auto f = std::async(std::launch::async, []
		{
			std::this_thread::sleep_for(5s);
	std::cout << "async\n";
		});
	return f;//return调用移动构造返回早于局部的析构，也就是说f在析构之前就已经移动了，析构就不会再导致阻塞了
}
int main() {
	auto future = wait_async();//排除返回值优化的可能，其实这里有一个很有趣的事情
	std::cout << "hello\n";

	std::future<void>future2;
	{
		std::future<void>tmp = std::async(std::launch::async, []
			{
				std::this_thread::sleep_for(5s);
		std::cout << "局部\n";
			});
		future2 = std::move(tmp);
	}
	std::cout << "main🤣🤣🤣🤣🤣\n";
}