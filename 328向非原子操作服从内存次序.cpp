#include<iostream>
#include<thread>
#include<atomic>
#include<assert.h>

bool x(false);
std::atomic<bool>y(false);
std::atomic<int>z(0);

void write_x_then_y()noexcept {
	x = true;
	std::atomic_thread_fence(std::memory_order_release);	//设置下一行y的store为std::memory_order_release，x=true就不能重排到y的后面
	y.store(true, std::memory_order_relaxed);
}
void read_y_then_x()noexcept {
	while (!y.load(std::memory_order_relaxed));
	std::atomic_thread_fence(std::memory_order_acquire);	//设置上一行y的load为std::memory_order_acquire，设置后面的指令if(x)++z;不能被重排到while前面
	if (x)
		++z;
}

auto main()->int {
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join();
	b.join();
	assert(z.load() != 0);
}
/*和327差不多,只是表示非原子操作也可被强制执行内存次序*/