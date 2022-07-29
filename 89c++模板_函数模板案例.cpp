//#include<iostream>
//using namespace std;
//
////实现通用 对数组进行排序的函数
////规则 从大到小
////算法 选择
////测试 char数组、int数组
//
////交换函数模板
//template<class T>
//void mySwap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
////排序算法
//template<class T>
//void mySort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;//认定最大值下标
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;//更新最大值下标
//			}
//		}
//		if (max != i)
//		{
//			//交换max和i的元素
//			mySwap(arr[i], arr[max]);
//		}
//	}
//}
//
////提供打印数组模板
//template<class T>
//void printArray(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void test01()
//{
//	//册数char数组
//	char charArr[] = "abcdefg";
//	mySort(charArr, 7);//排序
//	printArray(charArr, 7);//输出
//}
//
//void test02()
//{
//	//测试int数组
//	int intArr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	mySort(intArr, 10);//排序
//	printArray(intArr, 10);//输出
//}
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}