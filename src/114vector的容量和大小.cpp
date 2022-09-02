//#include<iostream>
//using namespace std;
//#include<vector>
//
//void printVector(vector<int>v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
////veector的容和大小
//void test01()
//{
//	vector<int>v1;
//	for (int i=0;i<10;i++)
//	{
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	if (v1.empty())//为真 代表容器为空，emptp判断是否为空
//	{
//		cout << "v1为空" << endl;
//	}
//	else
//	{
//		cout << "v1不为空" << endl;
//		cout << "v1的容量为:" << v1.capacity() << endl;//capacity返回容器容量
//		cout << "v1的大小为:" << v1.size() << endl;//size返回元素个数
//	}
//
//	//resize重新指定大小
//	v1.resize(15);
//	printVector(v1);//如果重新指定的比原来更长了，默认0填充
//
//	v1.resize(10);//大小变回10
//
//	v1.resize(15, 100);//重载版本，指定用100填充，而不是默认0
//	printVector(v1);
//
//	v1.resize(5);
//	printVector(v1);//如果指定的比原来短，超出部分删除掉
//}
//int main()
//{
//	test01();
//	return 0;
//}