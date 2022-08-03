#include<iostream>
#include<atomic>
#include<thread>
std::atomic<int>x(0), y(0), z(0);
std::atomic<bool>go(false);
constexpr static unsigned loop_count = 10;

struct read_values {
	int x, y, z;
};
read_values values1[loop_count];
read_values values2[loop_count];
read_values values3[loop_count];
read_values values4[loop_count];
read_values values5[loop_count];

void increment(std::atomic<int>* var_to_inc, read_values* values) {	//写
	while (!go)		//自旋以等待信号
		std::this_thread::yield();//让当前线程让出时间片，而不是一直在这里循环等着，很好的降低CPU的占用时间	此函数的准确性为依赖于实现，特别是使用中的 OS 调度器机制和系统状态。
	for (size_t i = 0; i < loop_count; i++) {
		values[i].x = x.load(std::memory_order_relaxed);
		values[i].y = y.load(std::memory_order_relaxed);
		values[i].z = z.load(std::memory_order_relaxed);
		var_to_inc->store(i + 1, std::memory_order_relaxed);
		std::this_thread::yield();
	}
}

void read_vals(read_values* values) {	//读
	while (!go)		//自旋锁以等待信号
		std::this_thread::yield();
	for (size_t i = 0; i < loop_count; i++) {
		values[i].x = x.load(std::memory_order_relaxed);
		values[i].y = y.load(std::memory_order_relaxed);
		values[i].z = z.load(std::memory_order_relaxed);
		std::this_thread::yield();
	}
}

void print(read_values* v) {
	for (size_t i = 0; i < loop_count; i++) {
		if (i)
			std::cout << ",";
		std::cout << "(" << v[i].x << "," << v[i].y << "," << v[i].z << ")";
	}
	std::endl(std::cout);
}

int main() {
	std::thread t1(increment, &x, values1);
	std::thread t2(increment, &y, values2);
	std::thread t3(increment, &z, values3);
	std::thread t4(read_vals, values4);
	std::thread t5(read_vals, values5);
	go = true;			//主循环的触发信号.
	t5.join();
	t4.join();
	t3.join();
	t2.join();
	t1.join();
	print(values1);
	print(values2);
	print(values3);
	print(values4);
	print(values5);
}
//五个线程共同操作三个原子变量