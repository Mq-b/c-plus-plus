//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
////常用集合算法 set_difference
//void Print(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//	//创建目标容器
//	vector<int>vTarget;
//	//给目标容器开辟空间
//	//两个容器没有一点交集 取两个容器中大的size作为目标开辟空间
//	vTarget.resize(max(v1.size(),v2.size()));
//
//	cout << "v1和v2的差集为:" << endl;
//	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for_each(vTarget.begin(), itEnd,Print);
//	cout << endl;
//
//	cout << "v2和v1的差集为:" << endl;//代码复用
//	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
//	for_each(vTarget.begin(), itEnd, Print);
//}
//
//int main()
//{
//	test01();
//	return 0;
//}