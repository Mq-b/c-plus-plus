#include<ppl.h>//提供头文件
#include<iostream>
#include<array>
using namespace concurrency;//并发算法都在此命名空间

int main() {
	
	concurrency::parallel_for(1,10, [](auto i) {
		std::cout << i<<' ';
		});
}