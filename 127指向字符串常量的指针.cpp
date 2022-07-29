//#include<iostream>
//using namespace std;
//
//int main()
//{
//	const char* ch1 = "abc";
//	const char* ch2 = "abc";
// 
// //char *ch3="abc";//这种写法在c++是错误的
// 
//	cout << (ch1 == ch2) << endl;//比较大小实际比较的是地址，因为地址一样所以相等
//	//两个指针都指向一块数据域，是指向常量的指针。并不是比较字符串是否相等。
// 
//	cout << static_cast<const void*>(ch1)<< endl;
//	cout << static_cast<const void*>(ch2) << endl;
//
//	//cout << &ch1 << endl;//这两种写法是错误的，取的是指针本身的地址所以不相等，c++风格写成上面那样就行
//	//cout << &ch2 << endl;
//	printf("%p\t%p", ch1, ch2);
//	return 0;
//}