#include <coroutine>
#include <iostream>

struct promise;
struct coroutine : std::coroutine_handle<promise>{
    using promise_type = ::promise;//需要进行有限定名字查找 需要这个别名
};

struct promise{//primise就是promise_type
    coroutine get_return_object()//返回值类型要求可以类型::promise_type
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
    S s{ 0 };
    coroutine h = s.f();
    std::cout << "乐呵\n";
    //h.resume(); // 协程恢复并执行了

}
void bad3()
{
    coroutine h = [i = 0]() -> coroutine // 一个 lambda ，同时也是个协程
    {
        std::cout << i << '\n';
        co_return;
    }(); // 立即调用
    std::cout << "乐呵\n";
    // lambda 被销毁
    std::cout << std::boolalpha << h.done() << '\n';//如果coroutine的那个函数的返回类型是suspend_never，那么这里会打印true，协程执行完毕
    h.resume(); // 释放后使用了 (anonymous lambda type)::i 被指代对象的生存期结束后恢复协程，UB，如果是suspend_never返回类型，那么这里会抛出异常
    h.destroy();
}
void good()
{
    coroutine h = [](int i) -> coroutine // i 是一个协程形参
    {
        std::cout << i;
        co_return;
    }(0);
    std::cout << "乐呵\n";//先打印这个，表示这是惰性启动的协程
    // lambda 被销毁
    h.resume(); // 没有问题， i 已经作为按值传递的参数被复制到协程帧中 不会UB，但是返回值改成suspend_never的话，和bad3()是一样的问题
    h.destroy();
}
int main() {
    bad1();
    puts("---");
    bad3();
    puts("---");
    good();
}
//使用suspend_never做initial_suspend的返回类型就会执行完协程了，即会先cout打印0
//如果将返回值改成suspend_always，那么必然先打印“乐呵”，如果不使用h.resume();让协程恢复执行，那么不会打印0
//协程只保存函数栈里的对象 不保存this