#include<iostream>
#include<atomic>
#include<thread>
#include<vector>

class spinlock_mutex {
	std::atomic_flag flag;
public:
	spinlock_mutex() {}	//C++20之前必须使用ATOMIC_FLAG_INIT这个宏对std::atomic_flag进行初始化，C++20后这个宏被废弃且不再有意义
	void lock() {
		while (flag.test_and_set(std::memory_order_acquire));	// 获得锁 (test_and_set为设置当前flag为true，并返回lock设置之前的值)
	}
	void unlock() {
		flag.clear(std::memory_order_release);					// 释放锁 (clear为设置flag的值为false,那么lock函数的while循环也就结束了，相当于解锁)
	}
};
/*test_and_set	原子地设置其为true，并返回其先前值

clear	原子地设置其标志为false

*/
/*自旋锁的定义：当一个线程尝试去获取某一把锁的时候，如果这个锁此时已经被别人获取(占用)，那么此线程就无法获取到这把锁，该线程将会等待，间隔一段时间后会再次尝试获取。这种采用循环加锁 -> 等待的机制被称为自旋锁*/
/*我们当前就是写了一个自旋锁的类*/

spinlock_mutex f;
void test() {
	static int n = 0;
	f.lock();
	std::cout << ++n << std::endl;
	f.unlock();
}
int main()
{
	std::vector<std::thread>Threads;
	for (int i = 0; i < 10; i++)
		Threads.emplace_back(test);
	for (auto& i : Threads)
		i.join();
}