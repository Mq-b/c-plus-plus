#include<iostream>
#include <functional>

/*std::ref 用于包装按引用传递的值。
std::cref 用于包装按const引用传递的值。*/

/*bind()是一个函数模板，它的原理是根据已有的模板，生成一个函数，但是由于bind()不知道生成的函数执行的时候，
传递进来的参数是否还有效。所以它选择参数值传递而不是引用传递。如果想引用传递，std::ref和std::cref就派上用场了。*/
void f(int& n1, int& n2, const int& n3)
{
    std::cout << "In function: n1[" << n1 << "]    n2[" << n2 << "]    n3[" << n3 << "]" << std::endl;
    ++n1; // 增加存储于函数对象的 n1 副本
    ++n2; // 增加 main() 的 n2
    //++n3; // 编译错误
    std::cout << "In function end: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
}

int main()
{
    int n1 = 1, n2 = 1, n3 = 1;
    std::cout << "Before function: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
    std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
    bound_f();
    std::cout << "After function: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;

    //C++11的设计者认为std::bind和std::thread默认应该采用拷贝，如果使用者有需求，加上std::ref()即可实现按引用传递。
    //所以即使函数的第一个参数是引用，但是bin的绑定实际是拷贝，如下
    std::endl(std::cout);
    f(n1, std::ref(n2), std::cref(n3));
    std::cout << "After function: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
}
/*n1是值传递，函数内部的修改对外面没有影响。
n2是引用传递，函数内部的修改影响外面。
n3是const引用传递，函数内部不能修改。*/