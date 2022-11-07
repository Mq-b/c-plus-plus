#include <iostream>
#include <thread>
#include <boost/asio.hpp>

std::mutex mutex_iostream;

void my_task(){
    std::lock_guard<std::mutex> lg(mutex_iostream);
    std::cout << "This is my task." << std::endl;
}

int main(int argc, const char** argv){
    /* 定义一个4线程的线程池 */
    boost::asio::thread_pool tp(4);

    /* 将函数投放到线程池 */
    for (int i = 0; i < 5; ++i) {
        boost::asio::post(tp, my_task);
    }

    /* 将函数投放到线程池 */
    for (int i = 0; i < 5; ++i) {
        boost::asio::post(
            tp,
            []() {
                std::lock_guard<std::mutex> lg(mutex_iostream);
                std::cout << "This is lambda task." << std::endl;
            });
    }

    /* 退出所有线程 */
    tp.join();
}