//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
////常用遍历算法for_each
//
////普通函数
//void print01(int val)
//{
//	cout << val << " ";
//}
////仿函数
//class print02
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//};
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	for_each(v.begin(), v.end(), print01);//普通函数只需要函数名
//	cout << endl;
//
//	for_each(v.begin(), v.end(), print02());//仿函数需要()
//	cout << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}
////for_each在实际开发中是最常用遍历算法，需要熟练掌握