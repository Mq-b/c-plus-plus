#include"vector.hpp"
#include<iostream>
#include<string>
#include<span>

template<typename T>
void print(T sp) {
	for (auto i : sp)
		std::cout << i << ' ';
	std::cout << '\n';
}

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

	mylib::vector v4(v);
	std::cout << v4.size() << ' ' << v4.capacity() << '\n';
	std::cout << v[0] << std::endl;
	for (auto i : v4)
		std::cout << i << ' ';
	std::cout << '\n';

	mylib::vector v5(8, 66);
	for (auto i : v5)
		std::cout << i << " ";
	std::cout << '\n';

	v4 = v5;
	for (auto i : v4)
		std::cout << i << " ";
	std::cout << '\n';

	v4 = std::move(v5);
	for (auto i : v4)
		std::cout << i << " ";
	std::cout << '\n';

	v4 = { 1,11,111,111,2,22,222 };
	for (auto i : v4)
		std::cout << i << " ";
	std::cout << '\n';

	mylib::vector<int>v6;
	v6.push_back(10);
	std::cout << v6[0] << ' ' << v6.size() << ' ' << v6.capacity() << '\n';
	v6.emplace_back(6);
	std::cout << v6[1] << ' ' << v6.size() << ' ' << v6.capacity() << '\n';

	mylib::vector<std::string>v7;
	std::string str{ "66" };

	v7.push_back("77");
	v7.push_back("傻子");
	v7.push_back(str);
	v7.push_back(std::string("无趣"));
	std::cout << v7[2] << ' ' << v7.size() << ' ' << v7.capacity() << '\n';
	v7.pop_back();
	v7.push_back("有趣");
	print(v7);

	v7.resize(10,"*");
	std::cout << v7[9] << ' ' << v7.size() << ' ' << v7.capacity() << '\n';

	std::cout << std::distance(v7.cbegin(), v7.cend()) << std::endl;

	v7.emplace(v7.cend(), std::string("78"));
	v7.emplace(v7.begin(), std::string("*****"));
	v7.insert(v7.begin(), "*66*");
	std::cout << v7[0] <<' '<<v7[1] << ' ' << v7.size() << ' ' << v7.capacity() << '\n';
	v7.insert(v7.end(), 10, "哈");
	print(v7);

	int array2[]{ 1,2,3,4,5 };
	v6.insert(v6.begin() + 2, std::begin(array2), std::end(array2));
	print(v6);

	v6.insert(v6.end(), { 9,9,9,9,9,9,9 });
	print(v6);
	v6.erase(v6.begin());
	print(v6);
	std::cout << v6.size() << ' ' << v6.capacity() << '\n';
	v6.erase(v6.begin(), v6.begin() + 6);
	print(v6);
	std::cout << v6.size() << ' ' << v6.capacity() << '\n';

	mylib::vector<int>v8;
	v8.swap(v6);

	std::cout << v8.size() << ' ' << v8.capacity() << '\n';
	std::cout << v6.size() << ' ' << v6.capacity() << '\n';
	print(v8);

	mylib::vector v9{ 1,2,3,4,5,6,7,8,9,10 };
	std::cout << v9.size() << ' ' << v9.capacity() << '\n';
	print(v9);

	mylib::vector v10(v9.begin(), v9.begin() + 5);
	print(v10);
	std::cout << v10.size() << ' ' << v10.capacity() << '\n';

	std::cout << (v10 == v9) << ' ' << (v10 != v9) << '\n';
	std::cout << (v10 > v9) << ' ' << (v10 < v9) << '\n';
	std::cout << (v10 >= v9) << ' ' << (v10 <= v9) << '\n';
	std::cout << int((v10 <=> v9)._Value) << std::endl;

	mylib::swap(v10, v9);
	std::cout << int((v10 <=> v9)._Value) << std::endl;

	print(v10);
	mylib::erase(v10, 10);
	print(v10);
	mylib::erase_if(v10, [](auto i) {return i == 5; });
	print(v10);
}