//#include<iostream>
//using namespace std;
//
////纯虚函数和抽象类
//class Base
//{
//public: 
//	//纯虚函数
//	//只要有一个纯虚函数，这个类称为抽象类
//	//抽象类特点
//	//1、无法实例化对象
//	//2、抽象类的子类必须要重写父类中纯虚函数，否则也属于抽象类
//	virtual void func() = 0;
//};
//
//class Son : public Base
//{
//public:
//	virtual void func()//子类的virtual关键字可以省略
//	{
//		cout << "func()函数调用" << endl;
//	}
//};
//
//class Aon : public Base
//{
//public:
//	virtual void func()
//	{
//		cout << "func()函数调用,Aon中" << endl;
//	}
//};
//
//void ave(Base& a)
//{
//	a.func();
//}
//void test01()
//{
//	//Base b;//抽象类是无法实例化对象
//	//new Base;
//	Son s;//子类必须要重写父类中纯虚函数，否则无法实例化对象
//
//	Base* base = new Son;//指针使用多态
//	base->func();
//	delete base;
//
//	Aon a;
//	ave(a);//引用使用多态
//}
//int main()
//{
//	test01();
//	return 0;
//}
/*包含纯虚函数的类称为抽象类（Abstract Class）。 之所以说它抽象，是因为它无法实例化，
也就是无法创建对象。 原因很明显，纯虚函数没有函数体，不是完整的函数，无法调用，
也无法为其分配内存空间。*/