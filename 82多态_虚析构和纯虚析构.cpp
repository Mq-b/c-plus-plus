//#include<iostream>
//#include<string>
//using namespace std;
//
////虚析构和纯虚函数
//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal构造函数的调用" << endl;
//	}
//	//虚析构函数，改成虚析构就会走子类中的析构函数
//	//利用虚析构可以解决	父类指针释放子类对象时不干净的问题
//	virtual ~Animal()
//	{
//		cout << "Animal析构函数的调用" << endl;
//	}
//
//	//纯虚析构	需要声明也需要实现
//	//有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
//	virtual ~Animal() = 0;
//
//	//纯虚函数
//	virtual void speak() = 0;
//};
//
//Animal::~Animal()//纯虚析构需要有具体的实现
//{
//	cout << "Anima纯虚析构函数" << endl;
//}
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat的构造函数调用" << endl;
//		m_Name=new string(name);
//	}
//	virtual void speak()
//	{
//		cout <<*m_Name<< "小猫在说话" << endl;
//	}
//	~Cat()
//	{
//		if (m_Name != NULL)
//		{
//			delete m_Name;
//			m_Name = NULL;
//		}
//		cout << "Cat的析构函数调用" << endl;
//	}
//	string* m_Name;
//};
//
//void test01()
//{
//	Animal* animal = new Cat("Tom");
//	animal->speak();
//	//父类指针在析构的时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
//	delete animal;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}
/*虚析构和纯虚析构
1、都可以解决父类指针释放子类对象
2、都需要有具体的函数实现
区别:
纯虚析构该类属于抽象类，无法实例化对象
虚析构语法:virtual ~类名(){}
纯虚析构语法:virtual~类名()=0
纯虚析构的实现需要在外部加上作用域实现，参考28行*/