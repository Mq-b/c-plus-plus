#include<string>
#include<iostream>
#include<MAP>
int main()
{
	std::map<int, std::string>Map;
	for (int i = 0; i < 1000; i++)
		Map.insert(std::pair<int, std::string>(i, "Á÷±×"));
	for (const auto& [a, b] : Map)
		std::cout << a << b << '\n';
	std::endl(std::cout);
}