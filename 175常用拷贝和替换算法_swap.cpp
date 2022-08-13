//#include <algorithm>
//#include <vector>
//#include<iostream>
//using namespace std;
//class myPrint
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//};
//
//void test01()
//{
//	vector<int> v1;
//	vector<int> v2;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//		v2.push_back(i + 100);
//	}
//
//	cout << "交换前： " << endl;
//	for_each(v1.begin(), v1.end(), myPrint());
//	cout << endl;
//	for_each(v2.begin(), v2.end(), myPrint());
//	cout << endl;
//
//	cout << "交换后： " << endl;
//	swap(v1, v2);
//	for_each(v1.begin(), v1.end(), myPrint());
//	cout << endl;
//	for_each(v2.begin(), v2.end(), myPrint());
//	cout << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}
////注意得是同种类型交换、

//#include<stdio.h>
//#include<time.h>
//#include <stdlib.h>
//void func(int* a)
//{
//	for (int i = 0; i < 1000; i++)
//	{
//		if (a[i] % 7 == 0 || a[i] % 11 == 0) 
//		{
//			if (!(a[i] % 7 == 0 && a[i] % 11==0))
//			printf("%d\n", a[i]);
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));///使用随机数种子
//	int a[1000] = { 0 };
//	for (int i = 0; i < 1000; i++)
//	{
//		a[i] = rand() % 10000;
//	}
//	func(a);
//}
