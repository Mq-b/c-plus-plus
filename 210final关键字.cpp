//#include<iostream>
//using namespace std;
//
//#if 0
////阻止类的进一步派生，虚函数的进一步重写，第九行报错
//class A1 final//加上final，指定A1不能派生
//{
//	int a;
//};
//class A2 :public A1	//err，基类不能再派生了
//{
//
//};
//#endif
////基类
//class B1
//{
//public:
//	virtual void func()final{}
//};
////派生类重写基类的虚函数
//class B2 :public B1
//{
//	//virtual void func(){}//err,基类中最终版本的虚函数，不能在重写
//};
//int main()
//{
//
//	return 0;
//}