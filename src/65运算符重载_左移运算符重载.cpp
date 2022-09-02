//#include<iostream>
//using namespace std;
////左移运算符重载
//
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);//全局函数访问类内私有，friend加上函数声明
//public:
//	Person(int a, int b)//构造你函数
//	{
//		m_A = a;
//		m_B = b;
//	}
//private:
//	//利用成员函数重载左移运算符	p.operator<<(cout) 简化版本p<<cout
//	//不会利用成员函数重载<<运算符，因为无法实现cout在左侧
//	void operator<<(Person& p)
//	{
//	}
//	int m_A;
//	int m_B;
//};
//
////只能利用全局函数重载左移运算符
////void operator<<(ostream& cout, Person& p)//本质operator<<(cout,p)	简化cout<<p
////{
////	cout << "m_A=" << p.m_A << " m_B=" << p.m_B << endl;
////}
//
////cout是左操作数所以一个参数是ostream& ，右操作数是你需要打印的类数据成员
//ostream & operator<<(ostream& cout, Person& p)//本质operator<<(cout,p)	简化cout<<p
//{
//	cout << "m_A=" << p.m_A << " m_B=" << p.m_B << endl;
//	return cout;
//}
//void test01()
//{
//	Person p(10,10);
//	cout << p << p << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}