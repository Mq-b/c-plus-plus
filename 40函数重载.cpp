//#include<iostream>
//using namespace std;
//
////函数重载
////可以让函数名相同，提高复用性
////1.同一个作用域下
////2.函数名称相同
////3.函数参数类型不同，或者个数不同，或者顺序不同
//void fuc()
//{
//	cout << "fuc的调用" << endl;
//}
//
//void fuc(int a)
//{
//	cout << "fuc的调用!!!!" << endl;
//}
//
//void fuc(double a)
//{
//	cout << "fuc的调用double" << endl;
//}
//
//void fuc(double a, int b)
//{
//	cout << "fuc的调用顺序1" << endl;
//}
//
//void fuc(int b,double a)
//{
//	cout << "fuc的调用顺序2" << endl;
//}
//
////注意事项
////函数的返回值不可以作为函数重载的条件
////int fuc(int b, double a)
////{
////	cout << "fuc的调用顺序2" << endl;
////}
//int main()
//{
//	fuc();
//	fuc(10);//个数
//	fuc(3.14);//不同类型
//	fuc(3.0,5);//不同顺序
//	fuc(2, 3.1);//不同顺序
//	return 0;
//}