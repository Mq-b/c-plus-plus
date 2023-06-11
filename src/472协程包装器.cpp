#include<iostream>
#include<coroutine>
#include<string>
#include<future>

template<typename T>
struct promise;

template<typename T>
struct coroutine : std::coroutine_handle<promise<T>> {
	using promise_type = ::promise<T>;
};

template<typename T>
struct promise {
	std::future<T>future;//接异步
	std::string _str;
	int n;
	coroutine<T> get_return_object() { return { coroutine<T>::from_promise(*this) }; }
	std::suspend_never initial_suspend() noexcept { return {}; }
	std::suspend_always final_suspend() noexcept { return {}; }
	void return_value(const std::string& str) noexcept {
		_str = str;
		std::cout << str << '\n';
	}
	std::suspend_always yield_value(int n) {
		this->n = n;
		puts("yield_value()被调用");
		return {};
	}
	void unhandled_exception() {}
};
template<>//类模板特化，为了能够void
struct promise<void> {
	std::future<void>future;//接异步
	int n;
	coroutine<void> get_return_object() { return { coroutine<void>::from_promise(*this) }; }
	std::suspend_never initial_suspend() noexcept { return {}; }
	std::suspend_always final_suspend() noexcept { return {}; }
	void return_void() noexcept { puts("协程执行完毕"); }//这个函数就是我们特化的目的
	std::suspend_always yield_value(int n) {
		this->n = n;
		puts("yield_value()被调用");
		return {};
	}
	void unhandled_exception() {}
};

template<typename F, typename...Args>
struct Input {
	using R = std::invoke_result_t<F, Args...>;

	F _f;
	std::tuple<Args...>_values;

	Input(F f, Args...args) :_f{ f }, _values{ args... } {}
	constexpr bool await_ready() const noexcept {
		return false;
	}
	constexpr void await_suspend(std::coroutine_handle<promise<R>>h)const noexcept {
		h.promise().future = std::async(std::launch::async,
			[this, h] {
				if constexpr (std::is_void_v<R>) {
					std::apply([&](Args...args) {return _f(args...); }, _values);
					if (!h.done())h.resume();//恢复协程
				}
				else {
					R result = std::apply([&](Args...args) {return _f(args...); }, _values);
					if (!h.done())h.resume();//恢复协程
					return result;
				}
			});//要创建异步任务
		puts("await_suspend 执行完毕");
	}
	constexpr void await_resume()const noexcept {  }
};

coroutine<int> f() {
	std::cout << "进入协程函数f()\n";
	Input input{ [](int i) {
		std::cout << i << '\n';
		return i;
	}, 10 };

	co_await input;
	std::cout << "co_await " << '\n';

	co_yield 666;

	co_return "笑死人了惹，协程结束了";
}

coroutine<void> f2() {
	std::cout << "进入协程函数f2()\n";
	Input input{ [](const char* s) {
		std::cout << s << '\n';
	}, "乐呵" };

	co_await input;
}//承诺类型“promise<T>”未声明 "return_void" 时，从协同例程结果末尾关闭流会导致未定义的行为

int main() {
	coroutine result = f();
	std::cout << "main\n";
	result.promise().future.get();
	result.resume();//恢复yield_value
	std::cout << std::boolalpha << result.done() << '\n';

	puts("-------------------");

	coroutine result2 = f2();
	std::cout << "main\n";//有可能先打印“main”，也可能异步任务先运行完了先打印“乐呵”。
	result2.promise().future.wait();//确保异步任务执行完毕，那么会恢复协程，相当于确保协程也执行完毕了。
	std::cout << std::boolalpha << result2.done() << '\n';
}