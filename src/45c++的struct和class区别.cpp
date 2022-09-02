//#include<iostream>
//using namespace std;
//
//class C1
//{
//	int m_A;//m默认权限	私有
//};
//
//struct C2
//{
//	int m_A;//默认权限	是公共
//};
//int main()
//{
//	//struct和class的区别
//	//struct默认权限是	公共public
//	//class默认权限是	私有private
//
//	C1 c1;
//	//c1.m_A = 100;//错误写法，在class里默认权限，私有，因此类外不可以访问
//	C2 c2;
//	c2.m_A = 100;//在struct中默认权限是公共所以可以访问
//
//	return 0;
//}