#include <iostream>
#include <new>

int main()
{
    try {
        while (true) {
            new int[100000000ul];   // 抛出异常的重载版本
        }
    }
    catch (const std::bad_alloc& e) {
        std::cout << e.what() << '\n';
    }

    while (true) {
        auto p = new(std::nothrow) int[100000000ul]; // 不抛出异常的重载版本
        if (p == nullptr) {
            std::cout << "Allocation returned nullptr\n";
            break;
        }
    }
}
//std::nothrow_t 是用于区分抛出与不抛出分配函数重载的空类类型。
//std::nothrow 是 std::nothrow_t 类型的常量，用于区分抛出与不抛出分配函数的重载
/*运行结果如下，但是vs无法得到，gcc才可以
std::bad_alloc
Allocation returned nullptr
*/