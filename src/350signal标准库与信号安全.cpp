#include <csignal>
#include <iostream>

void signal_handler(int signal)
{
    puts("66666");
}

int main()
{
    //// 安装信号处理函数
    //std::signal(SIGINT, signal_handler);

    //忽略Ctrl+C
    std::signal(SIGINT, SIG_IGN);

    //std::raise(SIGTERM);//发送信号 sig 给程序。调用信号处理函数（用 std::signal() 函数指定）。这其实可以不写，但是Windows没有信号，所以只能这种方式调用
    while (1);//死循环，输入Ctrl+C即发送信号
}
/*
    常量	解释
    SIGTERM	发送给程序的终止请求
    SIGSEGV	非法内存访问（分段错误）
    SIGINT	外部中断，通常为用户所起始
    SIGILL	非法程序映像，例如非法指令
    SIGABRT	异常终止条件，例如为 std::abort() 所起始
    SIGFPE	错误算术运算，例如除以零

    SIG_DFL 宏。信号处理函数被设为默认信号处理函数。
    SIG_IGN 宏。忽略信号。
*/

/*

若任何信号处理函数进行任何下列操作，则行为未定义：

调用任何库函数，除了下列信号安全函数（注意，尤其是动态分配函数不是信号安全的）：
std::atomic 的成员函数和来自 <atomic> 的非成员函数，若它们所操作的原子类型是免锁的。函数 std::atomic_is_lock_free 及 std::atomic::is_lock_free 对所有原子类型信号安全。
std::signal ，以当前处理的信号的数字为首参数（异步处理函数能重注册其自身，但不能注册其他函数）。
std::numeric_limits 的函数
std::_Exit
std::abort
std::quick_exit
std::initializer_list 的成员函数及 std::begin 与 std::end 的 std::initializer_list 重载
std::forward 、 std::move 、 std::move_if_noexcept
所有来自 <type_traits> 的函数
std::memcpy 与 std::memmove
访问拥有线程存储期的对象
dynamic_cast 表达式
throw 表达式
进入 try 块，包含函数 try 块
初始化进行动态非局部初始化的静态变量（包含延迟直至首次 ODR 使用者）
等待任何有静态存储期变量的初始化完成，由于另一线程共时初始化之
*/

//上面的代码无法在Windows下运行，只能类Unix，这里需要注意一个概念，”信号安全“