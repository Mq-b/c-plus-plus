//#include<iostream>
//using namespace std;
////多态
//
////动物类
//class Animal
//{
//public:
//	//虚函数
//	virtual void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
////猫类
//class Cat :public Animal
//{
//public:
//	//重写 函数返回值类型 函数名 参数列表 完全相同
//	void speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//
////狗类
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//};
////执行说话的函数
////地址早绑定 在编译阶段确定函数地址
////如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
//
////动态多态满足条件
////1、有继承关系
////2、子类重写父类的虚函数
//
////动态多态使用
////父类的指针或者引用指向子类对象
//void DoSpeak(Animal& animal)//Animal &animal=cat
//{
//	animal.speak();
//}
//
//void test01()
//{
//	Cat cat;
//	DoSpeak(cat);
//
//	Dog dog;
//	DoSpeak(dog);
//}
//int main()
//{
//	test01();
//	return 0;
//}
///*多态vfptr虚函数指针、vftable虚函数表，如果使用了多态，那么就四个字节内存，因为指针占四个字节而不是和之前一样占一个字节
//1. 要通过指针或引用调用
//2. 要调用的函数在基类或者被调用的类种声明为virtual
//同时满足才会去访问虚函数表，达到多态这个目的
//*/