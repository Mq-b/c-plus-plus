//#include<iostream>
//using namespace std;
//#include<string>
//
//#include"99.1person.cpp"//第一种解决办法
//
////第二种解决办法，将我们的.h和.cpp中的内容写在一起，将后缀名改为.hpp文件
//#include"person.hpp"
//
////类模板分文件编写问题以及解决
//
////template<class T1,class T2>
////class Person
////{
////public:
////	Person(T1 name, T2 age);
////
////	void showPerson();
////
////	T1 m_Name;
////	T2 m_Age;
////
////};
//
////template<class T1,class T2>
////Person<T1,T2>::Person(T1 name, T2 age)
////{
////	this->m_Name = name;
////	this->m_Age = age;
////}
////
////template<class T1, class T2>
////void Person<T1,T2>::showPerson()
////{
////	cout << "姓名:" << this->m_Name << "年龄:" << this->m_Age << endl;
////}
//
//void test01()
//{
//	Person<string, int>p("傻子", 18);
//	p.showPerson();
//}
//int main()
//{
//	test01();
//	return 0;
//}
////已经把类和实现写在hpp文件，注释掉的不用恢复