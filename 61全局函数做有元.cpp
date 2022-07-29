//#include<iostream>
//#include<string>
//using namespace std;
////建筑物类
//class Building
//{
//	//goodGay全局函数是Building好朋友，可以访问Building私有成员
//	 friend void gooGay(Building& building);
//
//public:
//	Building()
//	{
//		m_SittingRoom = "客厅";//客厅
//		m_BedRoom = "卧室";//
//	}
//public:
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
////全局函数
//void gooGay(Building& building)
//{
//	cout << "好基友的全局函数	正在访问：" << building.m_SittingRoom << endl;
//
//	cout << "好基友的全局函数	正在访问：" << building.m_BedRoom << endl;
//
//}
//
//void test01()
//{
//	Building building;
//	gooGay(building);
//}
//int main()
//{
//	test01();
//	return 0;
//}