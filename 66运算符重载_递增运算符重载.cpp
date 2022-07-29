//#include<iostream>
//using namespace std;
////重载递增运算符
//
////自定义整形
//class Myinteger
//{
//	friend ostream& operator<<(ostream&, Myinteger myint);
//	friend void test01();
//	friend void test02();
//public:
//	Myinteger()
//	{
//		m_Num = 0;
//	}
//	//重载++运算符
//
//	//重载前置++运算符
//	Myinteger& operator++()//返回引用是为了一直对一个数据进行操作
//	{
//		//先自增
//		m_Num++;
//		//返回自身
//		return *this;
//	}
//	//重载后置++运算符
//	Myinteger operator++(int)//int代表占位参数，可以区分前置和后置
//	{
//		//先 记录当时结果
//		Myinteger temp = *this;
//		//后 递增
//		m_Num++;
//		//最后讲记录的结果做返回
//		return temp;
//	}
//private:
//	int m_Num;
//};
////重载左移运算符
//ostream& operator<<(ostream&, Myinteger myint)
//{
//	cout << myint.m_Num;
//	return cout;
//}
////void test01()//前置
////{
////	Myinteger myint;
////	myint.m_Num = 20;
////	cout << myint << endl;
////	cout << ++(++myint)<< endl;
////}
//
//void test02()//后置
//{
//	Myinteger myint;
//	cout<<myint++<< endl;
//	cout << myint << endl;
//}
//int main()
//{
//	//test01();
//	test02();
//}