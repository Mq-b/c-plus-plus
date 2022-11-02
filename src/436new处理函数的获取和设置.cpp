#include <iostream>
#include <new>

void handler()
{
    std::cout << "Memory allocation failed, terminating\n";
    std::set_new_handler(nullptr);
}

int main()
{
    auto p = std::get_new_handler();
    if (p != nullptr) {
        p();
    }

    std::set_new_handler(handler);
    p = std::get_new_handler();
    p();//如果这里显式调用了，那么当抛出异常的时候则不会再调用处理函数,所以处理函数只会被调用一次

    try {
        while (true) {
            new int[100000000ul];
        }
    }
    catch (const std::bad_alloc& e) {
        std::cout << e.what() << '\n';
    }
}
/*按道理会得到如下结果，但是MSVC不抛出异常，所以请使用gcc测试
Memory allocation failed, terminating
std::bad_alloc
*/