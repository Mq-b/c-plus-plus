//#include<iostream>
//#include<string>
//using namespace std;
////类对象作为类成员
////手机类
//class Phone
//{
//public:
//	Phone(string Pname)
//	{
//		cout << "Phone构造函数调用" << endl;
//		m_Pname= Pname;
//	}
//	~Phone()
//	{
//		cout << "Phone的析构函数调用" << endl;
//	}
//	//手机名称
//	string m_Pname;
//};
//
////人类
//class Person {
//public:
//	//Phone m_Phone=pName    隐式转换法
//	Person(string name, string pName) :m_Name(name), m_Phone(pName)//初始化列表
//	{
//		cout << "Person构造函数调用" << endl;
//	}
//	~Person()
//	{
//		cout << "Person的析构函数调用" << endl;
//	}
//	string m_Name;
//	Phone m_Phone;
//};
////当其他的类作为本类成员，构造的时候先构造类对象，再构造自身，析构顺序与构造顺序相反
////栈，先入后出，后入先出
//void test01()
//{
//	Person p("张三", "苹果13远峰蓝1tb");
//	cout << p.m_Name << "拿着" << p.m_Phone.m_Pname << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}