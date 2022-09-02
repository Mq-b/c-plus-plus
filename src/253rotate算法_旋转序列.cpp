#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<vector>
int main() {
    std::vector<std::string> words{ "one", "two", "three", "four", "five","six", "seven", "eight" };
    auto iter = std::rotate(std::begin(words), std::begin(words) + 3, std::end(words));
    std::copy(std::begin(words), std::end(words), std::ostream_iterator<std::string> {std::cout, " "});
    //三个参数分别是开始位置，然后到自己需要的位置，然后结束位置，比如开始是1，需要的位置是3，结束的位置是5，那么就会把1 2 3 放到5后面，如下所示4 5 6 7 8 9 10 1 2 3
    std::vector<int>n{ 1,2,3,4,5,6,7,8,9,10 };
    std::rotate(n.begin(), n.begin() + 3, n.end());
    std::copy(std::begin(n), std::end(n), std::ostream_iterator<int> {std::cout, " "});
}