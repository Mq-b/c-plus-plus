#include<iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout << "hello word!";
}
/*1、ios::sync_with_stdio(false);

首先了解ios::sync_with_stdio(false);是C++ 的输入输出流（iostream）是否兼容C的输入输出（stdio）的开关。

因为C++ 中的std::cin和std::cout为了兼容C，保证在代码中同时出现std :: cin和scanf或std :: cout和printf时输出不发生混乱，

所以C 用一个流缓冲区来同步C的标准流。通过std::ios_base::sync_with_stdio函数可以解除这种同步，让std::cin和std::cout不再经过缓冲区，自然就节省了许多时间。

副作用：当设置为false时，cin就不能和scanf，sscanf, getchar, fgets等同时使用。

据说，endl用”\n”代替和cout使用，也可节约时间。
2、cin.tie(nullptr);

因为std::cin默认是与std::cout绑定的，所以每次操作的时候（也就是调用”<<”或者”>>”）都要刷新（调用flush），这样增加了IO的负担，通过tie(nullptr)来解除std ::cin和std ::cout之间的绑定，来降低IO的负担使效率提升。*/