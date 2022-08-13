//#include<iostream>
//using namespace std;
//#include<string>
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	//姓名
//	string m_name;
//	//年龄
//	int m_age;
//};
////模板的局限性
////模板并不是万能的，有些特定数据类型，需要用具体化方式做具体实现
//
////对比两个数据类型是否相等函数
//template<class T>
//bool myCompare(T& a, T& b)
//{
//	if (a == b)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
////利用具体化Person的版本实现代码，具体化优先调用
//template<> bool myCompare(Person& p1, Person& p2)
//{
//	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//void test01()
//{
//	int a = 10;
//	int b = 20;
//
//	bool ret = myCompare(a, b);
//	if (ret)
//	{
//		cout << "a==b" << endl;
//	}
//	else
//	{
//		cout << "a!=b" << endl;
//	}
//}
//
//void test02()
//{
//	Person p1("Tom", 10);
//	Person p2("Tom", 10);
//	bool ret = myCompare(p1, p2);
//	if (ret)
//	{
//		cout << "p1==p2" << endl;
//	}
//	else
//	{
//		cout << "p1!=p2" << endl;
//	}
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}