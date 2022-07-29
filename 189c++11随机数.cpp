#include<iostream>
#include<random>

int main()
{
    std::default_random_engine random(time(NULL));//构造随机数种子
    std::uniform_int_distribution<int> u(0, 100);//设置范围
    for (int i = 0; i < 20; ++i)
        std::cout << u(random) << ' ';
    std::cout << std::endl;

    return 0;
}