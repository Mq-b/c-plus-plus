#include<iostream>  
int main()
{
	double start, end, cost;
	start = clock();
	_sleep(1);
	end = clock();
	cost = end - start;
	printf("%f\n", start);
	printf("%f\n", end);
	printf("%f\n", cost);//相减即可得出中间代码运行所需时间
}
/*
* 在time.h文件中，还定义了一个常量CLOCKS_PER_SEC，它用来表示一秒钟会有多少个时钟计时单元，其定义如下：
	#define CLOCKS_PER_SEC ((clock_t)1000)

	表示clock（）可以精确到1毫秒

	在linux系统下，CLOCKS_PER_SEC的值可能有所不同，目前使用的linux打印出来的值是1000000，表示的是微秒

	lock()函数返回从“开启这个程序进程”到“程序中调用clock()函数”时之间的CPU时钟计时单元（clock tick）数

	精度算较高，我们下面介绍GetTickCount()
*/