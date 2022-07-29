//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int m_age)
//	{
//		//this指针指向的是被调用的成员函数所属的对象
//		this->Age = m_age;//(*this).m_Age = age;也行
//	}
//	Person& personAddAge(Person &p)
//	{
//		this->Age += p.Age;
//		//this指向p2的指针，而*this指向的就是p2这个对象的本体
//
//		return *this;//*this指向本体
//	}
//	int Age;
//};
////1.解决名称冲突
//void test01()
//{
//	Person p1(10);
//
//	Person p2(10);
//	//链式编程思想
//	p2.personAddAge(p1).personAddAge(p1).personAddAge(p1).personAddAge(p1);
//	cout << "p1的年龄为:" << p1.Age << endl;
//
//	cout << "p2的年龄为:" << p2.Age << endl;
//}
////2.返回对象本身用*this
//int main()
//{
//	test01();
//	return 0;
//}