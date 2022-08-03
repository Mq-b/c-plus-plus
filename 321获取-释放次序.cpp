#include<iostream>
#include<thread>
#include<atomic>
#include<assert.h>
std::atomic<bool>x(false), y(false);
std::atomic<int>z(0);

void write_x() {
	x.store(true, std::memory_order_release);
}

void write_y() {
	y.store(true, std::memory_order_release);
}

void read_x_then_y() {
	while (!x.load(std::memory_order_acquire));
	if (y.load(std::memory_order_acquire))
		++z;
}

void read_y_then_x() {
	while (!y.load(std::memory_order_acquire));
	if (x.load(std::memory_order_acquire))
		++z;
}

int main() {
	std::thread a(write_x);
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);
	a.join();
	b.join();
	c.join();
	d.join();
	assert(z.load() != 0);
	std::cout << z.load() << std::endl;
}
/* memory_order_acquire,     本线程中,所有后续的读操作必须在本条原子操作完成后执行*/
/*释放获得顺序
若线程 A 中的一个原子存储带标签 memory_order_release ，而线程 B 中来自同一变量的原子加载带标签 memory_order_acquire ，则从线程 A 的视角先发生于原子存储的所有内存写入
（非原子及宽松原子的），在线程 B 中成为可见副效应，即一旦原子加载完成，则保证线程 B 能观察到线程 A 写入内存的所有内容。*/
/*同步仅建立在释放和获得同一原子对象的线程之间。其他线程可能看到与被同步线程的一者或两者相异的内存访问顺序。*/