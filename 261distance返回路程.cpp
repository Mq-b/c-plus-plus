#include<iterator>//提供std::distance 距离
#include<vector>
#include<iostream>
int main() {
	int n[10];
	std::vector<double>v(10);
	std::cout << std::distance(n, n + 6) << std::endl;				//6
	std::cout << std::distance(v.begin(), v.end()) << std::endl;	//10
}