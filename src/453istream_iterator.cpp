#include<iostream>
#include<iterator>
#include<vector>
int main() {
	std::vector<int> V(std::istream_iterator<int>(std::cin), {});//这个{}的类型用第一个参数推导了，但是也适用于第二个参数{}自己
	//std::vector<int> v({ 1,2 }, {});//这两种方式调用的同一个构造函数,也就是Ite First Iter Last的版本
	// 
	//auto v = std::istream_iterator<int>(std::cin);//也可以直接这样，那么输入完后v就指向第一个数据的地址

	for (const auto i : V) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	/*for (int i = 0; i < 3; i++, v++) {
		std::cout << *v << ' ';
	}*/
}