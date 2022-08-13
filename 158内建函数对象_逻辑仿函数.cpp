//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<functional>
//
////内建函数对象_逻辑仿函数
////逻辑非 Iogical_not
//
//void test01()
//{
//	vector<bool>v;
//	v.push_back(true);
//	v.push_back(false);
//	v.push_back(true);
//	v.push_back(false);
//
//	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";//遍历v容器，与下面做对照
//	}
//	cout << endl;
//
//	//利用逻辑非 将容器v搬运到容器v2中，并执行取反操作
//	vector<bool>v2;
//	v2.resize(v.size());//目标容器v2需要提前开辟空间
//
//	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());//四个参数，需要搬运的容器的开始迭代器，结尾迭代器，搬运到模板的开始迭代器，最后一个内建仿函数，在搬运的过程中做操作
//	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
//	{
//		cout << *it << " ";//遍历输出v2
//	}
//	cout << endl;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}
////逻辑仿函数实际应用很少，了解即可