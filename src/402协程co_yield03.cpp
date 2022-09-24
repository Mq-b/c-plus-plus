#include <coroutine>
#include <iostream>
#include <thread>

class IntReader {
public:
    bool await_ready() {
        return false;
    }

    void await_suspend(std::coroutine_handle<> handle) {

        std::thread thread([this, handle]() {

            static int seed = 0;
            value_ = ++seed;

            handle.resume();//恢复协程执行
            });

        thread.detach();
    }

    int await_resume() {//await_resume()返回类型可以是void 也可以是其它类型，它的返回值就是co_await操作符的返回值
        return value_;
    }

private:
    int value_{};
};

class Task {
public:
    class promise_type {
    public:
        Task get_return_object() {//将协程句柄返回给Task
            return Task{ std::coroutine_handle<promise_type>::from_promise(*this) };
        }

        std::suspend_always yield_value(int value) {//接收co_yield返回的数据。我们希望返回数据之后立即暂停协程，所以返回类型定义成了std::supsend_always 。
            value_ = value;                         //使用co_yield的数据并执行
            return {};
        }

        void return_void() { }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void unhandled_exception() {}

        int GetValue() const {
            return value_;
        }

    private:
        int value_{};
    };

public:
    Task(std::coroutine_handle<promise_type> handle) : coroutine_handle_(handle) {}

    int GetValue() const {
        return coroutine_handle_.promise().GetValue();
    }

    void Next() {//恢复协程执行
        coroutine_handle_.resume();//这意味着 Task 需要拿到协程的句柄，这是在 promise_type 的 get_return_object() 中传递过去的
    }

private:
    std::coroutine_handle<promise_type> coroutine_handle_;
};

Task GetInt() {

    while (true) {

        IntReader reader;
        int value = co_await reader;//让协程暂停下来，等待某个操作完成之后再恢复执行
        co_yield value;//会调用yield_value()函数，将value传入
    }
}

int main() {

    auto task = GetInt();

    std::string line;
    while (std::cin >> line) {

        std::cout << task.GetValue() << std::endl;
        task.Next();
    }
}