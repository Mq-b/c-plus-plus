//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<ctime>
//
//void myPrint(int val)
//{
//	cout << val << " ";
//}
//
////常用排序算法 random_shuffle
//void test01()
//{
//	srand((unsigned int)time(NULL));//提供真随机
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	//利用洗牌 算法 打乱排序
//	random_shuffle(v.begin(), v.end());
//
//	for_each(v.begin(), v.end(),myPrint);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}
//random_shuffle 洗牌算法比较实用，使用时记得加随机数种子