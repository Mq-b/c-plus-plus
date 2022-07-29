//#include<iostream>
//using namespace std;
//#include<set>
//
////set容器 查找和统计
//
//void test01()
//{
//	//查找
//	set<int>s1;
//
//	//插入数据
//
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(40);
//	//auto是c++的自动推测数据类型关键字,这里auto等同于set<int>::iterator
//	auto pos=s1.find(300);//find查找函数会返回一个迭代器
//
//	if (pos != s1.end())//如果迭代器指向的是end()就是没找到
//	{
//		cout << "找到元素" << *pos << endl;
//	}
//	else
//	{
//		cout << "未找到元素" << endl;
//	}
//}
//
////统计
//void test02()
//{
//	set<int>s1;
//
//	//插入数据
//
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(40);
//	//统计30的个数
//	int num = s1.count(30);
//	//对于set而言，统计的结果要嘛是0，要嘛是1，因为set不允许插入重复的数据
//	cout << "num=" << num << endl;
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}
////find()查找
////count()统计