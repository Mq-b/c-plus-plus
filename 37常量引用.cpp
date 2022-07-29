//#include<iostream>
//using namespace std;
//
//void print(const int&val)
//{
//	//val = 1000;加了const就不能修改了
//	cout << val << endl;
//}
//int main()
//{
//	//常量引用
//	//用来修饰形参，防止误操作
//	int a = 10;
//
//	//加上cost后，编译器将代码修改 int temp=10;const int&ref=temp;
//	const int& ref = 10;//引用必须引一块合法的内存空间
//	//ref = 100;错误的，加入const变成只读，不可修改
//	print(ref);
//	print(100);
//	print(a);
//	return 0;
//}