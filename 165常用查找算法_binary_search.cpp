//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////二分查找法
////速度很快，但是必须在有序的序列
//void test01()
//{
//	vector<int>v;
//
//	for (int i = 0; i < 10; i++)//插入的顺序是有序的  升序
//	{
//		v.push_back(i);
//	}
//	//二分查找
//	bool ret = binary_search(v.begin(), v.end(), 2);
//	if (ret)
//	{
//		cout << "找到了" << endl;
//	}
//	else
//	{
//		cout << "未找到" << endl;
//	}
//}
//
//int main()
//{
//	test01();
//	return 0;
//}
////如果无序，结果是未知