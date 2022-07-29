//#include<iostream>
//using namespace std;
//#include<deque>
////deque容器大小操作
//void printDeque(const deque<int>& v)
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
//	deque<int>d1;
//	for (int i = 0; i < 10; i++)
//	{
//		d1.push_back(i);
//	}
//	printDeque(d1);
//
//	if (d1.empty())//empty如果容器为空，那么就返回真
//	{
//		cout << "d1为空" << endl;
//	}
//	else
//	{
//		cout << "d1不为空" << endl;
//		cout << "d1的大小为:" << d1.size() << endl;
//		//deque容器没有容量的概念
//	}
//
//	//重新指定大小
//	d1.resize(15, 1);//重载版本,指定大小为15，大于的部分用1补上，默认是0
//	printDeque(d1);
//
//	d1.resize(5);//指定为大小5,超出的删除
//	printDeque(d1);
//}
//int main()
//{
//	test01();
//	return 0;
//}
////deque容器没有容量的概念
////判断是否为空--empty
////返回元素个数--size
////重新指定个数--resize