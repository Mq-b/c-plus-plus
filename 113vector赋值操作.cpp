//#include<iostream>
//using namespace std;
//#include<vector>
//
//void printVector(vector<int>v1)
//{
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
////vector赋值操作
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	//赋值 operator=
//	vector<int>v2;
//	v2 = v1;
//	printVector(v2);
//
//	//assign
//	vector<int>v3;
//	v3.assign(v1.begin(), v1.end());//范围赋值行为
//	printVector(v3);
//
//	//n个elem方式赋值
//	vector<int>v4;
//	v4.assign(10, 100);
//	printVector(v4);
//}
//int main()
//{
//	test01();
//	return 0;
//}