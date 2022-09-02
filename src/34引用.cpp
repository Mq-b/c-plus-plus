//#include<iostream>
//using namespace std;
//
//int main()
//{
//	//引用的基本语法
//	//数据类型，&别名=原名
//	int a = 10;
//	int c = 20;
//	int& b = a;//引用必须初始化，后面不能改变
//	//int& b;//错误写法
//
//	cout << a << endl;
//	cout << b << endl;
//
//	b = 30;
//	cout << a << endl;
//	cout << b << endl;
//
//	a = 11;
//	cout << a << endl;
//	cout << b << endl;
//
//	//a和b操作的同一块内存
//
//	b = c;//赋值操作不是更改引用，等同于b=20
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}