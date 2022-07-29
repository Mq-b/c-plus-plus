//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////常用排序算法 merge
////两个容器合并到一个容器中 注意两个容器都得是有序的
//
//void myPrint(int v)
//{
//	cout << v << " ";
//}
//
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 1);
//	}
//
//	//目标容器
//	vector<int>vTarget;
//
//	//提前给目标容器分配空间
//	vTarget.resize(v1.size() + v2.size());
//
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());//合并默认是升序,可以加谓词
//
//	for_each(vTarget.begin(), vTarget.end(), myPrint);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}