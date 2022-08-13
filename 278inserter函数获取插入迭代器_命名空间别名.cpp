#include<iostream>
#include<vector>
namespace stdr = std::ranges;//命名空间赋值
//等于是把std::ranges变成了stdr
int main()
{
	std::vector<int>V{ 1,2,3 };
	auto it = std::inserter(V, V.begin() + 2);//获取插入迭代器
	*it = 100;//插入迭代器可被赋值不可被打印
	std::copy(V.begin(), V.end(), std::ostream_iterator<int>{std::cout, " "});
	std::endl(std::cout);
	stdr::copy(V, std::ostream_iterator<int>{std::cout, " "});//这样写法要方便很多，相比前者少了一个参数
}