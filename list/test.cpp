#include"list.hpp"
#include<iostream>
using namespace mylib;

int main() {
	list l(10, 1);
	std::cout << l.head->next->next->next->object << '\n';

	list l2{ 1,2,3,4,5,6 };
	std::cout << l2.head->next->next->next->object << '\n';

}