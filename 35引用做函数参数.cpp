//#include<iostream>
//using namespace std;
//
//void myswap01(int *a, int *b)//地址传递
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void myswap02(int &a, int &b)//引用传递，就相当于别名，a和b就是实参别名，他们操控同一块内存
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	cout << "a=" << a << " b=" << b << endl;
//	myswap02(a, b);
//	cout << "a=" << a << " b=" << b << endl;
//
//	int& p = a;
//	cout << p << endl;
//	return 0;
//}