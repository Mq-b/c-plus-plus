#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
/*rotate_copy() 算法会在新序列中生成一个序列的旋转副本，并保持原序列不变。rotate_copy() 的前 3 个参数和 copy() 是相同的；第 4 个参数是一个输出迭代器，
它指向目的序列的第一个元素。这个算法会返回一个目的序列的输出迭代器，它指向最后一个被复制元素的下一个位置。例如：*/
int main() {
    std::vector<std::string> words{ "one", "two", "three", "four", "five","six", "seven", "eight", "nine","ten" };
    auto start = std::find(std::begin(words), std::end(words), "two");
    auto end_iter = std::find(std::begin(words), std::end(words), "eight");
    std::vector<std::string> words_copy;
    std::rotate_copy(start, std::find(std::begin(words), std::end(words), "five"), end_iter, std::back_inserter(words_copy));

    std::copy(std::begin(words_copy), std::end(words_copy), std::ostream_iterator<std::string>{std::cout, " "});
    std::cout << std::endl;
}