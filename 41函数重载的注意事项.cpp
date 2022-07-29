//#include<iostream>
//using namespace std;
//
////函数重载的注意事项
////1.引用作为重载的条件
//void fun(int& a)//int &a=10;不合法
//{
//	cout << "fun(int&a)调用" << endl;
//}
//
////2.函数重载碰到默认参数
//void fun2(int a,int b=10)
//{
//	cout << "fun(int a,int b)的调用" << endl;
//}
//
//void fun2(int a)
//{
//	cout << "fun(int a)的调用1" << endl;
//}
//
//void fun(const int& a)//
//{
//	cout << "fun(const int&a)调用" << endl;//const int &a=10;合法
//}
//
//int main()
//{
//	int a = 10;
//	//fun(10);
//	//fun(a);//调用没加const的函数
//	//fun2(10);//当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况
//	fun2(10, 10);
//	return 0;
//}