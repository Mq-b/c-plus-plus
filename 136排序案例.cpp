//#include<iostream>
//using namespace std;
//#include<string>
//#include<list>
//
////list容器 排序案例 对于自定义数据类型 做排序
//
////按照年龄进行排序，如果年龄相同，按照身高进行排序
//
//class Person
//{
//public:
//	Person(string name, int age, int height)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//		this->m_Height = height;
//	}
//	string m_Name;
//	int m_Age;
//	int m_Height;
//};
//
////指定排序规则
//bool comparePerson(Person& p1, Person& p2)
//{
//	//按照年龄 升序
//	if (p1.m_Age == p2.m_Age)
//	{
//		//年龄相同 按照身高排序
//		return p1.m_Height > p2.m_Height;//高的就排前面
//	}
//	else
//	{
//		//按照年龄升序
//		return p1.m_Age < p2.m_Age;//小于就是真，反之为假就排序，所以升序，也就是从小到大
//	}
//}
//
//void test01()
//{
//	list<Person>L;//创建容器
//
//	//准备数据
//	Person p1("刘备", 35, 175);
//	Person p2("曹操", 40, 180);
//	Person p3("孙权", 40, 170);
//	Person p4("赵云", 25, 190);
//	Person p5("张飞", 35, 160);
//	Person p6("关羽", 35, 200);
//
//	//插入数据
//	L.push_back(p1);
//	L.push_back(p2);
//	L.push_back(p3);
//	L.push_back(p4);
//	L.push_back(p5);
//	L.push_back(p6);
//
//	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
//	{
//		cout << "姓名: " << (*it).m_Name << "年龄: " << (*it).m_Age << "身高: " << (*it).m_Height << endl;
//	}
//
//	//排序
//	cout << "--------------------------" << endl;
//	cout << "排序后" << endl;
//	L.sort(comparePerson);
//
//	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
//	{
//		cout << "姓名: " << (*it).m_Name << "年龄: " << (*it).m_Age << "身高: " << (*it).m_Height << endl;
//	}
//}
//
//int main()
//{
//	test01();
//	return 0;
//}