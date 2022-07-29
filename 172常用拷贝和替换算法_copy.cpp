//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////常用拷贝和替换算法
//void myPrint(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//
//	vector<int>v2;
//	v2.resize(v1.size());
//	copy(v1.begin(), v1.end(), v2.begin());
//
//	for_each(v2.begin(), v2.end(), myPrint);
//}
//
//int main()
//{
//	test01();
//	return 0;
//}
////利用copy算法在拷贝时，目标容器记得开辟空间
////其实可以直接使用=赋值，没必要特意使用这个