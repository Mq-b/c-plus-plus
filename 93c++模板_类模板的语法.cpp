//#include<iostream>
//using namespace std;
//#include<string>
//
////类模板
//template<class NameType, class AgeType>
//class Person
//{
//public:
//	Person(NameType name, AgeType age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	void showPerson()
//	{
//		cout << "name=" << this->m_Name << "age=" << this->m_Age << endl;
//	}
//
//	NameType m_Name;
//	AgeType m_Age;
//};
//
//void test01()
//{
//	//<>这个括号内的是模板参数列表
//	Person<string, int> p1("孙悟空", 999);
//	p1.showPerson();
//}
//int main()
//{
//	test01();
//	return 0;
//}
////类模板和函数模板语法极其相似，在声明template后面加类，此类称为类模板