//#include<iostream>
//using namespace std;
////加号运算符重载
//
////1.成员函数重载+号
//class Person
//{
//public:
//	/*Person operator+(Person& p)
//	{
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}*/
//	int m_A;
//	int m_B;
//};
////2.全局函数重载+号
//Person operator + (Person & p1, Person & p2)
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
////函数重载的版本
//Person operator+(Person& p1, int num)
//{
//	Person temp;
//	temp.m_A = p1.m_A + num;
//	temp.m_B = p1.m_B + num;
//	return temp;
//}
//void test01()
//{
//	Person p1;
//	p1.m_A = 100;
//	p1.m_B = 20;
//	Person p2;
//	p2.m_A = 10;
//	p2.m_B = 30;
//
//	Person p3 = p1 + p2;
//	/*成员函数的重载等价于：p1.operator+(p2)
//	实际上就是p1成员调用自己类内成员函数，因为是p1本身，
//	所以this指针自己访问自己就可以读取p1的数据了，然后靠传递的p2，就可以相加了
//	+是函数的别名其实，operator是一个关键字*/
//
//	//全局函数重载的本质调用:Person p3=operator+(p1,p2);
//
//	//运算符重载，也可以发生函数重载
//	Person p4; p4.m_A = 0; p4.m_B = 0;
//	p4 = p4+ 30;
//
//	/*cout << "P3m_A=" << p3.m_A << endl;
//	cout << "P3m_B=" << p3.m_B << endl;*/
//
//	cout << "P4m_A=" << p4.m_A << endl;
//	cout << "P4m_B=" << p4.m_B << endl;
//
//}
//
//int main()
//{
//	test01();
//	return 0;
//}