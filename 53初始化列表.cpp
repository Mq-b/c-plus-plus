//#include<iostream>
//using namespace std;
//
////初始化列表
//class Person
//{
//public:
//	//传统赋初值操作
//	Person(int a, int b, int c)//第一种
//	{
//		m_A = a;
//		m_B = b;
//		m_C = c;
//	}
//	int m_A;
//	int m_B;
//	int m_C;
//
//	//初始化列表初始属性
//	Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c)//第二种
//	{
//
//	}
//};
//
//void test01()
//{
//	//Person p(10, 20, 30);//调用第一种
//	Person p(30,20,10);//调用第二种
//	cout << "m_A=" << p.m_A << endl;
//	cout << "m_B=" << p.m_B << endl;;
//	cout << "m_B=" << p.m_C << endl;
//
//}
//int main()
//{
//	test01();
//}