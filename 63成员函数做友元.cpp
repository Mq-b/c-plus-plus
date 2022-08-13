//#include<iostream>
//#include<iostream>
//using namespace std;
//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit();//让visit函数可以访问Building中私有成员
//	void visit2();//让visit2函数不可以访问Building中私有成员
//	Building* building;
//};
//
//class Building
//{
//	//告诉编译器	GoodGay类下的visit成员函数作为本类的好朋友，可以访问私有成员
//	friend void GoodGay::visit2();
//public:
//	Building();
//public:
//	string m_SittingRoom;//客厅
//private:
//	string m_BedRoom;//卧室
//};
//
////类外实现成员函数
//
//Building::Building()
//{
//	m_SittingRoom = "客厅";
//	m_BedRoom = "卧室";
//}
//
//GoodGay::GoodGay()
//{
//	building = new Building;
//}
//
//void GoodGay:: visit()
//{
//	cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
//}
//
//void GoodGay::visit2()
//{
//	cout << "visit2函数正在访问：" << building->m_BedRoom << endl;
//}
//
//void test01()
//{
//	GoodGay gg;
//	gg.visit();
//	gg.visit2();
//}
//int main()
//{
//	test01();
//	return 0;
//}

//自己实现
//#include<iostream>
//#include<string>
//class Father;
//class Son
//{
//public:
//	Son();
//	void print();
//	~Son();
//	Father* father;
//private:
//	int m_Age;
//	std::string m_Name;
//};
//class Father
//{
//	friend void Son::print();
//public:
//	Father()
//	{
//		this->_m_Age = 0;
//		this->_m_Name = "";
//	}
//private:
//	int _m_Age;
//	std::string _m_Name;
//};
//
//Son::Son()
//{
//	this->m_Age = 0;
//	this->m_Name = "";
//	this->father = new Father;
//}
//void Son::print()
//{
//	std::cout << this->father->_m_Age << " " << this->father->_m_Name << std::endl;
//}
//Son::~Son()
//{
//	delete this->father;
//}
//int main()
//{
//	Son son;
//	son.print();
//}
////成员函数做友元函数需要有几个条件，首先在类中创建另一个类的成员函数需要先声明那个类，然后先创建需要访问另一个类。
////因为先创建它，编译器才能识别友元，然后创建另一个类，注意得类外实现，因为必须先创建好那个类，编译器才知道怎么访问