#include <coroutine>
#include <iostream>
#include <thread>

class IntReader {
public:
    bool await_ready() {
        return false;
    }

    void await_suspend(std::coroutine_handle<> handle) {//保有一个指向协程状态的指针作为其仅有的非静态成员，而其他特化不添加任何非静态数据成员，
                                                        //从而所有特化均为可平凡复制 (TriviallyCopyable) 。
        std::thread thread([this, handle]() {

            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            value_ = std::rand();

            handle.resume();//恢复协程执行
            });

        thread.detach();//挂起
    }

    int await_resume() {//await_resume()返回类型可以是void 也可以是其它类型，它的返回值就是 co_await 操作符的返回值。当协程恢复执行，
        return value_;  //或者不需要暂停的时候，会调用这个函数
    }

private:
    int value_{};
};

class Task {
public:
    class promise_type {
    public:
        Task get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }//suspend_never 是空类，能用于指示 await 表达式绝不暂停并且不产生值。
        std::suspend_never final_suspend() noexcept { return {}; }
        void unhandled_exception() {}
        void return_void() {}
    };
};

Task PrintInt() {//在 PrintInt() 这个协程内，总共有四个线程参与了执行。这里的关键点是：哪个线程调用协程句柄的 resume() ，就由哪个线程恢复协程执行

    IntReader reader1;
    int total = co_await reader1;//让协程暂停下来

    IntReader reader2;
    total += co_await reader2;

    IntReader reader3;
    total += co_await reader3;

    std::cout << total << std::endl;
}

int main() {

    PrintInt();

    std::cin.get();
}
/*co_await 的作用是让协程暂停下来，等待某个操作完成之后再恢复执行。在上面的协程示例中，我们对 IntReader 调用了 co_await 操作符，目前这是不可行的，
因为 IntReader 是我们自定义的类型，编译器不理解它，不知道它什么时候操作完成，不知道如何获取操作结果。为了让编译器理解我们的类型，C++定义了一个协议规范，
只要我们的类型按照这个规范实现好，就可以在 co_await 使用了*/

/*await_suspend该函数的目的是用来接收协程句柄（也就是std::coroutine_handle<> 参数），并在异步操作完成的时候通过这个句柄让协程恢复执行。协程句柄类似于函数指针，
它表示一个协程实例，调用句柄上的对应函数，可以让这个协程恢复执行。*/

/*C++对协程的返回类型只有一个要求：包含名为 promise_type 的内嵌类型。跟上文介绍的 Awaitable 一样， promise_type 需要符合C++规定的协议规范，也就是要定义几个特定的函数
在协程内，我们不需要显式地创建返回值，这是由编译器隐式调用 get_return_object() 来创建并返回的。这个关系看起来比较怪异， promise_type 是返回类型的内嵌类型，
但编译器不会直接创建返回值，而是先创建一个 promise_type 对象，再通过这个对象来创建返回值。
*/