#include<iostream>
#include<vector>

int main()
{
	std::vector<int>num={
	#include"data.h"
	};
	for (auto i : num)
		std::cout << i << ' ';
	std::endl(std::cout);
	int n[10] = {
	#include"data.h"
	};
	std::cout << 2[n] << std::endl;//a[i]->*(a+i)->*(i+a)->i[a] 
}