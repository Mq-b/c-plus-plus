//#include<iostream>
//template<typename T, typename V>
//auto func(T a, V b)->decltype(a* b)
//{
//	return a * b;
//}
//template<typename A, typename B>
//auto func2(A a, B b)->int
//{
//	return a * b;
//}
//void test01()
//{
//	std::cout << typeid(func(2.3e6, 5)).name() << std::endl;
//}
//void test02()
//{
//	std::cout << typeid(func2(2.3e6, 5)).name() << std::endl;
//}
//int main()
//{
//	test01();
//	//普通返回类型后置
//	test02();
//	return 0;
//}