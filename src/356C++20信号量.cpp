#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>
using namespace std::literals;

// 全局二元信号量实例
// 设置对象计数为零
// 对象在未被发信状态
std::binary_semaphore smphSignal(0);

void ThreadProc()
{
    // 通过尝试减少信号量的计数等待来自主程序的信号
    smphSignal.acquire();

    // 此调用阻塞直至信号量的计数被从主程序增加

    std::cout << "[thread] Got the signal" << std::endl; // 回应消息

    // 等待 3 秒以模仿某种线程正在进行的工作
    std::this_thread::sleep_for(3s);

    std::cout << "[thread] Send the signal\n"; // 消息

    // 对主程序回复发信
    smphSignal.release();
}

int main()
{
    // 创建某个背景工作线程，它将长期存在
    std::jthread thrWorker(ThreadProc);

    std::cout << "[main] Send the signal\n"; // 消息

    // 通过增加信号量的计数对工作线程发信以开始工作
    smphSignal.release();

    // release() 后随 acquire() 可以阻止工作线程获取信号量，所以添加延迟：
    std::this_thread::sleep_for(50ms);

    // 通过试图减少信号量的计数等待直至工作线程完成工作
    smphSignal.acquire();

    std::cout << "[main] Got the signal\n"; // 回应消息
}
/*调用 acquire() 与相关方法减少此计数器，而它通过调用 release() 增加。计数器为零时， acquire()阻塞该计数器直至它增加，但 try_acquire() 不阻塞； 
try_acquire_for() 与 try_acquire_until() 阻塞直至计数器增加或到达时限。
可把信号量当作 std::condition_variable 的替用品，通常它有更好的性能*/