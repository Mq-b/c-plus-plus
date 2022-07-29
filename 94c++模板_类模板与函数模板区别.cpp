//#include<iostream>
//using namespace std;
//#include<string>
//
////类模板与函数模板区别
//template<class NameType,class AgeType=int>//类型默认参数，只有类模板才有
//class Person
//{
//public:
//	Person(NameType name, AgeType age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//
//	void showPerson()
//	{
//		cout << "name="<<m_Name << "age=" << m_Age << endl;//加不加this指针实际是一个意思
//	}
//	NameType m_Name;
//	AgeType m_Age;
//};
////1、类模板没有自动推导类型使用方式
//void test01()
//{
//	//Person p("孙悟空", 1000); 错误，无法用自动类型推导
//
//	Person<string>p("孙悟空", 9999);
//	p.showPerson();
//}
////2、类模板在模板参数列表可以有默认参数
//
//int main()
//{
//	test01();
//	return 0;
//}