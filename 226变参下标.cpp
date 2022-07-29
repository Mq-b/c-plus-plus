#include<iostream>
#include<string>
template<typename...Args>
auto print(Args&&...args) {
	(std::cout << ... << args) << std::endl;//创建c++17的折叠表达式函数来对下面这个进行输出

}
template<typename C, typename... Idx>
void printElems2(C const& coll ,Idx... idx)
{
	print(coll[idx]...);
}

template<typename C, typename... Idx>
void printElems(C const& coll, Idx... idx)
{
	((std::cout << coll[idx] << ","), ...);//中间用逗号隔开
}

//直接cout输出，不使用外部函数
template<typename C, typename... Idx>
void printElems(C const& coll, Idx... idx)
{
	(std::cout << ... << coll[idx]);
}
int main()
{
	const int num[5]{ 1,2,3,4,5 };
	printElems(num, 1, 2, 3, 4);
	return 0;
}