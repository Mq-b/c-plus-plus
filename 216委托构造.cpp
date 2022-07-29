//#include<iostream>
//using namespace std;
//
//class Test
//{
//public:
//	//委托构造，一定要通过初始化列表方式
//	Test() :Test(1, 'a')
//	{
//
//	}
//
//	Test(int x) :a(x)
//	{
//
//	}
//
//	Test(int x,int y) :a(x),b(y)
//	{
//
//	}
//
//	int a;
//	char b;
//};
//int main()
//{
//	Test a;//委托构造
//	cout << a.a << " " << a.b << endl;
//	Test b(10);
//	cout << b.a << " " << b.b << endl;
//	return 0;
//}