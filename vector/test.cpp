#include"vector.hpp"
#include<iostream>
#include<string>

int main() {
	mylib::vector<int> v;
	std::cout << v.capacity() << ' ' << v.size() << '\n';
	v.assign(16, 1);
	std::cout << v[15] << std::endl;

	v.assign({ 1,2,3,4,5,6 });
	std::cout << v[5] << std::endl;
	int array[]{ 10,2,3 };
	v.assign(array, array + 3);
	std::cout << v[2] << std::endl;

	mylib::vector<int>v2(16);
	v2.assign(16,6);
	v2[15] = 100;
	std::cout << *(v2.cend()-1) << std::endl;

	const mylib::vector<int>v3(16);
	try
	{
		v3.at(16);
	}
	catch (const std::exception&e)
	{
		std::clog << e.what() << std::endl;
	}
	std::cout << v2.max_size() << std::endl;

	std::cout << *v2.data() << std::endl;

	std::cout << v2.front() << ' ' << v2.back() << ' ' << v3.front() << ' ' << v3.back() << '\n';
}