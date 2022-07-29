//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>//提供sort算法
//#include<functional>//提供内置仿函数
////关系仿函数
//
////大于 greater
//class MyCompare
//{
//public:
//	bool operator()(int v1, int v2)//使用自己写仿函数的方法
//	{
//		return v1 > v2;
//	}
//};
//void test01()
//{
//	vector<int>v;
//
//	v.push_back(10);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(20);
//	v.push_back(50);
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	//降序
//	//sort(v.begin(), v.end(), MyCompare());//使用自己写的仿函数，方法1
//	//gerator<int>();
//	sort(v.begin(), v.end(), greater<int>());//库仿函数是模板得添加类型，方法2常用
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//}
//int main()
//{
//	test01();
//	return 0;
//}
////关系仿函数中最常用的就是greator<>大于