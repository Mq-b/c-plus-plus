#include <coroutine>
#include <iostream>

struct promise;
struct coroutine : std::coroutine_handle<promise> {
    using promise_type = ::promise;//需要进行有限定名字查找 需要这个别名
};

struct promise {//primise就是promise_type
    coroutine get_return_object()//返回值类型要求可以类型::promise_type
    {
        return { coroutine::from_promise(*this) };
    }
    std::suspend_never initial_suspend() noexcept { return {}; }//注意返回类型
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
};
struct Note { int guess; };//用来协程传递值
struct Input {
    Note& _in;
    bool await_ready() {
        return false;//如果改成true，那么不会暂停协程会执行结束，那么main函数的resume()就会抛出异常
    }
    void await_suspend(std::coroutine_handle<coroutine::promise_type>h) {
        //协程暂停后跳转到哪 void返回类型是暂停后跳转到调用到调用者
    }
    int await_resume() { return _in.guess; }//调用co_wait的返回值
};

coroutine f(Note& note) {
    std::cout << note.guess << '\n';
    Input input{ note };
    int v = co_await input;
    std::cout << "co_await: " << v << '\n';
}

int main() {
    Note n{ 10 };
    auto result = f(n);
    std::cout << "main" << '\n';
    n.guess = 100;
    result.resume();
}