//#include<iostream>
//using namespace std;
//
////深拷贝与浅拷贝
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person的默认构造函数调用" << endl;
//	}
//	Person(int age,int height)
//	{
//		m_age = age;
//		m_Height= new int(height);
//		cout << "Person的有参构造函数调用" << endl;
//	}
//	//自己实现拷贝构造函数解决浅拷贝带来的问题
//	Person(const Person& p)
//	{
//		cout << "Person拷贝构造函数调用" << endl;
//		m_age = p.m_age;
//		//m_Height=p.m_Height;编译器默认实现的=就是运行这行代码
//		//深拷贝操作
//
//		m_Height = new int(*p.m_Height);
//	}
//	~Person()
//	{
//		//析构代码，将堆区开辟的数据做释放操作
//		if (m_Height != NULL)
//		{
//			delete m_Height;
//			m_Height = NULL;
//		}
//
//		cout << "Person的析构构造函数调用" << endl;
//	}
//	int m_age;//年龄
//	
//	int* m_Height;
//};
//
//void test01()
//{
//	Person p1(18,160);
//	cout << "p1的年龄是:" << p1.m_age <<"p1的身高是:"<<*p1.m_Height <<endl;
//	Person p2(p1);
//	cout << "p1的年龄是:" << p2.m_age << "p1的身高是:" << *p1.m_Height <<endl;
//	
//}
//int main()
//{
//	test01();
//	return 0;
//}