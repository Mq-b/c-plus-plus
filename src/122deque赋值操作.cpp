//#include<iostream>
//using namespace std;
//#include<deque>
//
////deque容器赋值操作
//
//void printDepue(const deque<int>& v)
//{
//	for (deque<int>::const_iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	deque<int>d1;
//	for (int i = 0; i < 10; i++)
//	{
//		d1.push_back(i);
//	}
//	printDepue(d1);
//
//	//operator=赋值
//	deque<int>d2;
//	d2 = d1;
//	printDepue(d2);
//
//	//assgin赋值
//	deque<int>d3;
//	d3.assign(d1.begin(), d1.end());
//	printDepue(d3);
//
//	deque<int>d4;
//	d4.assign(10, 100);
//	printDepue(d4);
//}
//int main()
//{
//	test01();
//	return 0;
//}