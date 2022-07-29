//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
////常用集合算法 set_intersection 交集
//void Print(int val)
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
//
//	vector<int>vTarget;
//	//目标容器需要提前开辟空间
//	//最特殊的情况 两个大容器包含小容器 开辟空间 取小容器 取小容器的size即可
//	vTarget.resize(min(v1.size(), v2.size()));//min使用库函数
//
//	//获取交集,迭代器接收返回的交集的最后一个元素的位置
//	vector<int>::iterator inEnd = set_intersection(v1.begin(), v1.end(), v2.begin(),v2.end(),vTarget.begin());
//	for_each(vTarget.begin(), inEnd, Print);//遍历输出
//}
//int main()
//{
//	test01();
//	return 0;
//}
////给目标容器分配内存的时候分配两个容器中较小的
////返回值是交集中最后一个元素的位置