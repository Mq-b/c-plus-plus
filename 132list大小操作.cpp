//#include<iostream>
//using namespace std;
//#include<list>
//
////list容器大小操作
//
//void printlist(const list<int>& L)
//{
//	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01()
//{
//	list<int>L1;
//	L1.push_back(10);
//	L1.push_back(20);
//	L1.push_back(30);
//	L1.push_back(40);
//
//	printlist(L1);
//
//	//判断容器是否为空
//	if (L1.empty())
//	{
//		cout << "L1为空" << endl;
//	}
//	else
//	{
//		cout << "容器不为空" << endl;
//		cout << "L1的元素个数为:" << L1.size() << endl;
//	}
//
//	//重新指定大小
//	L1.resize(10,10000);
//	printlist(L1);
//
//	L1.resize(2);
//	printlist(L1);
//}
//int main()
//{
//	test01();
//	return 0;
//}
////判断是否能为空--empty
////返回元素个数--size
////重新指定个数--resize