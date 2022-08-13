//#include<iostream>
//using namespace std;
//
////普通函数与函数模板的区别
//
////1、普通函数调用可以发生隐式类型转换
////2、函数模板 用做东类型推导，不可以发生隐性式类型转换
////3、函数模板 用显示指定类型，可以发生隐式类型转换
//
////普通函数
//int myAdd01(int a, int b)
//{
//	return a + b;
//}
//
//template<class T>
//T myAdd02(T a,T b)
//{
//	return a + b;
//}
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	char c = 'c';
//	cout << myAdd01(a, c) << endl;//隐性转换
//
//	////自动类型推导	不会发生隐式类型转换
//	//myAdd02(a, c);//错误的，无法统一类型
//
//	//显示指定类型	会发生隐式类型转换
//	cout<<myAdd02<int>(a, c) << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}
////建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T