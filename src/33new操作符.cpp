//#include<iostream>
//using namespace std;
//
//int* func()
//{
//	//在堆区创建整数类型
//	//new返回是，该数据类型的指针，就是地址
//	int* p = new int(10);
//	return p;
//}
//
////在栈区利用new开辟数组
//void text02()
//{
//	//创建10整形数据的数组，在栈区
//	int *arr=new int[10];//代表数组有10个元素
//
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i + 100;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	//释放栈区数组
//	//释放数组的时候要加[]才可以
//	delete[] arr;
//}
//int main()
//{
//	int* p = func();
//	cout << *p << endl;
//	//堆区的数据由程序员管理开辟，程序员管理释放
//	//如果想释放堆区的数据，利用关键字delete
//	delete p;//释放--
//
//	//cout << *p << endl;//内存已经被释放，再次访问就是非法操作，会报错
//	text02();
//	return 0;
//}