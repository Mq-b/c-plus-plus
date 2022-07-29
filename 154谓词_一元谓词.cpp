//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////仿函数 返回值类型是bool数据类型，称为谓词
////一元谓词
//
//class GreaterFive
//{
//public:
//	bool operator()(int val)
//	{
//		return val > 5;//大于5即为真
//	}
//};
//
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	//查找容器中 有没有大于5的数字
//	//GreaterFive()匿名函数对象
//	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
//	if (it == v.begin())
//	{
//		cout << "未找到" << endl;
//	}
//	else
//	{
//		cout << "找到了大于5的数字为:" << *it << endl;//结果是6，6是第一个大于5的数
//	}
//}
//
//int main()
//{
//	test01();
//	return 0;
//}
////参数只有一个的谓词，称为一元谓词