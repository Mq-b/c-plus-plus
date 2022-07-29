//#include <numeric>
//#include <vector>
//#include <algorithm>
//#include<iostream>
//using namespace std;
//class myPrint
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//};
//
//void test01()
//{
//
//	vector<int> v;
//	v.resize(10);
//	//填充
//	fill(v.begin(), v.end(), 100);
//
//	for_each(v.begin(), v.end(), myPrint());//遍历输出
//	cout << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}
//对数组操作
//#include <numeric>//提供fill算法
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[10] = { 0 };
//	fill(a, a + 10,1000);//填充函数
//	for (int i = 0; i < 10; i++)cout << a[i] << " ";
//}
//利用fill将容器区间内元素填充为指定的值