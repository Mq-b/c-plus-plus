//#include<iostream>
//using namespace std;
//
////函数默认参数
//
////如果我们自己传入数据，就用自己的数据，如果没有，就用默认值
////语法:返回值类型 函数名(形参=默认值)
//int func(int a, int b=20, int c=30)
//{
//	return a + b + c;
//}
//
////注意事项
////1.如果某个位置已经有了默认参数，从这个位置往后，从左到右都必须有默认值，如下代码错误写法
//
////int func(int a, int b = 20, int c)
////{
////	return a + b + c;
////}
//
////2.如果函数声明有默认参数，函数实现就不能有默认参数，下面的代码是错误写法
//int func3(int a=20, int b=30);//只有函数声明或者函数定义其在一个写默认参数才行
//
//int func3(int a=30, int b=40)
//{
//	return a + b;
//}
//int main()
//{
//	cout << func(10, 30) << endl;
//	cout << func3(10, 30) << endl;//错误调用
//	return 0;
//}