#include <iostream>    
#include <algorithm>  
int main() {
    //该数组中存储有 2 个有序序列
    int first[] = { 5,10,15,20,25,7,17,27,37,47,57 };
    //将 [first,first+5) 和 [first+5,first+11) 合并为 1 个有序序列。
    std::inplace_merge(first, first + 5, first + 11);
    for (int i = 0; i < 11; i++) {
        std::cout << first[i] << " ";
    }
    std::cout << std::endl;
    int first_[]{ 57,47,37,27,17,10,9,8,7,6,5,4 };
    std::inplace_merge(first_, first_ + 5, first_ + 11, [](auto a, auto b) {return a > b; });
    for (auto i : first_)
        std::cout << i << ' ';
    return 0;
}
//只能处理有序序列，且有序是指如果要按照从小到大，那么这个数组的两个序列必须也是分别从小到大