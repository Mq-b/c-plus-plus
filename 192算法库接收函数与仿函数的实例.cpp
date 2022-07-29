//#include<iostream>
//#include<array>
//class Print
//{
//public:
//	void operator()(std::array<int, 5>num)const
//	{
//		for (int i : num)
//		{
//			std::cout << i << " ";
//		}
//		std::cout << std::endl;
//	}
//};
//
//
//void print(std::array<int, 5>num)
//{
//	for (int i : num)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//}
//
//template<class T, class B>
//auto show(T num, B print)
//{
//	print(num);
//	std::cout << typeid(print).name() << std::endl;
//}
//
//void test03()
//{
//	std::array<int, 5>num{ 1,2,3,4,5 };
//	//使用仿函数
//	show(num, Print());
//	//使用普通函数
//	show(num, print);
//	//匿名函数对象
//	Print()(num);
//}
//int main()
//{
//	test03();
//}