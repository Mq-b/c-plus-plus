//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<string>
//
////1、统计内置的数据类型
//void test01()
//{
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(40);
//	v.push_back(40);
//
//	int num = count(v.begin(), v.end(), 40);
//
//	cout << "40的元素个数为" << num << endl;
//}
//
////2、统计自定义数据类型
//
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//	bool operator==(const Person& v)
//	{
//		return this->m_Age == v.m_Age;//==满足就是真
//	}
//	string m_Name;
//	int m_Age;
//};
//
//void test02()
//{
//	vector<Person>v;
//
//	Person p1("刘备", 35);
//	Person p2("刘备", 35);
//	Person p3("刘备", 35);
//	Person p4("刘备", 30);
//	Person p5("刘备", 40);
//
//	Person p("诸葛亮", 35);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//
//
//	int num = count(v.begin(), v.end(), p);//记得重载==让底层代码识别自定义数据类型
//
//	cout << "和诸葛亮相同岁数的人数是:" << num << endl;
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}
////统计相同条件元素出现次数