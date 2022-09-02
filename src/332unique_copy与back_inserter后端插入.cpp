#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	std::string s1 = "The      string    with many       spaces!";
	std::cout << "before: " << s1 << '\n';
	std::string s2;
	/*unique_copy只复制每组等价元素的首元素也就是说如果两个元素相等，那么就去重，需要传入一个二元谓词来处理		std::back_inserter能用于添加元素到容器尾端*/
	std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2), [](auto c1, auto c2) { return c1 == ' ' && c2 == ' '; });

	std::cout << "after:  " << s2 << '\n';
}