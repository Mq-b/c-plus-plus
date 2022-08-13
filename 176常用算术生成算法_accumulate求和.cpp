//#include<iostream>
//using namespace std;
//#include<vector>
//#include<numeric>
//
////常用算术生成算法
//int main()
//{
//	vector<int>v;
//
//	for (int i = 0; i <= 100; i++)
//	{
//		v.push_back(i);
//	}
//
//	int total=accumulate(v.begin(), v.end(), 0);//0表示初始从0开始，没要求就0
//
//	cout << "total=" << total << endl;//计算总和，这里是1+到100的和就是5050
//	return 0;
//}

//#include<iostream>//计算数组的方式
//using namespace std;
//#include<numeric>//提供算法
//int main()
//{
//	int num[10] = { 1,2,3,4,5,6,7,8,9 ,10 };
//	int total = accumulate(num, num + 10, 0);//总和，计算数组的总和
//	cout << total << endl;
//}