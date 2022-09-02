//#include<iostream>
//using namespace std;
//
////栈区注意事项 不要返回局部变量的地址！！下方错误示范
//int* fun(int b)//形参数据也会放在栈区
//{
//	int a = 10;//局部变量 存放在栈区，栈区的数据在函数执行完自动释放
//	return &a;//返回区局变量的地址
//}
//int main()
//{
//	//接收fun函数的返回值
//	int* p = fun(1);
//	cout << *p << endl;//第一次可以打印正确的数字，是因为编译器做了保留
//	cout << *p << endl;//第二次不再保留了
//	return 0;
//}