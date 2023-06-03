#include <coroutine>
#include <iostream>

struct promise;
struct coroutine : std::coroutine_handle<promise>{
    using promise_type = ::promise;//需要进行有限定名字查找
};

struct promise{
    coroutine get_return_object()
    {
        return { coroutine::from_promise(*this) };
    }
    std::suspend_always initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
};

struct S {
    int i;
    coroutine f() {
        std::cout << i << '\n';
        co_return;
    }
};

void bad1() {
    S s{ 0 };
    coroutine h = s.f();
    // S{0} 被销毁
    std::cout << "乐呵\n";
    //h.resume(); // 协程恢复并执行了 std::cout << i ，这释放后使用了 S::i

}

int main() {
    bad1();
}
//使用suspend_never做initial_suspend的返回值就会先执行到co_return等待，即会先cout打印0
//如果将返回值改成suspend_always，那么必然先打印“乐呵”，如果不使用h.resume();让协程恢复执行，那么不会打印0