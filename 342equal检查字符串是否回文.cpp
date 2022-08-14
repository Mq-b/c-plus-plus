#include <iostream>
#include <algorithm>
#include <string>

void test(const std::string_view& s)
{
    if (std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin())) 
        std::cout << s << "是回文串" << std::endl;
    else 
        std::cout << s << "不是回文串" << std::endl;
}
int main()
{
    test("radar");
    test("hello");
}