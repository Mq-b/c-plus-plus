#include"list.hpp"
#include<iostream>
using namespace mylib;

template<typename T>
void print(mylib::list<T>l) {
	std::cout << "{";
	for (const auto i : l) {
		std::cout << i << ' ';
	}
	std::cout << "}";
	endl(std::cout);
}

int main() {
	list l(10, 1);
	std::cout << l.head->next->next->next->object << '\n';

	list l2{ 1,2,3,4,5,6 };
	std::cout << l2.head->next->next->next->object << '\n';

	list<int> l3;
	l3 = l2;
	std::cout << l3.head->next->next->next->object << '\n';

	l3 = { 10,20,30 };
	std::cout << l3.head->next->next->next->object << '\n';
	print(l3);

	l3.assign(2, 5);
	std::cout << l3.tail->object << '\n';
	std::cout << l3.head->next->next->object << '\n';

	l3.assign(10, 6);
	std::cout << l3.head->next->next->next->object << '\n';

	int array[]{ 1,2,3,4 };
	l3.assign(array, array + 4);
	std::cout << l3.head->next->next->next->next->object << '\n';

	l3.assign({ 7,8,9,10,11,12,13,14,15,16,17,18,19,20 });
	std::cout << l3.head->next->next->next->next->object << '\n';

	std::cout << l3.front() << ' ' << l3.back() << '\n';

	std::cout << *l3.begin()<<' '<<*l3.cbegin() << '\n';

	auto p = l3.end();
	p--;
	std::cout << *p << ' ' << *(--l3.end()) << '\n';
	std::cout << *(++l3.cbegin()) << '\n';
	print(l3);

	auto p2 = l3.crbegin();
	auto p3 = l3.crend();
	std::cout << *(l3.crend()) << ' ' << *(++p2) << ' ' << *(--p3) << '\n';

	list l4{ 1,2,3 };
	*l4.begin() = 10;
	std::cout << *l4.begin() << '\n';
	print(l4);

	std::cout << l4.max_size() << '\n';

	std::cout << l4.size() << '\n';
	print(l4);
	l4.clear();
	std::cout << l4.size() << '\n';
	print(l4);
}