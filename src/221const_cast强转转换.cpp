#include<iostream>
#include<string>
//c++中一旦const绝对无法修改
int main()
{
	const int n = 10;
	int* p = const_cast<int*>(&n);//强制去掉const属性
	*p = 2;						//但是在c++11依旧无法修改，可以编译通过，禁止执行
	std::cout << n << std::endl;
	return 0;
}
