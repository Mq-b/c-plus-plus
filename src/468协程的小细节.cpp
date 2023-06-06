#include <coroutine>
#include <iostream>

struct promise;
struct coroutine : std::coroutine_handle<promise> {
    using promise_type = ::promise;//需要进行有限定名字查找 需要这个别名
};
struct promise {//primise就是promise_type
    coroutine get_return_object()//返回类型要求可以类型::promise_type
    {
        return { coroutine::from_promise(*this) };
    }
    std::suspend_always initial_suspend() noexcept { return {}; }//注意返回类型
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
    coroutine h = S{ 0 }.f();
    //S{0}已经被销毁
    std::cout << "乐呵\n";
    std::cout << std::boolalpha << h.done() << '\n';
    h.resume(); // 协程恢复并执行了 执行cout打印i，UB
}
void bad2()
{
    coroutine h = [i = 0]() -> coroutine // 一个 lambda ，同时也是个协程
    {
        std::cout << i << '\n';
        co_return;
    }(); // 立即调用
    std::cout << "乐呵\n";
    // lambda已经被销毁
    std::cout << std::boolalpha << h.done() << '\n';
    h.resume(); // 释放后使用了 (anonymous lambda type)::i 被指代对象的生存期结束后恢复协程，UB
    h.destroy();
}
void good()
{
    coroutine h = [](int i) -> coroutine // i 是一个协程形参
    {
        std::cout << i;
        co_return;
    }(0);
    std::cout << "乐呵\n";
    std::cout << std::boolalpha << h.done() << '\n';
    // lambda已经被销毁
    h.resume(); // 没有问题，i已经作为按值传递的参数被复制到协程帧中不会UB
    h.destroy();
}
int main() {
    bad1();
    puts("---");
    bad2();
    puts("---");
    good();
}