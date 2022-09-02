//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
////常用的集合算法 set_union 并集
//void myPrint(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//	vector<int>vTarget;
//	//目标容器提前开辟空间
//	//最特殊情况 两个容器没有交集，并集就是两个容器size相加
//	vTarget.resize(v1.size()+v2.size());
//
//	vector<int>::iterator vEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for_each(vTarget.begin(), vEnd, myPrint);
//
//	cout << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}
////set_union返回值是并集中最后一个元素的位置