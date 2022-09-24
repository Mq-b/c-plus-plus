/*
正如上文所说的，在一开始调用协程的时候，C++会在堆上为协程的状态分配内存，这块内存必须在适当的时机来释放，否则就会造成内存泄漏。释放协程的内存有两种方式：自动释放和手动释放。

当协程结束的时候，如果我们不做任何干预，那么协程的内存就会被自动释放。调用了 co_return 语句之后，协程就会结束

有一些协程没有写co_return，编译器也会在末尾隐式的加上

自动释放有的时候并不是我们想要的，我们看一下需要手动释放的例子
*/

#include <coroutine>
#include <iostream>
#include <thread>

class Task {
public:
    class promise_type {
    public:
        Task get_return_object() {
            return Task{ std::coroutine_handle<promise_type>::from_promise(*this) };
        }

        void return_value(int value) {
            value_ = value;
        }

        int GetValue() const {
            return value_;
        }

        std::suspend_never initial_suspend() { return {}; }//在协程刚开始执行的时候，会调用这个函数来决定是否暂停。我们可以将这个函数的返回类型改成 std::suspend_always 来让协程一执行即暂停
        std::suspend_always final_suspend() noexcept { return {}; }//修改后的，协程执行完要暂停
        void unhandled_exception() {}

    private:
        int value_{};
    };

public:
    Task(std::coroutine_handle<promise_type> handle) : coroutine_handle_(handle) {

    }

    int GetValue() const {
        return coroutine_handle_.promise().GetValue();
    }
    ~Task() {//修改后增加的，为了结束自动释放的
        coroutine_handle_.destroy();
    }
private:
    std::coroutine_handle<promise_type> coroutine_handle_;
};

Task GetInt() {
    co_return 1024;
}

int main() {

    auto task = GetInt();

    std::string line;
    while (std::cin >> line) {
        std::cout << task.GetValue() << std::endl;
    }
}
/*在这个例子中， GetInt() 协程通过 co_return 返回了1024给 promise_type ；协程返回值 Task 通过协程句柄访问 promise_type ，从中取出这个值。随着用户的输入，把这个值输出来。
运行程序，我们会发现输出的值并不是1024，而是一个随机值；也有可能会出现地址访问错误的异常。

造成这个现象的原因是，协程在返回1024之后就被自动释放了， promise_type 也跟着被一起释放了，此时在 Task 内部持有的协程句柄已经变成了野指针，指向一块已经被释放的内存。
所以访问这个协程句柄的任何行为都会造成不确定的后果。

解决这个问题的方法是，修改 promise_type 中 final_supsend() 函数的返回类型，从 std::suspend_never 改成 std::suspend_always 。协程在结束的时候，会调用 final_suspend() 来决定是否暂停，
如果这个函数返回了要暂停，那么协程不会自动释放，此时协程句柄还是有效的，可以安全访问它内部的数据。

std::suspend_never 和 std::suspend_always 。顾名思义，这两个类型分别表示“不暂停”和“要暂停
*/