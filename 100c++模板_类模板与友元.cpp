//#include<iostream>
//using namespace std;
//#include<string>
////通过全局函数 打印Person信息
//
////提前让编译器知道Person类的存在
//template<class T1, class T2>
//class Person;
////类外实现得先写在前面
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>p)
//{
//	cout << "类外实现---姓名:" << p.m_Name << "年龄:" << p.m_Age << endl;
//}
//
//template<class T1,class T2>
//class Person
//{
//	//全局函数 类内实现
//	//以前学友元的时候都是在这里加一个声明，在无访问权限的地方；
//	//现在是直接类内实现了，看起来像成员函数，实际上没有访问权限，是全局函数
//	friend void printPerson(Person<T1, T2>p)
//	{
//		cout << "姓名:" << p.m_Name << "年龄:" <<p.m_Age << endl;
//	}
//
//	//全局函数 类外实现
//	//加一个空模板参数列表
//	//如果我们全局函数是类外实现，需要让编译器提起知道这个函数的存在
//	friend void printPerson2<>(Person<T1, T2>p);
//
//public:
//
//	Person(T1 name, T2 age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//private:
//	T1 m_Name;
//	T2 m_Age;
//};
//
//
////1、全局函数在类内实现
//void test01()
//{
//	Person<string, int>p("Tonm", 20);
//	printPerson(p);
//}
//
////2、全局函数在类外实现
//void test02()
//{
//	Person<string, int>P("牛马", 118);
//	printPerson2(P);
//}
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}
////建议全局函数做类内实现，用法简单，而且编译器可以直接识别