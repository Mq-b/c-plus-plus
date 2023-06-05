#include <coroutine>
#include <iostream>
#include<thread>

struct promise;
struct coroutine : std::coroutine_handle<promise> {
	using promise_type = ::promise;
};

struct promise {
	int n;
	coroutine get_return_object()//返回值类型要求可以类型::promise_type
	{
		return { coroutine::from_promise(*this) };
	}
	std::suspend_never initial_suspend() noexcept { return {}; }//注意返回类型
	std::suspend_always final_suspend() noexcept { return {}; }
	std::suspend_always yield_value(int r) { n = r; return {}; }//co_yield()需要
	void return_void() {}
	void unhandled_exception() {}
};

template<typename T>
struct Future {
	T n;
	bool await_ready() {
		return false;
	}
	void await_suspend(std::coroutine_handle<coroutine::promise_type>h) {
		std::jthread thread{[this, &h] {h.resume(); } };//协程在子线程运行
		//协程暂停后跳转到哪 void返回类型是暂停后跳转到调用到调用者
	}
	T await_resume() { return {}; }//调用co_wait的返回值 await_resume的返回值是整个co_await表达式的结果
};

template<typename T>
inline auto operator co_await(Future<T> x) {//必须返回类类型 operator co_await的返回类型和co_await表达式没任何关系
	std::cout << "operator co_await 被调用 X= " << x.n << '\n';
	return x;//目前这个返回值没啥用,co_await的返回值送进协程调度器的,我们不会使用，目前的Future其实给调度器也没啥意义，只是表示可以这么写
}

coroutine f() {
	int v = co_await Future{ 10 };
	std::cout << "thread ID: " << std::this_thread::get_id() << '\n';//子线程ID
	std::cout << v << '\n';
	co_yield 20;
	std::cout << "thread ID: " << std::this_thread::get_id() << '\n';//主线程ID
}
int main() {
	std::cout << "main thread ID: " << std::this_thread::get_id() << '\n';
	auto result = f();
	std::cout << "main\n";
	result.resume();
	std::cout << result.promise().n << '\n';//可以通过promise()方法访问我们写的promise类的成员
	std::cout << std::boolalpha << result.done() << '\n';
}
//写模板纯属为了展示可以写模板
//https://eel.is/c++draft/expr.await#6