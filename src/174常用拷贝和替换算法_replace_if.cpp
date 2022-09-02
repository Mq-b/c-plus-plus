//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>//o戈瑞怎
//
//class MyPrint
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//};
//class Great30
//{
//public:
//	bool operator ()(int val)//谓词
//	{
//		return val >= 30;
//	}
//};
////常用拷贝和替换算法 replace_if
//void test01()
//{
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(40);
//	v.push_back(20);
//	v.push_back(50);
//	v.push_back(20);
//	v.push_back(30);
//	
//
//	cout << "替换前" << endl;
//	for_each(v.begin(), v.end(), MyPrint());//其实使用仿函数或者函数做参数没有区别，都可以
//	cout << endl;
//	//将大于等于30 替换为3000
//	//replace_if与replace的区别就是第三个参数，前者使用谓词表示区间的真假，后者只能使用具体值或对象
//	cout << "替换后" << endl;
//	replace_if(v.begin(), v.end(),Great30(),3000);
//
//	for_each(v.begin(), v.end(), MyPrint());//其实使用仿函数或者函数做参数没有区别，都可以
//}
//int main()
//{
//	test01();
//	return 0;
//}