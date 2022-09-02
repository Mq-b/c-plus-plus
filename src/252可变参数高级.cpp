//#include<iostream>
//#include<array>
//#include<string>
//#include<vector>
//template<typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& data)
//{
//	for (auto& str : data)
//	{
//		os << str<<",";
//	}
//	return os;
//}
//template<typename T, size_t size>
//std::ostream& operator<<(std::ostream& os, const std::array<T, size>& data)
//{
//	for (auto& str : data)
//	{
//		os << str<<",";
//	}
//	return os;
//}
//void print() {}
//template<typename T, typename...Types>
//void print(T first, Types...args) {
//	std::cout << first << '\n';
//	print(args...);
//	return;
//}
//int main()
//{
//	std::array<int, 10>a{ 1,2,3,4,5,6,7,8,9,10 }, b{ 10,9,8,7,6,5,4,3,2,1 };
//	std::vector<std::string>a1{ "离谱" }, b1{ "6666" }, c1{ "阿巴巴" };
//	print("可以",a, b, 10);
//	print(a1, b1, c1, 666);
//}