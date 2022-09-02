#include<iostream>
namespace A
{
	namespace std
	{
		struct my_struct {};
	}
}

using namespace A; // 删除此行会使 std:: 解析为全局 std::

int main()
{
	//::std::my_struct; // 标准库的std库内没有成员

	//std::my_struct; // 不明确到底是哪个std

	A::std::my_struct;	//加上A作用域下就明确了是A的std，或者像第一行::能明确是标准的全局下的std
}
//https://stackoverflow.com/questions/33102207/difference-in-using-namespace-std-vs-std