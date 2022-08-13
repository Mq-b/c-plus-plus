#include<string>
#include<iostream>
#include<MAP>
int main()
{
	std::map<int, std::string>Map;
	for (int i = 0; i < 1000; i++)
		Map.insert(std::pair<int, std::string>(i, "流弊"));
	for (const auto& [a, b] : Map)
		std::cout << a << b << '\n';
	std::endl(std::cout);
}