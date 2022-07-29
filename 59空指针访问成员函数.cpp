//#include<iostream>
//using namespace std;
////空指针调用成员函数
//
//class Person
//{
//public:
//	void showClassName()
//	{
//		cout << "this is Person class" << endl;
//	}
//	void showPersonAge()
//	{
//		//报错原因因为传入的指针是为NULL;
//		if (this == NULL)//防止出错
//		{
//			return;
//		}
//		cout << "age=" << this->m_Age << endl;//this是空指针
//	}
//	int m_Age;
//};
//
//void test01()
//{
//	Person* p = NULL;
//	p->showClassName();
//	p->showPersonAge();
//}
//int main()
//{
//	test01();
//}