#include"list.hpp"
#include<iostream>
using namespace mylib;

int main() {
	list<int>l(10, 1);
	std::cout << l.head->next->object << '\n';
}