//#include<iostream>
//using namespace std;
////多态案例2 制作饮品类
//class AbstractDrinking
//{
//public:
//	//煮水，纯虚函数
//	virtual void Boil() = 0;
//	//冲泡
//	virtual void Brew() = 0;
//	//倒入杯中
//	virtual void PourInCup() = 0;
//	//加入辅料
//	virtual void putSomething() = 0;
//	//制作饮品
//	void makeDerink()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		putSomething();
//	}
//};
//
////制作咖啡
//class Coffee :public AbstractDrinking
//{
//public:
//	//煮水，纯虚函数
//	virtual void Boil()
//	{
//		cout << "煮农夫山泉" << endl;
//	}
//	//冲泡
//	virtual void Brew()
//	{
//		cout << "冲泡咖啡" << endl;
//	}
//	//倒入杯中
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//	//加入辅料
//	virtual void putSomething()
//	{
//		cout << "加入牛奶和糖" << endl;
//	}
//};
//
////制作茶叶
//class Tea :public AbstractDrinking
//{
//public:
//	//煮水，纯虚函数
//	virtual void Boil()
//	{
//		cout << "煮矿泉水" << endl;
//	}
//	//冲泡
//	virtual void Brew()
//	{
//		cout << "冲泡茶叶" << endl;
//	}
//	//倒入杯中
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//	//加入辅料
//	virtual void putSomething()
//	{
//		cout << "加入柠檬枸杞" << endl;
//	}
//};
////制作函数
//void doWork(AbstractDrinking* abs)
//{
//	abs->makeDerink();
//	delete abs;//释放
//}
//
//void test01()
//{
//	//制作咖啡
//	doWork(new Coffee);//new创建内存空间，返回值是空间的地址，函数参数也是指针，所以直接传递就行
//	cout << "-------------" << endl;
//	//制作茶叶
//	doWork(new Tea);
//}
//int main()
//{
//	test01();
//	return 0;
//}