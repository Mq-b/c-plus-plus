//#include<iostream>
//#include<string>
//using namespace std;
//
////成员变量和成员函数是分开存储的
//
//class Person
//{
//	int m_A;//非静态成员变量	属于类的对象上
//
//	static int m_B;//静态成员变量	不属于类的对象上
//
//	void func() {}//非静态成员函数	不属于类的对象上
//
//	static void func2() {}//静态的成员函数	不属于类的对象上
//};
//
//int Person::m_B=0;
//
//struct ave
//{
//	int m_A;//非静态成员变量;属于类的对象上
//
//	static int m_B;//静态成员变量，不属于类的对象上
//
//	void func() {}//非静态成员函数
//}a;
//void test01()
//{
//	Person p;
//	string r;
//	//空对象占用的内存空间为：0
//	//c++编译器给每个对象也分配一个字节空间，是为了区分空对象内存的位置
//	//每个空对象也应该有一个独一无二的内存地址
//	cout << "sizeof p=" << sizeof(p) << endl;
//	cout << "sizeof a=" << sizeof(a) << endl;//测试结构体
//	cout << "sizeof r=" << sizeof(r) << endl;//测试string
//}
//
//
//int main()
//{
//	test01();
//	return 0;
//}