#include <memory>
#include <iostream>
#include<algorithm>

int main()
{
    std::allocator<int> v1Alloc;//创建空间配置器对象时的类型决定申请堆区内存的类型
    auto v1aPtr = v1Alloc.allocate(10);//分配内存数量
    for (int i = 0; i < 10; i++) {
        v1aPtr[i] = i;
    }
    std::for_each(v1aPtr, v1aPtr + 10, [](auto a) {std::cout << a << ' '; });
    std::cout << std::endl;
    v1Alloc.deallocate(v1aPtr, 10);//释放分配的内存

}