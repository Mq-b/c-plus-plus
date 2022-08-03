#include<atomic>
#include<thread>
#include<assert.h>
#include<iostream>

std::atomic<bool>x(false), y(false);
std::atomic<int>z(0);

void write_x_then_y() {
	x.store(true, std::memory_order_relaxed);		//1
	y.store(true, std::memory_order_relaxed);		//2
}

void read_y_then_x() {
	while (!y.load(std::memory_order_relaxed));			//其中即使1先于2（同一个线程保证原子执行顺序）但是在不同线程间的执行顺序是没有约束的，所以#4也有可能是false
	if (x.load(std::memory_order_relaxed))	//4
		++z;
}

int main() {
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join();
	b.join();

	assert(z.load() != 0);
}