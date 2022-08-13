//#include<iostream>
//using namespace std;
//#include<deque>
//#include<algorithm>//标准算法头文件
//void printDeque(const deque<int>&v)
//{
//	for (deque<int>::const_iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01()
//{
//	deque<int>d;
//	d.push_back(10);
//	d.push_back(20);
//	d.push_back(30);
//	d.push_front(100);
//	d.push_front(200);
//	d.push_front(300);
//
//	printDeque(d);
//
//	//排序	默认从小到大 升序
//	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接进行排序
//	sort(d.begin(), d.end());
//	cout << "排序后" << endl;
//	printDeque(d);
//}
//
//int main()
//{
//	test01();
//	string a;
//	return 0;
//}
////sort排序算法非常实用