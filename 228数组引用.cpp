#include<iostream>
#include<string>
template<typename T, int N, int M>
bool less(T(&a)[N], T(&b)[M])//数组引用与模板，数组引用让模板能直接推导出数组的长度
{
	for (int i = 0; i < N && i < M; ++i)
	{
		if (a[i] < b[i]) return true;
		if (b[i] < a[i]) return false;
	}
	return N < M;
}

template<typename T, int N, int M>
void test1(T(&a)[N], T(&b)[M])
{
	std::cout << sizeof a << "," << sizeof b << std::endl;
}

void test2(int a[], int b[])
{
	std::cout << sizeof a << "," << sizeof b << std::endl;
}

int main()
{
	int x[] = { 1, 2, 3 };
	int y[] = { 1, 2, 3, 4, 5 };
	std::cout << less(x, y) << '\n';
	//数组引用的语法
	int(&p)[3] = x;	//使用括号是因为结合性，方括号的优先级更高用小括号让变量先和&结合表示是引用
	std::cout << p[2] << "," << x[2] << std::endl;//结果是一样的
	
	//我们再用两个函数表示一下
	test1(x, y);//12 20
	test2(x, y);//4 4
	//前者能直接得出数组的大小，后者只有指针

	//我们再举一个例子，auto
	auto& p2 = x;
	std::cout << sizeof p2 << "," << sizeof x << std::endl;//结果是一样的 12 12，auto的引用一样会推导为数组引用

	return 0;
}
//这样写主要的好处是防止数组衰退成指针，失去了长度
//同时第一个函数是专门处理裸数组或者字符常量的模板