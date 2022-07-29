//#include<iostream>
//using namespace std;
//#include<vector>
//#include<string>
//
////vector容器中存放自定义数据类型
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//	string m_Name;
//	int m_Age;
//};
//
//void test01()
//{
//	vector<Person>v;
//
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	Person p5("ttt", 50);
//
//	//向容器中添加数据
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//
//	//遍历容器中的数据
//	//it是指针，一个地址，指向容器中第一个元素
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名:" << it->m_Name << "年龄:" << (*it).m_Age << endl;//一个意思，清楚本质就行
//	}
//}
//
////存放自定义数据类型指针
//void test02()
//{
//	vector<Person*>v;
//
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	Person p5("ttt", 50);
//
//	//向容器中添加数据
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//
//	//遍历容器中的数据
//	//it是一个指针，默认创建1级，但是<Person*>类型，让it变成二级指针
//  //这条语句定义了一个名为it的变量，它的数据类型是由vector<int>定义的iterator类型。
//	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名:" << (*it)->m_Name << "年龄:" << (*it)->m_Age << endl;//二级指针
//	}
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}