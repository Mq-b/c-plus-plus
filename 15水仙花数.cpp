//#include<iostream>
//using namespace std;
//
//int main()
//{
//	for (int i = 100; i <= 999; i++)
//	{
//		int a = i % 10;
//		int b = i / 10 % 10;
//		int c = i / 100;
//		if (i == a * a * a + b * b * b + c * c * c)cout << i << endl;
//	}
//	return 0;
//}//无比简单

//#include<stdio.h>
//int fun(int n)
//{
//	int i, j, k = 0, m;
//	m = n;
//	for (i = 1; i < 4; i++)
//	{
//		j = m % 10;
//		m = (m - j) / 10;
//		k += j * j * j;
//	}
//	if (k == n)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int n = 0;
//	for (n = 153; n < 1000; n++)
//	{
//		if (fun(n) == 1)printf("%d\n", n);
//	}
//	return 0;
//}//函数调用判断的写法