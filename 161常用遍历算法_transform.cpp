//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
//class Transform
//{
//public:
//	int operator()(int v)
//	{
//		return v;
//	}
//};
//
//class MyPrint
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
//	vector<int>vTarget;//目标容器
//	vTarget.resize(v.size());//目标容器需要提前开辟空间
//
//	transform(v.begin(), v.end(), vTarget.begin(), Transform());//搬运期间也可以做运算
//
//	for_each(vTarget.begin(), vTarget.end(), MyPrint());
//	cout << endl;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}
//就是把一个容器搬运到另一个容器