#include<iostream>
#include<chrono>
#include<future>
#include<thread>
#include<experimental/generator>
using namespace std::literals;

std::mutex mtx{};
std::condition_variable cond{};
std::condition_variable cond2{};
bool flag = true;
int v{ 0 };

void func(int n) {
	for (int i = 0; i < n; ++i) {
		std::unique_lock lck{ mtx };
		cond.wait(lck, [=] {
			if (flag) { flag = false; return i == v; }
			else return false;
			});
		//std::cout << i << '\n';
		cond2.notify_all();
	}
}

void call() {
	auto start = std::chrono::steady_clock::now();
	std::thread t{func, 10000000};
	for (int i = 0; i < 10000000; ++i) {
		std::unique_lock x{ mtx };
		v = i;
		flag = true;
		cond.notify_all();
		cond2.wait(x);
	}
	t.join();
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double>(end - start) << '\n';
}
std::experimental::generator<int> coroutine(int n) {
	for (int i = 0; i < n; ++i) {
		co_yield i;
	}
}
int main() {
	call();

	auto start = std::chrono::steady_clock::now();
	for (auto i : coroutine(10000000)) {
		//std::cout << i << '\n';
	}
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double>(end - start) << '\n';
}

/*
1000万次线程切换：7.3905s 平均每次739.05ns
1000万次协程切换0.665018s
*/