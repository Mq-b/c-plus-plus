//#include<iostream>
//using namespace std;
//#include<map>
////map容器构造和赋值
//void printMap(map<int, int>& m)
//{
//	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << "key=" << it->first << "value=" << it->second << endl;
//	}
//	cout << endl;
//}
//
//void test01()
//{
//	//创建map容器
//	map<int, int>m;
//
//	m.insert(pair<int, int>(1, 10));//匿名对组
//	m.insert(pair<int, int>(3, 30));
//	m.insert(pair<int, int>(2, 20));
//	m.insert(pair<int, int>(4, 40));
//
//	printMap(m);//插入后自动排序，输出的是升序
//
//	//拷贝构造
//	map<int,int>m2(m);
//	printMap(m2);
//
//	//赋值
//	map<int, int>m3;
//	m3 = m2;
//	printMap(m3);
//}
//int main()
//{
//	test01();
//	return 0;
//}
////map中所有元素都是pair
////pair中第一个元素为key(键值),起到索引作用,第二个元素为value(实值)
////所有元素都会根据元素的键值自动排序
////map/numltimap属于关联式容器,底层结构是二叉树实现
////map不允许容器中有重复的key值
////multimap允许容器中有重复key值元素