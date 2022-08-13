//#include<iostream>
//using namespace std;
//#include <deque>
////deque 构造函数
//void printDeque(const deque<int>& d)//const修饰容器，变成只读，无法修改
//{
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//迭代器也得const_修饰
//	{
//		//*it = 100;//容器数据无法修改
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01()
//{
//	deque<int>d1;
//	for (int i = 0; i < 10; i++)
//	{
//		d1.push_back(i);
//	}
//	printDeque(d1);
//
//	deque<int>d2(d1.begin(), d1.end());
//	printDeque(d2);
//
//	deque<int>d3(10, 100);//10个100
//	printDeque(d3);
//
//	deque<int>d4(d3);
//	//d4 = d3;//一个意思
//	printDeque(d4);
//}
//
//int main()
//{
//	test01();
//	return 0;
//}