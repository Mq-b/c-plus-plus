//#include<iostream>
//using namespace std;
////1.不要返回局部变量的引用
//int& test01()
//{
//	int a = 10;//存放在四区中的栈区
//	return a;
//}
////2.函数的调用可以为左值
//int& test02()
//{
//	static int a = 10;//静态变量，存放在全局区，全局区上的 数据在程序结束后系统释放
//	return a;
//}
//int main()
//{
//	//int& ref = test01();
//	//cout << ref << endl;//两行都是错误写法
//
//	int& ref2 = test02();
//	cout << ref2 << endl;
//	cout << ref2 << endl;
//	test02() = 10000;
//	cout << ref2 << endl;
//	cout << ref2 << endl;
//}