//#include<iostream>
//using namespace std;
//#include<functional>//内建函数对象头文件
//
////内建函数对象 算数仿函数
//
////negate 一元仿函数 取反仿函数
//void test01()
//{
//	negate<int>n;
//
//	cout << n(50) << endl;
//}
//
////plus 二元仿函数 加法
//void test02()
//{
//	plus<int>p;
//	cout << p(10, 20) << endl;
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}
////仿函数的本质是类，是类的成员函数重载了()
////加上模板，实际是类模板，这里用的是封装好的库
////使用内建函数对象时，需要引入头文件