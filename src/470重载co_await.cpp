#include <coroutine>
#include <iostream>

struct promise;
struct coroutine : std::coroutine_handle<promise> {
    using promise_type = ::promise;
};

struct promise {
    coroutine get_return_object()//返回值类型要求可以类型::promise_type
    {
        return { coroutine::from_promise(*this) };
    }
    std::suspend_never initial_suspend() noexcept { return {}; }//注意返回类型
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
};
struct X {
    int n;
    bool await_ready() {
        return false;
    }
    void await_suspend(std::coroutine_handle<coroutine::promise_type>h) {
        //协程暂停后跳转到哪 void返回类型是暂停后跳转到调用到调用者
    }
    int await_resume() { return 0; }//调用co_wait的返回值
};
inline auto operator co_await(X x) {//必须返回类类型
    std::cout << "operator co_await 被调用 X= " << x.n << '\n';
    return x;
}

coroutine f() {
    int v = co_await X{ 10 };
    std::cout << v << '\n';
}
int main() {
    auto result = f();
    std::cout << "main\n";
    result.resume();
}