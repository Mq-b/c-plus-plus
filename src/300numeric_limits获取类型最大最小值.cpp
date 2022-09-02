#include<iostream>
#include<limits>

int main() {
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<int>::lowest() << std::endl;
	
}
//为了让我们方便得到类型最大或者最小的值。而不需要再使用C的宏