//#include<iostream>
//using namespace std;
////构造函数的调用规则
////1.创建一个类，c++编译器会给每个类都添加至少三个函数
////默认构造（空实现）
////析构函数（空实现）
////拷贝构造（值拷贝）
//
////2.如果我们写了有参构造函数，编译器不再提供默认构造，依旧提供拷贝构造
////如果我们写了拷贝构造函数，编译器就不再提供其他的普通构造函数
//
////总结 我写有参构造函数，编译器不提供默认构造函数；我写拷贝构造函数，编译器不提供剩下两个
//class Person
//{
//
//public:
//	/*Person()
//	{
//		cout << "Person的默认构造函数调用" << endl;
//	}*/
//	Person(int age)
//	{
//		m_Age = age;
//		cout << "Person的有参构造函数调用" << endl;
//	}
//	~Person()
//	{
//		cout << "Person的构析函数调用" << endl;
//	}
//	/*Person(const Person& p)
//	{
//		cout << "Person的拷贝构造函数调用" << endl;
//		m_Age = p.m_Age;
//	}*/
//	int m_Age;
//};
////void test01()
////{
////	Person p;
////	p.m_Age = 18;
////	Person p2(p);
////
////	cout << "p2的年龄为:" << p2.m_Age << endl;
////}
//
//void test02()
//{
//	Person p(18);
//	Person p2(p);
//	cout << "p2的年龄为:" << p2.m_Age << endl;
//}
//int main()
//{
//	test02();
//	return 0;
//}