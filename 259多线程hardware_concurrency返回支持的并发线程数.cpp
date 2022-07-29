#include <iostream>
#include <thread>

int main() {
    unsigned int n = std::jthread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
    //jthread和thread的区别主要是析构，不用join或者thread了，但这需要开销所以就重新写了个jthread类
}