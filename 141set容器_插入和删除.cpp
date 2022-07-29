//#include<iostream>
//using namespace std;
//#include<set>
//
////set容器 插入和删除
//void printSet(set<int>& s)
//{
//	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	set<int>s1;
//
//	//插入
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(40);
//
//	//遍历
//	printSet(s1);
//
//	//删除
//	s1.erase(s1.begin());//插入顺序没用，我们插入排序好删除第一个
//	printSet(s1);
//
//	//删除重载版本
//	s1.erase(30);
//	printSet(s1);
//
//	//清空
//	//s1.erase(s1.begin(), s1.end());//清空区间
//	
//	//清空的接口
//	s1.clear();
//	printSet(s1);
//}
//int main()
//{
//	test01();
//	return 0;
//}