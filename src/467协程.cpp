#include<coroutine>
#include<iostream>
#include<format>

struct CoRet{
	struct promise_type {
		int _out;
		int _res;
		CoRet get_return_object() { return { std::coroutine_handle<promise_type>::from_promise(*this) }; }
		std::suspend_never initial_suspend() { return {}; }//suspend_never 是空类，能用于指示 await 表达式绝不暂停并且不产生值。
		std::suspend_never final_suspend() noexcept { return {}; }
		void unhandled_exception() {}
		std::suspend_always yield_value(int r) {//co_yield()需要
			_out = r;
			return {};
		}
		void return_value(int r) {//co_return()需要，如果不想co_return则可以写void_return函数
			_res = r;
		}
	};
	std::coroutine_handle<promise_type>_h;
};
struct Note{ int guess; };//用来协程传递值
struct Input{
	Note& _in;
	bool await_ready() {
		return false;//false表示需要暂停
	}
	void await_suspend(std::coroutine_handle<CoRet::promise_type>h) {//拿到协程的handle
		//协程暂停后跳转到哪 void是暂停后跳转到调用到调用者
	}
	int await_resume() { return _in.guess; }//调用co_wait的返回值
};

CoRet Guess(Note&note) {
	int res = (rand() % 30) + 1;
	Input input{note};

	int g = co_await input;//暂停，跳转回到main
	std::cout<<std::format("corutine: You guess {}\n", g);

	co_yield(res);//返回随机数值

	co_return res;//执行完这个表示协程已经执行完成,和co_yield很像
}
int main() {
	srand(time(nullptr));
	Note note{};
	auto ret = Guess(note);
	std::cout<<std::format("main: make a guess ...\n");
	note.guess = 10;
	ret._h.resume();//回到协程

	std::cout<<std::format("main: result is {}\n", ret._h.promise()._out);

	ret._h.resume();//回到协程 co_yield
	if (ret._h.done()) {//协程执行完毕
		std::cout<<std::format("main: the result is {}\n", ret._h.promise()._res);
	}
}