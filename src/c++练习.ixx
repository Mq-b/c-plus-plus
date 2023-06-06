#include <coroutine>
#include <iostream>
#include<thread>
#include<chrono>
using namespace std::literals;

struct promise;
struct coroutine : std::coroutine_handle<promise> {
	using promise_type = ::promise;
};

struct promise {
	int n;
	coroutine get_return_object()
	{
		return { coroutine::from_promise(*this) };
	}
	std::suspend_never initial_suspend() noexcept { return {}; }
	std::suspend_always final_suspend() noexcept { return {}; }
	std::suspend_always yield_value(int r) { n = r; return {}; }
	void return_void() {}
	void unhandled_exception() {}
};

template<typename T>
struct Future {
	T n;
	Future(T v) :n{ v } { puts("Future"); }
	~Future() { puts("~Future"); }
	bool await_ready() {
		return false;
	}
	void await_suspend(std::coroutine_handle<coroutine::promise_type>h) {
		std::thread thread{[this, h] {//创建异步任务
			int t = this->n;
			for (int i = 1; i < t; ++i)
				this->n *= i;
			if(!h.done())h.resume();//执行完任务之后重新启动协程
		}};
		thread.detach();
	}
	T await_resume() { return n; }
};

template<typename T>
inline auto operator co_await(const Future<T>& x) {
	std::cout << "operator co_await 被调用 X= " << x.n << '\n';
	return x;
}

coroutine f() {
	Future fu{ 5 };
	int v = co_await fu;
	std::cout << "n: " << v << '\n';

	co_yield 20;
}
int main() {
	auto result = f();
	std::cout << "main\n";
	std::this_thread::sleep_for(100ms);
	result.resume();
	std::cout << std::boolalpha << result.done() << '\n';
	std::cout << "co_yield value: " << result.promise().n << '\n';
}
//我只要暂停协程回到调用者就会析构我的局部对象