#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v{ 3, 1, 4 };

    auto vi = v.begin();

    std::advance(vi, 2);//第一个参数是要前进的迭代器，第二个参数是前进的元素个数

    std::cout << *vi << '\n';//打印4
}
//它的功能远不止如此，可以查看参考文档，先这样用