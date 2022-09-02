//#include<iostream>
//using namespace std;
//
////继承中的对象模型
//class Base
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//class Son :public Base
//{
//	int m_D;
//};
//
//void test01()
//{
//	//父类中所有的非静态成员属性都会被子类继承下去
//	
//	//父类中私有成员属性是被编译器给隐蔽了，因此是访问不到，但是雀氏是被继承下去了
//	cout << "sizeof Son" << sizeof(Son) << endl;//16
//}
//int main()
//{
//	test01();
//	return 0;
//}
////利用开发人员命令提示工具查看对象模型
//// cd具体路径下
////cl /d1 reportSingleClassLayout类名 "文件名"//