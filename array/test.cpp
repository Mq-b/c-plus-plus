#include"array.hpp"
#include<iostream>
#include<fmt/core.h>

int main() {
	mylib::array<int, 10>arr{ 1,2,3,4,5,6,7,8,9,10 };
	try
	{
		std::cout << arr.at(10) << std::endl;
	}
	catch (const std::exception&e)
	{
		std::clog << e.what() << std::endl;
	}
	std::cout << arr.at(9) << std::endl;
	std::cout << arr[9] << std::endl;
	arr[9] = 66;

	const mylib::array<int, 10>v{ 1,2 };
	std::cout << v[1] << ' ' << v.at(0) << std::endl;

	v[0];

	std::cout << ( * arr.begin() == *arr.rend() )<< std::endl;//0
	std::cout << *arr.cbegin() << ' ' << *(arr.crend()-1) << std::endl;//1 1
	std::cout << *arr.rbegin() << ' ' << *arr.crbegin() << ' ' << *(arr.end() - 1) << std::endl;//66 66 66

	arr.fill(1);
	for (auto i : arr) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	mylib::array<int, 10>arr2;
	arr2.fill(2);
	arr.swap(arr2);

	for (auto i : arr2) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	auto& ret = mylib::get<1>(arr);
	std::cout << ret << std::endl;

	int array[]{ 1,2,3,4,5,6,7,8,9,10 };

	auto arrr = mylib::to_array<int>(array);
	for (auto i : arrr)
		std::cout << i << ' ';
	std::cout << '\n';

	auto arrr2 = mylib::to_array<int>({ 1,2,3,4,5,6,7,8,9,10 });

	for (auto i : arrr2) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	mylib::array c{ 1,2,3,4,5,6 };
	for (auto i : c)
		std::cout << i << ' ';
	std::cout << '\n';
}