//#include<iostream>
//using namespace std;
//
////继承中的同名静态成员处理方式
//class Base
//{
//public:
//	static int m_A;
//
//	static void func()
//	{
//		cout << "Base-static void func()" << endl;
//	}
//	static void func(int a)
//	{
//		cout << "Base=" << a << endl;
//	}
//};
//int Base::m_A = 100;//静态成员要在外部初始化
//
//class Son :public Base
//{
//public:
//	static void func()
//	{
//		cout << "Son-static void func()" << endl;
//	}
//	static int m_A;
//};
//int Son::m_A = 200;
//
////同名静态成员属性
//void test01()
//{
//	//1.通过对象访问
//	Son s;
//	cout << "通过对象的访问" << endl;
//	cout << "Son m_A=" << s.m_A << endl;//200,打印的子类的
//	cout << "Base m_A=" << s.Base::m_A << endl;//100，加上了作用域打印的父类的
//	//2.通过类名访问
//	cout << "通过类名访问" << endl;
//	cout << "Son下m_A=" << Son::m_A << endl;
//	cout << "Base下m_A=" << Base::m_A << endl;
//	//第一个::代表通过类名的方式访问	第二个::代表访问父类作用域下
//	cout << "Base下m_A=" << Son::Base::m_A << endl;
//}
//
////同名静态成员函数
//void test02()
//{
//	//1.通过对象访问
//	cout << "通过对象访问" << endl;
//	Son s;
//	s.func();
//	s.Base::func();
//	//2.通过类名访问
//	cout << "通过类名访问" << endl;
//	Son::func();//访问子类
//	Son::Base::func();//通过子类访问父类
//	Base::func();//直接访问父类
//
//	//子类和父类出现同名静态成员函数，也会隐藏掉父类中所有同名成员函数
//	//如果想访问父类中被隐藏同名成员，需要加作用域
//	Son::Base::func(100);
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}
////同名静态成员处理方式和非静态一样，只不过有两种访问方式(通过对象和类名)
////非静态只能通过对象