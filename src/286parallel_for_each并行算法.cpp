#include<iostream>
#include<ppl.h>
using namespace concurrency;

class auto_timer {				//计时器
	std::chrono::system_clock::time_point start;
public:
	// start record when entering scope
	explicit auto_timer(const char* task_name = nullptr) {
		if (task_name) std::cout << task_name << " running , ";
		start = std::chrono::system_clock::now();
	}
	// end record when leaving scope
	~auto_timer() {
		auto cost = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now() - start);
		std::cout << "cost: " << double(cost.count()) / 1000000.0 << " ms" << std::endl;
	}
};

void test1() {
	std::vector<std::vector<int>>V(10, std::vector<int>());//创建1000个vector
	concurrency::parallel_for_each(V.begin(), V.end(), [](auto& i) {
		_sleep(1000);
		});
}

void test2() {
	std::vector<std::vector<int>>V(10, std::vector<int>());
	std::for_each(V.begin(), V.end(), [](auto& i) {
		_sleep(1000);
		});
}
int main() {
	{
		auto_timer timer("parallel_for_each");
		test1();
	}

	{
		auto_timer timer("对照for_each");
		test2();
	}
}
//这个并行算法用了和没用一样