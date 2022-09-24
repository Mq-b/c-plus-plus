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

            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            value_ = std::rand();

            handle.resume();
            });

        thread.detach();
    }

    int await_resume() {
        return value_;
    }

private:
    int value_{};
};

class Task {
public:
    class promise_type {
    public:
        promise_type() : value_(std::make_shared<int>()) {

        }

        Task get_return_object() {
            return Task{ value_ };
        }

        void return_value(int value) {//接收co_return的数据并执行
            *value_ = value;
        }

        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void unhandled_exception() {}

    private:
        std::shared_ptr<int> value_;
    };

public:
    Task(const std::shared_ptr<int>& value) : value_(value) {

    }

    int GetValue() const {
        return *value_;
    }

private:
    std::shared_ptr<int> value_;
};

Task GetInt() {

    IntReader reader1;
    int total = co_await reader1;

    IntReader reader2;
    total += co_await reader2;

    IntReader reader3;
    total += co_await reader3;

    std::cout << total << std::endl;
    co_return total;
}

int main() {

    auto task = GetInt();

    std::string line;
    while (std::cin >> line) {
        std::cout << task.GetValue() << std::endl;
    }
}
//promise_type 和 Task 之间，使用了 std::shared_ptr<int> 来共享数据。在 get_return_object() 中创建 Task 的时候，把 promise_type 里的智能指针传递了过去，
//这样它们就能访问到同一个数据。在 promise_type 的 return_value() 中写数据，然后在 Task 的 GetValue() 中读数据。