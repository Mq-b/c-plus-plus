#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<string>
#include <unordered_set>
int main()
{
    std::vector<std::string> names{ "A1", "Beth", "Carol", "Dan", "Eve","Fred", "George", "Harry", "Iain", "Joe" };
    std::unordered_set<std::string> more_names{ "Jean", "John" };
    size_t max_length{ 4 };
    std::copy_if(std::begin(names), std::end(names), std::inserter(more_names, std::begin(more_names)), [=](const std::string& s) { return s.length() <= max_length; });//每一项都要判断长度是否大于等于4，满足条件才会拷贝
    /*因为作为第 4 个参数的 lambda 表达式所添加的条件，这里的 copy_if() 操作只会复制 names 中的 4 个字符串或更少。目的容器是一个 unordered_set 容器 more_names，它已经包
    含两个含有 4 个字符的名称。和前面的章节一样，insert_itemtor 会将元素添加到限定的关联容器中。如果想要展示它是如何工作的，可以用 copy() 算法列出 more_names 的内容*/
    std::copy(std::begin(more_names), std::end(more_names), std::ostream_iterator <std::string>{std::cout, " "});
    std::cout << std::endl;

    //当然也可以使用流迭代器，打印lambda为真的
    std::copy_if(std::begin(names), std::end(names), std::ostream_iterator< std::string> {std::cout, " "}, [max_length](const std::string& s) { return s.length() > max_length; });
}