#include<iostream>
//设置退出条件
void show(){}
template<typename T,typename ...Args>
void show(T v, Args... args)
{
	std::cout << v << ",";
	show(args...);
}
void test01()
{
	show(5,6.2,'*',"hello");
}
int main()
{
	test01();
	return 0;
}
//本质上是递归调用，函数9个步骤，传递完参数后开始输出，四轮，然后没有数据了就进入结束的重载函数，执行完后
//开始结束，销栈，销毁栈区也是四轮，相反顺序。
//c++ prime plus P670面，这种操作还有很多用法.

//这是普通的可变参数，不能接收任意类型，是c风格的
#include<iostream>
#include<cstdarg>
//可变参数的函数
void vair_fun(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
    {
        int arg = va_arg(args, int);
        std::cout << arg << " ";
    }
    va_end(args);
}

int main()
{
    //可变参数有 4 个，分别为 10、20、30、40
    vair_fun(4, 10, 20, 30, 40);
    return 0;
}

//纯纯的c++11风格的可变参数模板
#include <iostream>
using namespace std;
//模板函数递归的出口
void vir_fun() {

}

template <typename T, typename... args>
void vir_fun(T argc, args... argv)
{
    cout << argc << endl;
    //开始递归，将第一个参数外的 argv 参数包重新传递给 vir_fun
    vir_fun(argv...);
}

int main()
{
    vir_fun(1, "http://www.biancheng.net", 2.34);
    return 0;
}
