//#include<iostream>
//using namespace std;
//
////类模板中成员函数创建时机
////类模板中成员函数在调用时才去创建
//
//class Person
//{
//public:
//	void showPerson()
//	{
//		cout << "Person show" << endl;
//	}
//};
//
//class Person2
//{
//public:
//	void showPerson2()
//	{
//		cout << "Person2 show" << endl;
//	}
//};
//template<class T>
//class MyClass
//{
//public:
//	T obj;
//
//	//类模板中的成员函数
//	void func1()
//	{
//		obj.showPerson();
//	}
//	void func2()
//	{
//		obj.showPerson2();
//	}
//};
//
//void test01()
//{
//	MyClass<Person>m;//模板的参数列表是Person表示这个类的类型是Person
//	m.func1();
//	//m.func2();不能调用起这个是因为，func2是Person2类型的
//}
//int main()
//{
//	test01();
//	return 0;
//}
////模板类不是类，模板函数也不是函数，只有在施加模板参数后才会具体化
//类模板中的成员函数并不是一开始就创建的，在调用时才去创建