#include<iterator>//Ã·π©std::distance æ‡¿Î
#include<vector>
#include<iostream>
int main() {
	int n[10];
	std::vector<double>v(10);
	std::cout << std::distance(n, n + 6) << std::endl;				//6
	std::cout << std::distance(v.begin(), v.end()) << std::endl;	//10
}