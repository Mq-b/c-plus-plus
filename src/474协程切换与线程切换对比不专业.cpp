#include<iostream>
#include<experimental/generator>
#include<chrono>
#include<future>
#include<thread>
using namespace std::literals;

std::mutex mtx{};//共用这一个锁
std::condition_variable cond{};
int v{ 0 };

void func(int n) {
	for (int i = 0; i < n; ++i) {
		std::unique_lock lck{ mtx };
		cond.wait(lck, [=] {return i == v; });
		std::cout << i << '\n';
	}
}

void call() {
	auto start = std::chrono::steady_clock::now();
	std::thread t{func, 10};
	for (int i = 0; i < 10; ++i) {
		std::this_thread::sleep_for(100ms);
		std::lock_guard x{ mtx };
		v = i;
		cond.notify_all();
	}
	t.join();
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double>(end - start) << '\n';
}

std::experimental::generator<int> coroutine(int i) {
	for (int i = 0; i < 10; ++i) {
		co_yield i;
	}
}

int main() {
	auto start = std::chrono::steady_clock::now();
	for (auto i : coroutine(10)) {
		std::cout << i << '\n';
	}
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double>(end - start) << '\n';

	call();
}