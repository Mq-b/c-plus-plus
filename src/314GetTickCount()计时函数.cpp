#include<iostream>
#include<Windows.h>
int main() {
	INT64 start = GetTickCount64();
	_sleep(10);
	INT64  end = GetTickCount64();
	std::cout << "GetTickCount:" << end - start << std::endl;
}
/*
	GetTickcount函数：它返回从操作系统启动到当前所经过的毫秒数(与lock不同)，它的返回值是DWORD。常常用来判断某个方法执行的时间，其函数原型是DWORD GetTickCount(void)，

	返回值以32位的双字类型DWORD存储，因此可以存储的最大值是(2^32-1) ms约为49.71天，因此若系统运行时间超过49.71天时，这个数就会归0

	特别注意：这个函数并非实时发送，而是由系统每18ms发送一次，因此其最小精度为(14-16)ms，也就是操作系统的一个CPU时间片。当需要有小于18ms的精度计算时，应使用StopWatch方法进行。
*/