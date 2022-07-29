////114面动态内存的传递
//#include<iostream>
//using namespace std;
//void arr(int** a, int num)//解决方式1c的使用指向指针的指针
//{
//	*a = new int[num];
//}
//void arr2(int*& a, int num)//解决方法2使用引用&
//{
//	a = new int[10];
//}
//int main()
//{
//	int* p = NULL;
//	arr(&p, 10);//申请内存
//	for (int i = 0; i < 10; i++)
//	{
//		p[i] = i*10;//循环赋值
//	}
//	for (int i = 0; i < 10; i++)cout << p[i] << " " ;//输出
//	cout << endl;
//
//	int* q = NULL;
//	arr2(q, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		p[i] = i * 5;//循环赋值
//	}
//	for (int i = 0; i < 10; i++)cout << p[i] << " " ;//输出
//	delete[] p;
//	delete[] q;
//	return 0;
//}
////书上的写法实际是值传递
////c++推荐使用引用会方便很多

////122面字符串
//#include<iostream>
//using namespace std;
//void arr(char* av)
//{
//	if (av == NULL)
//	{
//		cout << "空" << endl;
//		return;
//	}
//	else
//	{
//		cout << "你好" << endl;
//	}
//}
//int main()
//{
//	char str[10] = { 0 };//str是指向栈区一块大小为10个int的连续内存
//	char* av = NULL;//av指向空
//	arr(str);//所以输出你好
//	arr(av);//输出空 
//	return 0;
//}

//122面，手写int转字符串函数
//#include<iostream>
//using namespace std;
//void int_str(char* str, int num)
//{
//	int temp = num > 0 ? num : -num;
//
//	int i = 0;
//	if (str == NULL)
//	{
//		cout << "空";
//		return;
//	}
//	while (temp)
//	{
//		temp /= 10;
//		i++;
//	}
//	if (num < 0)
//	{
//		i++;
//	}
//	str[i] = 0;
//	while (num)
//	{
//		--i;
//		str[i] = '0'+ num % 10;
//		num /= 10;
//	}
//	if (i != 0)
//	{
//		str[i] = '-';
//	}
//}
//int main()
//{
//	int i = 0;
//	cout << "你想输入字符串容量";
//	cin >> i;
//	char *str=new char[i+1];//我们这里稍微完善一下，自定义多少位数
//	int num;
//	cin >> num;
//	int_str(str, num);
//	cout << str << endl;
//	delete[] str;
//	return 0;
//}
//使用库函数的方式
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int number1 = 123456;
//    int number2 = -123456;
//    char string[16] = { 0 };
//    itoa(number1, string, 10);//使用库函数进行的转换
//    printf("数字：%d 转换后的字符串为：%s\n", number1, string);
//    itoa(number2, string, 10);
//    printf("数字：%d 转换后的字符串为：%s\n", number2, string);
//    return 0;
//}

//124将字符串转为数字
//#include<iostream>
//using namespace std;
//int str_int(const char* str)
//{
//	const char* str2 = str;
//	int temp = 0;
//	while (*str2!=NULL)
//	{
//		if (*str2 == '-')//为负号就跳过
//		{
//			str2++;
//		}
//		if (*str2 <'0' || *str2 >'9')
//		{
//			break;
//		}
//		temp = temp * 10 + ( * str2 - '0');
//		str2++;
//	}
//	if (*str == '-')//如果第一个符号为-,那么就转成负数
//	{
//		return temp = -temp;
//	}
//
//	return temp;
//}
//int main()
//{
//	char str[15];
//	cin >> str;//输入赋值
//	int num = str_int(str);
//	cout << num << endl;
//}

////126自己实现strcpy函数
//#include<iostream>
//using namespace std;
//char* My_Strcpy(char* str, const char* p)
//{
//	char* str_ = str;
//	while (*str_++ = *p++);
//	return str;
//}
//int get_strlen(const char* str)//不使用strlen而是使用自己写的函数，都一样
//{
//	int i = 0;
//	while (*str++)
//	{
//		i++;
//	}
//	return i;
//}
//int main()
//{
//	char ch[10] = "abcdef";
//	char ch2[10];
//	int num=get_strlen(My_Strcpy(ch2, ch));
//	cout << num << endl;//输出长度
//	cout << ch2 << endl;//输出字符串
//}
////strcpy函数使用char*作为返回值是为了链式表达式，程序简洁明了

//128面手写实现memcpy函数
//#include<iostream>
//#include<cassert>//提供assert断言函数
//using namespace std;
//void* My_Memstry(void* str, const void* str2,size_t num)
//{
//	assert(str != NULL && str2 != NULL&&num>0);//断言函数判断，括号内为真就继续执行，为假就结束程序
//	char* str_ = (char*)str;//保留原始地址,同时强转
//	const char* str2_ = (char*)str2;//保留原始地址
//	while (num--)
//	{
//		*str_++ = *str2_++;
//	}
//	return str;
//}
//int main()
//{
//	char ch1[10];
//	char ch2[10] = "abcdefg";
//	char *ch3=NULL;
//	ch3=(char*)My_Memstry(ch1, ch2, 3);//返回值也得强转
//	cout << ch3 << endl << ch1 << endl;
//	return 0;
//}

////133面 手动实现strstr函数
//#include<iostream>
//using namespace std;
//const char* my_Strstr(const char* str1, const char* str2)
//{
//	const char* str1_ = str1;
//	const char* str2_ = str2;//先复制一份
//	if (str1_ == NULL || str2_ == NULL)//确保是有效字符串
//	{
//		return str1;
//	}
//	while (*str1)//外循环遍历str1
//	{
//		str1_ = str1;
//		str2_ = str2;
//
//		while (*str1_++ == *str2_++)
//		{
//			if (*str2_ == NULL)
//			{
//				return str1;
//			}
//		}
//		str1++;
//	}
//	return NULL;
//}
//int main()
//{
//	const char a[20] = "aa哈哈哈bb哈";
//	const char b[10] = "哈哈";
//
//	const char *p=my_Strstr(a, b);//调用函数
//	cout << p << endl;
//	return 0;
//}

////137编程实现strcmp函数
//#include<iostream>
//using namespace std;
//#include<cassert>
//#include<cstring>
//
//int my_Strcmp(const char* str1, const char* str2)
//{
//	//断言函数 为真就继续执行
//	assert(!(str1 == NULL && str2 == NULL));
//	int num = 0;
//    while ((*str1 != '\0') && (*str1 == *str2))
//    {
//        str1++;
//        str2++;
//    }
//    num = *str1 - *str2;
//    return num;
//}
//
//int main()
//{
//    const char a[]{ "哈哈哈" };
//    const char b[]{ "哈哈哈" };
//
//    int i=my_Strcmp(a, b);
//    cout << i << endl;
//    //库函数做参照
//    int v = strcmp(a, b);
//    cout << v << endl;
//	return 0;
//}

////141把10进制正整数数用二进制方式输出
//#include<iostream>
//using namespace std;
//void base(int num)
//{
//	int i = num;
//	int ave[1024]{ 0 };
//
//	int v = 0;
//	while (num)
//	{
//		ave[v] = num % 2;
//		v++;
//		num /= 2;
//	}
//	//倒序输出也就是从右往左的看，减1因为v最后多加一
//	for (int i = v - 1; i >= 0; i--)
//		cout << ave[i];
//}
//int main()
//{
//	base(8);
//	return 0;
//}

//2进制转10进制，c语言写法
//#include<stdio.h>
//#include<math.h>
//int func(int n[], int i) {
//	int num = 0;
//	int t = 0;
//	for (int a = i - 1; a >= 0; a--, t++) {
//		if (n[a] == 0)continue;
//		num += 1 << t;
//	}
//	return num;
//}
//int main()
//{
//	int n[7]{ 1,0,1,0,1,1,1 };
//	printf("%d", func(n, 7));
//	return 0;
//}
