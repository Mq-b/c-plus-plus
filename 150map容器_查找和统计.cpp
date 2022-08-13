//#include<iostream>
//using namespace std;
//#include<map>
//
////map容器查找和统计
//void test01()
//{
//	//查找
//	map<int, int>m;
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int, int>(2, 20));
//	m.insert(pair<int, int>(3, 30));
//
//	map<int, int>::iterator pos = m.find(3);
//
//	if (pos != m.end())
//	{
//		cout << "查到了元素key=" << pos->first << " value=" << pos->second << endl;
//	}
//	else
//	{
//		cout << "未找到元素" << endl;
//	}
//
//	//统计
//	//map容器不允许插入重复key元素,cout统计而言 结果要嘛是0要嘛是1
//	//mulitmap的count统计可能大于1
//
//	int num =  m.count(3);
//	cout << "num=" << num << endl;//1/0
//}
//int main()
//{
//	test01();
//	return 0;
//}
////查找find返回的是迭代器
////统计count对于map，结果为0