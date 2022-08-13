//#include<iostream>
//using namespace std;
//
////普通函数与函数模板调用规则
////1、如果函数模板和普通函数都可以调用，优先调用函数模板
////2、可以通过空模板参数列表 强制调用 函数模板
////3、函数模板可以发生函数重载
////4、如果函数模板可以更好的匹配，优先调用函数模板
//
//void myPrint(int a, int b)
//{
//	cout << "调用的是普通函数" << endl;
//}
//
//template<class T>
//void myPrint(T a, T b)
//{
//	cout << "调用的模板" << endl;
//}
//
//template<class T>
//void myPrint(T a, T b,T c)
//{
//	cout << "调用重载的模板" << endl;
//}
//
//void test01()
//{
//	int a = 10;
//	int b = 20;
//
//	//myPrint(a, b);//重载
//	myPrint<>(a, b);//空模板参数列表
//	myPrint(a, b, 100);
//
//	//如果函数模板产生更好的匹配，优先调用函数模板
//	char c1 = 'a';
//	char c2 = 'b';
//	myPrint(c1, c2);//编译器认为直接char推导比隐性转换更好的匹配，所以调用的模板
//}
//int main()
//{
//	test01();
//	return 0;
//}
////既然提供了函数模板就不要提供普通函数，否则容易出现二义性