#include<iostream>
#include<thread>
#include<assert.h>
#include<atomic>

std::atomic<bool>x(false), y(false);
std::atomic<int>z(0);

void write_x() {
	x.store(true, std::memory_order_seq_cst);
}

void write_y() {
	y.store(true, std::memory_order_seq_cst);		//我们无法确定前两个函数谁会先发生
}

void read_x_then_y() {
	while (!x.load(std::memory_order_seq_cst));		//如果y先执行，那么x就还是false，while是!的，那么就可以结束，执行下面的if，因为y执行了是true，那么就可以对z++
	if (y.load(std::memory_order_seq_cst))
		++z;
}

void read_y_then_x() {
	while (!y.load(std::memory_order_seq_cst));		//和上面相反，x先执行，然后y是false可结束循环，x是true，z++
	if (x.load(std::memory_order_seq_cst))
		++z;
}

int main() {
	std::thread a(write_x);	//一定是a或者b先执行，然后按顺序
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);
	a.join();
	b.join();
	c.join();
	d.join();

	assert(z.load() != 0);
	std::cout << z << std::endl;//至少为1
}
/*
	若某项操作被标记为std::memory_order_seq_cst，则编译器和CPU必须严格遵守源代码逻辑流程的先后顺序。在相同线程上，以该操作为界，其后方的任何操作不得重新编排到它前面，而前方的任何操作
	不得重新编排到它后面，其中”任何“是指带有任何内存标记的任何变量之上的任何操作
*/
/*这就是先后一致次序*/