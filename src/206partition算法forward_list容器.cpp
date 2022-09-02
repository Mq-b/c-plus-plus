#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
    if (first == last) return;
    auto pivot = *std::next(first, std::distance(first, last) / 2);
    ForwardIt middle1 = std::partition(first, last,
        [pivot](const auto& em) { return em < pivot; });
    ForwardIt middle2 = std::partition(middle1, last,
        [pivot](const auto& em) { return !(pivot < em); });
    quicksort(first, middle1);
    quicksort(middle2, last);
}
int main()
{
    std::vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
    std::cout << "Original vector:\n    ";
    for (int elem : v)
        std::cout << elem << ' ';
    
    //it被推导为一个迭代器，vector<int>iterator，因为partition算法返回迭代器就是所有满足第三个参数的值的地址后一位。(partition() 函数返回一个正向迭代器，其指向的是两部分数据的分界位置)
    //partition算法会按照第三个参数进行排列，这里的话按照值，满足顺序的排列，也就是0 2 4 8满足放在前面，然后5 3 7 1 9不满足的放在他们的后面，it迭代器指向的也就是5
    auto it = std::partition(v.begin(), v.end(), [](int i) {return i % 2 == 0; });
    std::cout << "\nPartitioned vector:\n    ";
    
    //std::begin(v)相当于v.begin(),然后it根据前面所得也就是指向满足要求数据的后一位，end，所以copy到输出流就是拷贝0 2 4 8
    std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << " * ";
    //std::end(v)相当于v.end(),it作为begin，然后end，也就是copy的范围，即不满足要求的数据
    std::copy(it, std::end(v), std::ostream_iterator<int>(std::cout, " "));
    
    //forward_list容器基本等于list容器，但是前者的效率更高，是单链表的底层，不支持rbegin，rend这些方法，反向遍历
    std::forward_list<int> fl = { 1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92 };
    std::cout << "\nUnsorted list:\n    ";
    for (int n : fl)
        std::cout << n << ' ';
    std::cout << '\n';

    quicksort(std::begin(fl), std::end(fl));
    std::cout << "Sorted using quicksort:\n    ";
    for (int fi : fl) std::cout << fi << ' ';
    std::cout << '\n';
}