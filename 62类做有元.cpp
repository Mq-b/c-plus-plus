//#include<iostream>
//#include<string>
//using namespace std;
//
////类做友元
//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit();//参观函数，访问Building中的属性
//	~GoodGay()
//	{
//			cout << "析构函数" << endl;
//			if (building != NULL)
//			{
//				delete building;
//				building = NULL;
//			}
//	}
//	Building* building;
//};
//
//class Building
//{
//	//GoodGay类是本来的好朋友，可以访问本类私有成员
//	friend class GoodGay;
//public:
//	Building();
//	
//	string m_SittingRoom;//客厅
//private:
//	string m_BedRoom;//卧室
//
//};
//
////类外写成员函数
//
//Building::Building()//作用域
//{
//	m_SittingRoom = "客厅";
//	m_BedRoom = "卧室";
//}
//
//GoodGay::GoodGay()
//{
//	//创建一个建筑物对象
//	building = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "好基友类正在访问" << building->m_SittingRoom << endl;
//
//	cout << "好基友类正在访问" << building->m_BedRoom << endl;
//}
//
//void test01()
//{
//	GoodGay gg;
//	gg.visit();
//}
//int main()
//{
//	test01();
//	return 0;
//}