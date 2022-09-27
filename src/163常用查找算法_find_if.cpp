//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<string>
//
////常用查找算法find_if
//
////1、查找内置数据类型
//class GeraterFive
//{
//public:
//	bool operator ()(int v)
//	{
//		return v > 5;
//	}
//};
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	//使用auto C++自动推导，不然就要写vector<int>::iterator
//	auto it=find_if(v.begin(), v.end(), GeraterFive());
//	if (it == v.end())
//	{
//		cout << "未找到" << endl;
//	}
//	else
//	{
//		cout << "找到大于5的数字为" << *it << endl;
//	}
//}
////2、查找自定义数据类型
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//	int m_Age;
//	string m_Name;
//};
//class Greater20
//{
//public:
//	bool operator()(Person&p)
//	{
//		return p.m_Age > 20;
//	}
//};
//void test02()
//{
//	vector<Person>v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	//找年龄大于20的人
//	//使用auto C++自动推导，不然就要写vector<int>::iterator
//	auto it=find_if(v.begin(), v.end(), Greater20());
//	if (it == v.end())
//	{
//		cout << "没有找到" << endl;
//	}
//	else
//	{
//		cout << "找到了 姓名:" << it->m_Name << "年龄:" << it->m_Age << endl;
//	}
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}
