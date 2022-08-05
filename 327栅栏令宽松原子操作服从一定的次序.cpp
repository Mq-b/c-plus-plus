#include<iostream>
#include<thread>
#include<atomic>
#include<assert.h>

std::atomic<bool>x(false), y(false);
std::atomic<int>z(0);
void write_x_then_y() {
	x.store(true, std::memory_order_relaxed);	//宽松
	std::atomic_thread_fence(std::memory_order_release);	//加入释放栅栏，设置当前线程中的读或写不能被重排到此存储“后”，后面那句就是y
	y.store(true, std::memory_order_relaxed);
}
void read_y_then_x() {
	while (!y.load(std::memory_order_relaxed));	//宽松
	std::atomic_thread_fence(std::memory_order_acquire);	//获取栅栏 设置当前线程中读或写不能被重排到此加载“前”，前面那句也是y
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

/*栅栏的运作思路是:若存储操作处于释放栅栏后面，而存储操作的结果也为获取操作所见，则该释放栅栏与获取操作同步*/