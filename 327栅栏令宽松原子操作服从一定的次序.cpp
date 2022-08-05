#include<iostream>
#include<thread>
#include<atomic>
#include<assert.h>

std::atomic<bool>x(false), y(false);
std::atomic<int>z(0);
void write_x_then_y() {
	x.store(true, std::memory_order_relaxed);	//宽松
	std::atomic_thread_fence(std::memory_order_release);	//加入释放栅栏，限制了原子操作前面的指令不能重排到 release 之“后”，后就是设置y，设置y的那指令为std::memory_order_release
	y.store(true, std::memory_order_relaxed);
}
void read_y_then_x() {
	while (!y.load(std::memory_order_relaxed));	//宽松
	std::atomic_thread_fence(std::memory_order_acquire);	//获取栅栏 设置当前线程中读或写不能被重排到此加载“前”，前面那句指令也就是y，设置y的指令为std::memory_order_acquire
	if (x.load(std::memory_order_relaxed))
		++z;
}
/*栅栏使得变量x的存储操作在16行之前发生，读取的必然是true*/
/*因为栅栏设置了x的存储这行代码不能重排，也就是y无法先变为true，那么while循环!false将一直为真，这个线程将无法继续往下运行。自然x的存储操作一定发生在16行之前*/

auto main()->int {
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join();
	b.join();
	assert(z.load() != 0);	//不可能触发
}


/*释放栅栏的是令变量y的存储操作不再服从memory_order_relaxed次序，改成了次序memory_order_release*/

/*获取栅栏，相当于变量y的载入操作改成了次序std::memory_order_acquire*/

/*释放和获取栅栏都相当于重新设置y的操作次序*/

void test() {
	//std::atomic_thread_fence(std::memory_order_release);		//如果将栅栏写到这里将毫无意义，因为相当于给x为std::memory_order_release，x前面没有指令，没有限制任何东西，x可以重排到y后面
	x.store(true, std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_release);	//栅栏
	y.store(true, std::memory_order_relaxed);
}

/*不要带入栅栏视角，它只是个无情的更改原子操作次序的工具*/