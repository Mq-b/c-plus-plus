#include<atomic>
#include<thread>
#include<assert.h>
#include<iostream>

std::atomic<bool>x(false), y(false);
std::atomic<int>z(0);

void write_x_then_y() {
	x.store(true, std::memory_order_relaxed);
	y.store(true, std::memory_order_relaxed);
}

void read_y_then_x() {
	while (!y.load(std::memory_order_relaxed));
	if (x.load(std::memory_order_relaxed))			//有可能是直接跳到这里执行，所以断言有可能失败
		++z;
}

int main() {
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join();
	b.join();

	assert(z.load() != 0);
}
/*宽松顺序

带标签 memory_order_relaxed 的原子操作无同步操作；它们不会在共时的内存访问间强加顺序。它们只保证原子性和修改顺序一致性。

例如，对于最初为零的 x 和 y ，

// 线程 1 ：
r1 = y.load(std::memory_order_relaxed); // A
x.store(r1, std::memory_order_relaxed); // B
// 线程 2 ：
r2 = x.load(std::memory_order_relaxed); // C
y.store(42, std::memory_order_relaxed); // D

允许产生结果 r1 == 42 && r2 == 42 ，因为即使线程 1 中 A 先序于 B 且线程 2 中 C 先序于 D ，却没有制约避免 y 的修改顺序中 D 先出现于 A ，而 x 的修改顺序中 B 先出现于 C 。
D 在 y 上的副效应，可能可见于线程 1 中的加载 A ，同时 B 在 x 上的副效应，可能可见于线程 2 中的加载 C 。 */

/*说白了就是，如果使用std::memory_order_seq_cst，必须按照顺序执行的话，两个线程交叉执行的情况最好也是先执行线程2然后线程1，r1就是42，如果反过来的话，那么r1和r2都没值。
	但是如果使用memory_order_relaxed，我们就不必按照顺序执行，我们可以先执行D然后执行A，r1此时为42，然后执行B，x为42，然后执行C，r2被x赋值为了42.这句是宽松顺序
*/