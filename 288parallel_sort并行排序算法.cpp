#include <ppl.h>
#include <random>
#include <iostream>

using namespace concurrency;

int wmain()
{
    //std::mt19937是伪随机数产生器，用于产生高性能的随机数。 C++11引入
    std::vector<int> values(25000);
    //std::generate这个算法会编译迭代器范围内的数据，第三个参数是一个可调用对象，对他们进行操作,我们这里使用的mt19937产生随机数进行赋值
    std::generate(begin(values), end(values), std::mt19937(std::random_device()()));
    concurrency::parallel_sort(begin(values), end(values));

    // Print a few values.
    std::wcout << "V(0)        = " << values[0] << std::endl;
    std::wcout << "V(12500000) = " << values[12500] << std::endl;
    std::wcout << "V(24999999) = " << values[24999] << std::endl;
}