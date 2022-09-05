#include <iostream>
#include <thread>
#include <mutex>

std::once_flag flag1, flag2;

void simple_do_once()
{
    std::call_once(flag1, []() { std::cout << "Simple example: called once\n"; });
}

void may_throw_function(bool do_throw)
{
    if (do_throw) {
        std::cout << "throw: call_once will retry\n"; 
        throw std::exception();//该调用抛异常，则传播异常给 call_once 的调用方法，并且不翻转 flag 
    }
    std::cout << "Didn't throw, call_once will not attempt again\n"; 
}

void do_once(bool do_throw)
{
    try {
        std::call_once(flag2, may_throw_function, do_throw);
    }
    catch (...) {
    }
}

int main()
{
    std::thread st1(simple_do_once);
    std::thread st2(simple_do_once);
    std::thread st3(simple_do_once);
    std::thread st4(simple_do_once);
    st1.join();
    st2.join();
    st3.join();
    st4.join();

    std::thread t1(do_once, true);
    std::thread t2(do_once, true);
    std::thread t3(do_once, false);
    std::thread t4(do_once, true);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
/*Simple example: called once
throw: call_once will retry
throw: call_once will retry
Didn't throw, call_once will not attempt again
连续调用四次simple_do_once也只打印一句话是因为 在调用 call_once 的时刻， flag 指示已经调用了 f ，则 call_once 立即返回

然后打印两次throw是因为，该调用抛异常，则传播异常给 call_once 的调用方法，并且不翻转 flag 
然后第三次调用传的参数是false，没有抛异常，就正常翻转flag，打印Didn't
第四次调用的时候发现flag指示已经调用过do_once了，那么就直接返回

https://zh.cppreference.com/w/cpp/thread/call_once
*/