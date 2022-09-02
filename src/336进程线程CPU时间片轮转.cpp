#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<Windows.h>

using namespace std::literals::chrono_literals;
std::mutex m;
void ff() {
	std::atomic<int> begin(clock());
	//std::this_thread::sleep_for(1ms);
	//Sleep(1);
	_sleep(1);
	std::this_thread::yield();
	std::atomic<int> end(clock());
	std::lock_guard<std::mutex>lock(m);
	std::cout << end - begin << std::endl;
}

int main() {
	int start = clock();
	std::cout << "开始: " << start << std::endl;
	std::vector<std::thread>Threads;
	for (int i = 0; i < 20; i++)
		Threads.emplace_back(ff);

	for (auto& i : Threads)
		i.join();

	std::cout << "结束: " << clock() << std::endl;
}
/*
	总有说法说CPU时间片切换至少需要十几ms，所以延时1ms也需要十几ms，实际上不是这个意思，并非一定CPU时间片轮转一轮

	CPU被设计为两个逻辑核心共用一个物理核心的硬件。OS因此能够在16个逻辑核心上，执行16个操作。

	意味着最多可以并行16个进程，16个线程。多余的还得靠CPU轮转

	CPU分配资源的最小单位是进程，进程去抢夺CPU时间片运行，然而进程内的多线程并非一定得CPU轮转，也可并行，这是都有的

*/