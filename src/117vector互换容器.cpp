//#include<iostream>
//using namespace std;
//#include<vector>
//
////容器互换
//
////1、基本使用
//void printVector(vector<int>& v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	cout << "交换前" << endl;
//	printVector(v1);
//
//	vector<int>v2;
//	for (int i = 10; i > 0; i--)
//	{
//		v2.push_back(i);
//	}
//	printVector(v2);
//
//	cout << "交换后" << endl;
//	v1.swap(v2);
//	//swap(v1, v2);//也可以使用这种写法
//	printVector(v1);
//	printVector(v2);
//}
//
////2、实际用途
////巧用swap可以收缩内存空间
//void test02()
//{
//	vector<int>v;
//	for (int i = 0; i < 100000; i++)
//	{ 
//		v.push_back(i);
//	}
//	cout << "v的容量为:" << v.capacity() << endl;
//	cout << "v的大小为:" << v.size() << endl;
//
//	v.resize(3);//重新指定大小
//	//指定大小不会改变容器的容量
//	cout << "v的容量为:" << v.capacity() << endl;
//	cout << "v的大小为:" << v.size() << endl;
//
//	//巧用swap收缩内存
//	vector<int>(v).swap(v);
//	//vetor<int>(v)实际是一个匿名对象初始化为v的大小就是3，匿名对象指向的就是这块内存
//	//.swap(v)就是匿名对象和对象v进行交换，v指向匿名对象的内存，匿名对象指向v的内存
//	//语句结束后，匿名对象连同内存就被系统销毁
//	//匿名对象的特点是，当前行执行完，系统就回收掉
//	cout << "v的容量为:" << v.capacity() << endl;
//	cout << "v的大小为:" << v.size() << endl;
//}
//
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}