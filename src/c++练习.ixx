//#include<iostream>
//using namespace std;
//
//int main()
//{
//	typedef int arr[5];
//	arr a = { 0 };
//	for (int i = 0; i < 5; i++)cin >> a[i];
//	for (int i = 0; i < 5; i++)cout << a[i] << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a[3]{ 0,1,2 };//c++的写法
//	for (int i = 0; i < 3; i++)cout << a[i] << endl;
//	return 0;
//}
//#include<iostream>
//#include<math.h>
//using namespace std;
//void fun()
//{
//	for (int i = 1000; i <= 9999; i++)
//	{
//		int a = i % 10;
//		int b = i / 10 % 10;
//		int c = i / 100 % 10;
//		int d = i / 1000;
//		if (i == pow(a, 4) + pow(b, 4) + pow(c, 4) + pow(d, 4))cout << i << endl;//遍历查找四位数中各位的四次放的和==本身的数
//	}
//}
//int main()
//{
//	fun();
//	return 0;
//}//无比简单
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a[5]{ 1,2,3,4,5 };
//	int b[5]{ 1,2,3,4,5 };
//	//cout << a << endl;
//	//cout << b << endl;
//
//	int a_ = 20, b_ = 20;
//	cout << &a_ << " " << &b_ << endl;
//
//	char ch[10] = "哈哈哈哈";
//	char ch2[10] = "哈哈哈哈";
//	cout << &ch << endl;
//	cout << &ch2 << endl;
//
//	const char *ch3 = "哈哈哈哈";
//	const char *ch4 = "哈哈哈哈";
//	cout << &ch << endl;
//	cout << &ch2 << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	float b = 0.0f;
//	cout << typeid(a * b).name() << endl;//检查数据类型
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = 1;
//	for (int i = 1; i < 10; i++)//回溯
//	{
//		a = (a + 1) * 2;
//	}
//	a = (a + 1) / 2+1;
//	cout << a << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	bool arr[10] = { 0,1,2,3,4,5.3,6,7,8,9 };//bool类型数组
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	cout << sizeof(arr) << endl;
//	bool ave = 0.1;
//	cout << ave << endl;
//}
//#include<iostream>
//using namespace std;
//void sort(int* a, int b)
//{
//	for (int i = 0; i < b-1; i++)
//	{
//		for (int j = 0; j < b - i - 1; j++)//冒泡排序算法
//		{
//			if (a[j] < a[j + 1])
//			{
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int a[10] = { 0,1,2,3,4,5,6,7,8,9};
//	sort(a, 10);
//	for (int i = 0; i < 10; i++)cout << a[i] << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<string>
//
//int main()
//{
//	int a[10] = {1,2,3,4,5,6,7,8,9,10};
//	int* p = a;
//	cout << (p+=2,*(p++)) << endl;
//	cout << *p << endl;
//}
//#include<iostream>
//using namespace std;
//
//template<class T,class B>//函数模板
//void ave(T& a, B& b)
//{
//	a = a - b;
//}
//int main()
//{
//	int a = 10;
//	double b = 20;
//	ave(a, b);
//	cout << a << endl;
//	return 0;
//}
//完美素数
//#include<iostream>
//using namespace std;
//#include<string>
//bool judgment(int a)
//{
//	int i = 0;
//	for ( i = 2; i <= a; i++)
//	{
//		if (a % i == 0)break;
//	}
//	if (a == i)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//bool aver(int a)
//{
//	int sum = 0,i=a;
//	while (i)
//	{
//		sum += i % 10;
//		i /= 10;
//	}
//	if (judgment(sum) && judgment(a))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//	
//}
//int main()
//{
//	int ave=1;
//	while (ave)
//	{
//		cin >> ave;
//		if (ave == 0)
//		{
//			cout << "退出" << endl; break;
//		}
//		else
//		{
//			if (aver(ave))
//			{
//				cout << "完美素数是:" << ave << endl;
//			}
//			else
//			{
//				cout <<ave<< "不是完美素数" << endl;
//			}
//		}
//	}
//	return 0;
//}

//计算阶乘的那个和
//#include<iostream>
//#include<math.h>
//using namespace std;
//
//long fac(int a)
//{
//	if (a == 0 || a == 1)return 1;
//	else return a * fac(a - 1);
//}
//double power(double x, int n)
//{
//	double sum = 1;
//	if (n == 1)
//	{
//		sum += x;
//		return sum;
//	}
//	else
//	{
//		sum += x;
//		for (int i = 2; i <= n; i++)
//		{
//			sum += pow(x, i) / fac(i);
//		}
//		return sum;
//	}
//}
//int main()
//{
//	int n = 0;
//	double x = 0;
//	cin >> x>>n;
//	cout << power(x, n) << endl;
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b;
//	while (scanf_s("%d%d", &a, &b) != EOF)//EOF多组输入
//	{
//		printf("%d\n", a+b);
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main() 
//{
//	int  a[10];
//	for (int i = 0; i < 10; i++)cin >> a[i];//给数组赋值
//	int v = 0;
//	cin >> v;
//	for(int j=1;j<=v;j++)//外循环意味着执行三次
//	{
//		int k = a[9];//外循环，保留第10元素的初值
//		for (int i = 9; i > 0; i--)
//		{
//			a[i] = a[i - 1];//内循环，把元素10个整体向后移动一位
//		}
//		a[0] = k;//外循环，把初值第10元素赋值给第一元素
//	}
//	for (int i = 0; i < 10; i++)cout << a[i] << " ";
//	return 0;
//}
//#include<iostream>
//using namespace std;//打印两个三角
//
//int main()
//{
//	int j,i,v;
//	for (i = 1; i <= 4; i++)
//	{
//		for (j = 1; j <= i - 1; j++)
//			cout << " ";
//		for (v = 1; v <=9-2*i; v++)
//			cout << "*";
//		cout << endl;
//	}
//	for (i = 1; i <= 3; i++)
//	{
//		for (j = 0; j <= 2-i; j++)
//			cout << " ";
//		for (v = 1; v <= i * 2 + 1; v++)
//			cout << "*";
//		cout << endl;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<Windows.h>
//int main()
//{
//	system("color 05");
//	for (int i = 0; i < 60; i++)
//	{
//		for (int j = 0; j < 60; j++)//Sleep函数控制计时器打印数字
//		{
//			system("cls");
//			cout << i << ":" << j;
//			Sleep(1000);
//		}
//	}
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int b = 20;
//	int* q = &b;
//	int* a = new int (*q);//new的初始化
//	cout << *a << endl;
//
//	int* e = new int[5]{ 1,2,3,4,5 };//new数组的初始化
//	cout << *e << endl;
//
//	delete a;
//	delete[] e;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//void sort(int* arr, int num)
//{
//	for (int i = 0; i < num - 1; i++)
//	{
//		for (int j = 0; j < num - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1]) 
//			{
//				int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int num;
//	cout << "请输入需要排序的数字数量" << endl;
//	cin >> num;
//	int* p = new int[num];
//	cout << "请输入需要排序的数字" << endl;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> p[i];
//	}
//	sort(p, num);
//	for (int i = 0; i < num; i++)cout << p[i] << endl;
//	delete[] p;
//	return 0;
//}//动态内存排序

//#include<iostream>
//using namespace std;
////template<typename T>
////void swap(T &a, T &b)
////{
////	T temp = a;
////	a = b;
////	b = temp;
////}
//int main()
//{
//	int a = 1, b = 2;
//	double a1 = 1.5, b2 = 2.6;
//	swap<>(a1, b2);//swap是封装好的库函数模板，可以直接使用
//	cout << a1 << b2 << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a[2][3] = { {0,1,2},{3,4,5} };
//	int(*p)[3];
//	p = a;
//	cout << *(*(p + 1) + 2) << endl;
//	cout << *(*(a + 1) + 2) << endl;
//	return 0;
//}
//堆区申请二维数组大小，赋值，释放
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int** a = new  int*[2];
//	for (int i = 0; i < 2; i++)
//	{
//		a[i] = new int[2];
//	}
//	
//	for (int i = 0; i < 2; i++)
//		for (int j = 0; j < 2; j++)
//			cin >> a[i][j];
//	
//	for (int i = 0; i < 2; i++)
//		for (int j = 0; j < 2; j++)
//			cout<< a[i][j];
//
//	for (int i = 0; i < 2; i++)
//		delete[] a[i];
//		delete[]a;
//		/*int** a2 = new int*;//试试
//		delete a2;*/
//	return 0;
//}
//求出回文数
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = 0, temp = 0, sum = 0;
//	for (a = 0; a <= 10000; a++)
//	{
//		temp = a;
//		sum = 0;
//		while (a)
//		{
//			sum = sum * 10 + a % 10;//求得倒数
//			a /= 10;
//		}
//		a = temp;
//		if (a == sum)cout << a << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<string>
//int main()
//{
//	ifstream ifs;
//	ifs.open("文件.txt", ios::in);
//	if (ifs.is_open() == NULL)
//	{
//		cout << "打开失败" << endl;
//		return 0;
//	}
//	ofstream ofs;
//	ofs.open("文件2.txt", ios::out);
//	char ch[1024] = { 0 };
//	while (ifs >> ch)//边读取数据边写入数据
//	{
//		cout << ch << endl;
//		ofs << ch << endl;
//	}
//	
//	ifs.close();//关闭读取文件
//	ofs.close();//关闭写入文件
//	return 0;
//}
//#include<iostream>
//using namespace std;
//struct date//内存对齐问题
//{
//	short j, i;
//	char ch[20];
//	int a, b, c;
//	double ab;
//	int av;
//}today;
//int main()
//{
//	//int 傻子 = 0;
//	//cout << 傻子 << endl;
//	//int a;
//	//cin >> a;
//	//if (a > 1)cout << "a>1" << endl;
//	//else if (a < 1)cout << "a<1" << endl;//最后不以else结尾依旧合法
//	cout << sizeof(today) << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	string name2;
//	cin >> name2;
//	if (name2=="哈哈哈")cout << "yes" << endl;
//	else cout << "no" << endl;
//
//	char ch[7] = "哈哈哈";//c语言字符串的写法不能比较是否相等
//	scanf_s("%s", ch, 7);
//	if (ch == "哈哈哈")printf("no\n");
//	else printf("no\n");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int x = 3, z, y;
//	x *= (z = y = 4);//4赋值给y，y赋值给z，x*=z，就是12
//	cout << x << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int ave = 5;
//int main(void)
//{
//	int ave = 0;
//	cout << ave << endl;
//	cout << ::ave << endl;//全局作用域
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	const double num = 20.1;//const修饰num为只读
//	//错误的num = 20;
//	double* p;
//	//p=&num//错误
//	double av = 20.0;
//	double& a = av;//别名，a引用必须初始化，且后面不能更改
//	a = 30;//操控同一块内存
//	cout << av << endl;
//	
//	return 0;
//}
////题目:用宏定义得到一个字的高位和低位字节
//#define WORD_LOW(a) (( a & 255))
//#define WORD_HIGH(a) (a>>8)
//
////一个字由两个字节组成，因此WORD_LOW取参数xxx的低8位，WORD_HIGH取参数的高8位
//
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 62597;   //1111 0100 1000 0101
//	
//	cout << WORD_LOW(a) << endl;
//	cout << WORD_HIGH(a) << endl;
//}
//#include<iostream>
//using namespace std;
//struct student
//{
//	int a;
//	student* p;
//	int b;
//}i;
//int main()
//{
//	/*int* a;
//	double* b;
//	float* c;
//	char* e;
//	void* q;
//	student* p;
//	cout << sizeof(a) << endl;
//	cout << sizeof(b) << endl;
//	cout << sizeof(c) << endl;
//	cout << sizeof(e) << endl;
//	cout << sizeof(q) << endl;
//	cout << sizeof(p) << endl;*//在64位系统下指针是8个字节，所有指针都是8字节
//	
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a[100]{};
//	int* p = a;
//	cout << sizeof(a) << " " << sizeof(p) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int x) :i(x)
//	{
//
//	}
//
//	int i;
//};
//class B :public A
//{
//public:
//	B(int x) :A(10), j(x)
//	{
//
//	}
//
//	int j;
//};
//int main()
//{
//
//	A av(5);
//	B ar(6);
//	cout << av.i << endl;
//	cout << ar.j << endl;
//
//	cout << sizeof(A) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//void arr(char ch[])
//{
//	cout << sizeof(ch[0]) << endl;//1
//	cout << sizeof(ch) << endl;
//}
//union ar
//{
//	double a;
//	int r;
//	float c;
//};
//int main()
//{
//	char ch[] = "ABCDE";
//	arr(ch);
//	cout << sizeof(ch) << endl;
//	cout << sizeof(ar) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//const char* ave(int a)
//{
//	return a % 2 ? "奇数" : "偶数";//三目运算符的强大
//}
//int main()
//{
//	string a;
//	a = ave(20);
//	cout << a << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//const string arr(const string ar,const string av)//离谱的字符串比较
//{
//	return (ar > av ? av : ar);
//}
//int main()
//{
//	string ch = "力魄";
//	string ch2 = "计算机技术";
//	cout << arr(ch, ch2) << endl;
//	cout << (ch < ch2) << endl;
//	return 0;
//}

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

//#include<iostream>
//using namespace std;
//int sort(const void* a, const void* b)
//{
//	//return *(int*)a - *(int*)b;//升序
//	return *(int*)b - *(int*)a;//降序
//}
//int main()
//{
//	int arr[10] = { 1,8,6,5,4,7,3 ,6,7,8 };
//	//qsort快排
//	qsort(arr, 10, sizeof(arr[0]), sort);//数组首地址 排序个数 单个个数大小 比较函数
//	for (int i = 0; i < 10; i++)cout << arr[i] << " ";
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	char ch[10] = "abcde";
//	const char ch2[10] = "jha";
//	strncpy(ch, ch2, 2);//从第一个开始覆盖掉
//	cout << ch << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(char* name)
//	{
//		cout << sizeof(name) << endl;//4，和普通函数一样只能得出指针的大小
//		strcpy(Name, name);
//	}
//private:
//	char Name[10];
//};
//int main()
//{
//	char ch[10]="哈哈哈哈";
//	Person str(ch);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//void arr(char* av)
//{
//	if (av == 0)
//	{
//		return;
//	}
//	else
//	{
//		cout << "你好" << endl;
//	}
//}
//int main()
//{
//	char str[10]={0};
//	char* av = NULL;
//	arr(str);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[10];
//	int p[3];
//	int k = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		a[i] = i;
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		p[i] = a[i * (i + 1)];
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		k = k + p[i] * 2;
//	} 
//	cout << k << endl;
//	return 0;
//}

//using namespace std;
//#include<iostream>
//
//int main()
//{
//	int a[5] = { 0,1,2,3,4};
//	int b[5] = { 0 };
//	memcpy(b, a,20);//库函数memcpy函数,第三个参数是字节,拷贝内存
//	for (int i = 0; i < 5;i++)cout << b[i] << endl;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	FILE* fp = fopen("文件.txt", "a+");//c语言读写方式
//	fputs("哈哈哈哈", fp);
//	fclose(fp);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//void sum(int a, int b, int* s)
//{
//	*s = a + b;
//}
//int main()
//{
//	int a = 2, b = 3, c = 0;
//	sum(a, b, &c);
//	cout << c << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;//using在c++的作用
//
//int main()
//{
//	//using 别名 = 原先类型；
//	using AV = int;
//	AV i = 0;
//	cout << typeid(i).name() << endl;
//}
//#include<iostream>//关于类占占据内存空间的问题
//using namespace std;
//
//class A
//{
//	virtual void func() = 0;
//};
//class B :public A
//{
//	void func()
//	{
//		cout << "哈哈" << endl;
//	}
//private:
//	int a;
//};
//class C
//{
//	virtual void av()
//	{
//		
//	}
//};
//class D
//{
//	void av()
//	{
//
//	}
//};
//class E
//{
//	void av()//函数内的变量不算在类内
//	{
//		int a;
//		double b;
//	}
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(D) << endl;
//	cout << sizeof(E) << endl;
//}
//for each (object var in collection_to_loop)
//{
//
//}
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<string>
//#include<algorithm>
//class Person
//{
//public:
//	Person() = default;//默认构造函数
//	Person(string name,int age)
//	{
//		this->Name = name;
//		this->Age = age;
//	}
//	string Name;
//	int Age;
//};
//void Print(const Person& v)
//{
//	cout << v.Age << " " << v.Name << endl;
//}
//int main()
//{
//	vector<Person>a;
//	vector<Person>b;
//
//	Person p1("哈哈", 10);
//	Person p2;
//	a.push_back(p1);
//
//	b.resize(a.size()); //vector resize时会调用无参数构造函数,需要有默认构造函数
//
//	//copy(a.begin(), a.end(), b.begin());
//	b = a;//两种方式都行
//	for_each(b.begin(), b.end(), Print);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<string>
//#include<algorithm>
//#include<vector>
//
//class Person
//{
//public:
//	Person() = default;
//	Person(string name, int age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	string m_Name;
//	int m_Age;
//	bool operator==(const Person& val)//二元谓词
//	{
//		return this->m_Age == val.m_Age;
//	}
//	void operator=(const Person& p)//重载=
//	{
//		this->m_Age = p.m_Age;
//	}
//};
//class Print
//{
//public:
//	void operator()(const Person& p)
//	{
//		cout << "姓名:" << p.m_Name << " 学号:" << p.m_Age << endl;
//	}
//};
//void test01()
//{
//	Person p1("a", 1);
//	Person p2("b", 3);
//	Person p3("c", 4);
//	Person p4("d", 1);
//	Person p5("e", 1000);
//
//	vector<Person>n;
//	n.push_back(p1);
//	n.push_back(p2);
//	n.push_back(p3);
//	n.push_back(p4);
//
//	cout << "修改前" << endl;
//	for_each(n.begin(), n.end(), Print());//仿函数
//
//	cout << "修改后" << endl;
//	replace(n.begin(), n.end(), p4, p5);
//	for_each(n.begin(), n.end(), Print());//仿函数
//}
//int main()
//{
//	test01();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<numeric>//提供算法
//int main()
//{
//	int num[10] = { 1,2,3,4,5,6,7,8,9 ,10 };
//	int total = accumulate(num, num + 10, 0);//总和，计算数组的总和
//	cout << total << endl;
//}

//#include<iostream>
//using namespace std;
//#include<algorithm>
//
//int main()
//{
//	int num = min(10, 20);//调用库函数在算法头文件
//	cout << num << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	system("start http://bing.com");//使用system命令跳转网址
//	return 0;
//}
//子串
//#include<iostream>
//using namespace std;
//#include<string>
//#include<vector>
//
//void test01()
//{
//	string v1 = "abcd eeee";
//	size_t temp = v1.find(' ', 0);
//	cout << temp << endl;
//
//	string v2 = v1.substr(0, temp);
//	cout << v2 << endl;
//
//	vector<string>p1;
//	p1.push_back(v2);
//
//	cout << p1[0] << endl;
//}
//
//void test02()
//{
//	
//		size_t choose = 0;
//		size_t temp = 0;
//		vector<string>p1;
//		string show;
//		show = "http://ssjsjs-eeeeee";
//		temp = 0;
//
//		cout << show << endl;
//		temp = show.find('-', 0);//查找空格位置
//		string temp1 = show.substr(0, temp);
//		p1.push_back(temp1);//获取子串放入容器
//		cout << p1[0] << endl;
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int max = 0;
//	int i_, j_;
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,12,7 };
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 4; j++)
//			if (a[i][j] > max)max = a[i][j], i_ = i, j_ = j;
//	cout << i_ << j_<<" "<< max << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<string>
//void test01()
//{
//	string v1 = "start ";
//	string v2 = "http://bing.com";
//	v1 += v2;
//	cout << v1 << endl;
//	system(v1.data());//事实证明可以直接访问,需要data取出容器的值
//}
//int main()
//{
//	test01();
//	return 0;
//}

//#include<iostream>
//
//void test01()
//{
//	//奇奇怪怪的知识
//	std::cout <<( * "pizza" )<< std::endl;
//	std::cout << ("pizza"[2]) << std::endl;
//
//}
//int main()
//{
//	test01();
//	return 0;
//}

//#include<iostream>
//
//struct Person
//{
//	char ch[10];
//};
//
//int main()
//{
//	Person* v = new Person;
//	std::cin >> v->ch;
//	std::cout << v->ch << std::endl;
//	delete v;
//	char ch[] = "\1234\\t\x43\\bcd";
//	char ch2[] = "\1000";
//	std::cout << ch2 << std::endl;
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//struct Person
//{
//	int age;
//	std::string name;
//};
//int main()
//{
//	Person v[2]{ 12,"离谱" };
//	std::cout << v[1].name << std::endl;
//	std::cout << v[1].age << std::endl;
//
//	int a[10]{ 5 };
//	std::cout << a[2] << std::endl;
//	return 0;
//}

//#include<iostream>
//#include<fstream>
//#include <string>
//void test01()
//{
//	std::string name;
//	std::string str;
//	//输入赋值给name对象
//	getline(std::cin, name);
//	//初始化打开name，不存在就创建
//	std::ofstream ofs(name);
//	std::cin >> str;
//	ofs << str;
//	ofs.close();
//}
//int main()
//{
//	//按照输入创建顺便写入
//	//test01();
//
//	//使用外部变量方式
//	extern int a;
//	extern const int b;
//
//	std::cout << b << a << std::endl;
//	return 0;
//}

//#include<iostream>
//#include<fstream>
//#include <string>
//void test01()
//{
//	std::string name;
//	std::string str;
//	getline(std::cin, name);
//	std::ofstream ofs(name.data());
//	std::cin >> str;
//	ofs << str.data();
//	ofs.close();
//
//	std::ifstream ifs;
//	//读取也可以默认打开方式
//	ifs.open(name);
//	std::string str2;
//	while (ifs >> str2)
//	{
//		std::cout << str2 << std::endl;
//	}
//	ifs.close();
//}
//int main()
//{
//	//按照输入创建顺便写入
//	test01();
//	return 0;
//}

//#include<iostream>
//
//void test01()
//{
//	//链式编程，原理是因为成员函数返回对象本身
//
//	std::cout.put('a').put('b').put('c');
//}
//int main()
//{
//	test01();
//	return 0;
//}
//#include<iostream>
//#include<string>
//class Person
//{
//public:
//	Person(int age, std::string name)
//	{
//		this->m_Age = age;
//		this->m_Name = name;
//		std::cout << "构造" << std::endl;
//	}
//
//	Person() = default;
//
//	void print()
//	{
//		std::cout << this->m_Name << " " << this->m_Age << std::endl;
//	}
//
//	~Person()
//	{
//		std::cout << "析构" << std::endl;
//	}
//
//private:
//	int m_Age;
//	std::string m_Name;
//};
//void test01()
//{
//	Person 小明{12,"张三"};
//	小明.print();
//	Person static v{ 13,"离谱" };
//	v.print();
//}
//int main()
//{
//	//经过调试，静态对象和静态变量的内存策略基本一样
//	test01();
//	return 0;
//}

////练习模板类
//#include<iostream>
//#include<string>
//template<class T, class T2>
//class Person
//{
//public:
//
//	Person() = default;
//
//	void showPerson()
//	{
//		std::cout <<  this->m_Age << " " << this->m_Name << std::endl;
//	}
//
//	
//	Person(T age, T2 name)
//	{
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//
//	T m_Age;
//	T2 m_Name;
//};
//void test01()
//{
//	std::string  name = "哈哈";
//	Person <double,std::string>v(1.2, name);
//	v.showPerson();
//}
//int main()
//{
//	test01();
//	return 0;
//}

//#include<iostream>
//
//class Person
//{
//public:
//	Person()
//	{
//		this->num++;
//		this->m_Age = 0;
//		this->m_Name = "";
//	}
//
//	Person(int age, std::string name)
//	{
//		this->m_Age = age;
//		this->m_Name = name;
//		this->num++;
//	}
//
//	void print()
//	{
//		std::cout << this->m_Age << " " << this->m_Name << std::endl;
//		std::cout << this->num << std::endl;
//	}
//
//private:
//
//	int m_Age;
//	std::string m_Name;
//	static int num;
//};
//
////给静态成员变量初始化
//int Person::num = 0;
//
//void test01()
//{
//	Person v{ 12,"哈哈哈" };
//	v.print();
//
//	Person p1;
//	Person p2;
//	Person p3;
//	Person p4;
//
//	p3.print();
//	p4.print();
//	//总结静态成员变量不属于对象的组成部分，多个对象共享一份数据，也就是静态成员变量
//	//并且静态成员变量要在外部初始化
//}
//int main()
//{
//	test01();
//	return 0;
//}
//#include<iostream>
//#include<array>
//#include<fstream>
//class Fath
//{
//
//public:
//
//	Fath(int age, std::string name)
//	{
//		this->m_age = age;
//		this->m_name = name;
//	}
//
//	void showFath()
//	{
//		std::cout << m_age << " " << m_name << std::endl;
//	}
//
//	int m_age;
//	std::string m_name;
//};
//
//class Child :public Fath
//{
//public:
//	//子类有参构造函数，显性调用父类构造函数，初始化为值都一样的
//	Child(int age, std::string name) :Fath(age, name)
//	{
//		this->z_age = age;
//		this->z_name = name;
//	}
//	Child() :Fath(0, "0")
//	{
//		this->z_age = 0;
//		this->z_name = "0";
//	}
//	void show()
//	{
//		std::cout <<"父:" << m_age << " " << m_name << std::endl;
//		std::cout <<"子:" << z_age << " " << z_name << std::endl;
//	}
//
//	int z_age;
//	std::string z_name;
//};
//
//std::ostream& operator<<(std::ostream& cout, Child& V)
//{
//	cout << V.m_age << " " << V.m_name << std::endl;
//	cout << V.z_age << " " << V.z_name << std::endl;
//	cout << std::endl;
//	return cout;
//}
//
//void test01()
//{
//	//如果父类只有有参构造就必须在父类的构造函数显性的调用它
//	Child v1;
//	Child v2{12,"傻子"};
//	v1.show();
//	v2.show();
//}
//void test02()
//{
//	char ch[10]{ 0 };
//	std::cin.getline(ch, 10);
//	std::cout << ch << std::endl;
//}
//
//void test03()
//{
//	Child v1{ 12,"没意思" };
//	Child v2{ 100,"额鹅鹅鹅" };
//	std::cout << v1<<v2;
//}
//
//int main()
//{
//	//test01();
//	//test02();
//	//复习重载运算符
//	test03();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//    int arry[] = { 4, 3, 4, 2, 2, 2, 4, 1, 1, 1, 3, 3, 1, 1, 1, 4, 2, 2 };
//    // 先计算这两个出现奇数次的数的异或运算结果:
//    int eor = 0;
//    for (int i = 0; i < sizeof(arry) / sizeof(arry[0]); i++)
//    {
//        eor ^= arry[i];
//    }
//    cout << "那么这两个出现奇数次的数的异或运算结果为：" << eor << endl;
//    int rightOne = eor & (~eor + 1); //提取eor最右边的1
//    int theOne = 0; // 相应位置为1的那个出现奇数次的那个数
//    for (int i = 0; i < sizeof(arry) / sizeof(arry[0]); i++)
//    {
//        if ((arry[i] & rightOne) == 0)
//        {
//            theOne ^= arry[i];  // 可以找到跟eor的最右边为1的数相应的出现奇数次的那个数
//        }
//    }
//    cout << "出现奇数次的两个数分别为：" << theOne << " " << (eor ^ theOne) << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<string>
//class Father
//{
//public:
//	virtual void showFather()
//	{
//		std::cout << this->m_age << " " << this->m_name << std::endl;
//	}
//
//private:
//	int m_age=0;
//	std::string m_name = "父亲";
//};
//
//class Son :public Father
//{
//public:
//	void showFather()
//	{
//		std::cout << this->z_age << " " << this->z_name << std::endl;
//	}
//
//private:
//	int z_age=1;
//	std::string z_name = "儿子";
//};
//void test01()
//{
//	Father* p = nullptr;
//	p = new Son;
//	//简单的多态，子类重写父类成员函数，父类指针指向
//	p->showFather();
//	delete p;
//}
//int main()
//{
//	test01();
//}

//#include<iostream>
//#include<string>
//
//class Father
//{
//public:
//	virtual void print()
//	{
//		std::cout << "父亲在说话" << std::endl;
//	}
//
//	virtual ~Father()
//	{
//
//	}
//};
//class Son :private Father
//{
//public:
//	void print2()
//	{
//		std::cout << "儿子在说话" << std::endl;
//	}
//};
//
//class Son2 :public Father
//{
//public:
//	void print()
//	{
//		std::cout << "儿子在说话" << std::endl;
//	}
//};
//
//class Son3 :protected Father
//{
//public:
//	void print()
//	{
//		std::cout << "儿子在说话" << std::endl;
//	}
//};
//void test01()
//{
//	Father father;
//	father.print();
//
//	//私有继承，子类无法访问父类
//	Son son;
//	son.print2();
//
//	//共有继承就可以
//	Son2 son2;
//	son2.print();
//}
//void test02()
//{
//	//父类指针无法访问指向私有继承的子类对象
//	//Father* father = new Son;
//
//	//公共继承的就可以多态
//	Father* father = new Son2;
//	father->print();
//}
//
//void test03()
//{
//	Son3 son3;
//	//保护继承，保护权限外部无法访问
//	//son3.Father::print();
//
//	//一样无法进行多态
//	//Father* father = new Son3;
//}
//int main()
//{
//	//test01();
//	//test02();
//	
//	//试试保护权限
//	test03();
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<functional>
//#include<numeric>
//using namespace std;
//void test01()
//{
//	int num[5]{ 1,2,3,4,5 };
//	//numeric头文件提供
//	int i=accumulate(num, num + 5,0);
//	cout << i << endl;
//}
//int main()
//{
//	test01();
//}

////模板使用一半类型一半参数的情况
//#include<iostream>
//template<class T,int num>
//class Sum
//{
//public:
//	Sum(T i)
//	{
//		this->num2 = i;
//	}
//
//	void sum()
//	{
//		std::cout << (this->num2 + num) << std::endl;
//	}
//private:
//	T num2;
//};
//int main() {
//	Sum<double, 10>v(20);
//	v.sum();
//}
//#include<stdio.h>
//int main()
//{
//	int num[5]{ 0 };
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%d", num + i);
//	}
//	for (int i : num)printf(" %d", i);
//}
//#include<stdio.h>
//int main()
//{
//	int num[5]={ 0 };
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%d", num + i);
//	}
//	for (int i = 0; i < 5;i++)printf(" %d", num[i]);
//}
//#include<iostream>
//const char* str(int a, int b)
//{
//	return a > b ? "a大于b" : "a小于b";
//}
//int main()
//{
//	const char *v=str(5, 6);
//	std::cout << v << std::endl;
//}

//#include<iostream>
//class Outside
//{
//public:
//	Outside()
//	{
//		std::cout << "外部的无参构造" << std::endl;
//	}
//	~Outside()
//	{
//		std::cout << "外部的析构函数" << std::endl;
//	}
//	Outside(int num)
//	{
//		this->m_Num = num;
//		std::cout << "外部的有参构造" << std::endl;
//	}
//	int m_Num;
//public:
//	class Nested
//	{
//	public:
//		Nested()
//		{
//			std::cout << "嵌套的无参构造" << std::endl;
//		}
//		~Nested()
//		{
//			std::cout << "嵌套的析构函数" << std::endl;
//		}
//		Nested(int num)
//		{
//			this->z_Num = num;
//			std::cout << "嵌套的有参构造" << std::endl;
//		}
//		int z_Num;
//	};
//	//我们也可以直接在嵌套类所在的类内创建嵌套类对象
//	//Nested num;
//};
//void test01()
//{
//	Outside v(10);
//	std::cout << sizeof v << std::endl;
//	//创建嵌套类对象,得使用作用域解析运算符，先声明在哪个类才能创建
//	//嵌套类只是语义上的嵌套，并不包含
//	//因为是嵌套类是公工权限，所以可以在外部访问创建
//	Outside::Nested num;
//	std::cout << sizeof num << std::endl;
//}
//int main() {
//	test01();
//}
//#include<iostream>
//#include<cctype>
//
//int main()
//{
//	std::cout << (isalnum('5')) << std::endl;
//}

////string输入输出构造
//#include<iostream>
//#include<string>
////占位参数，加不加逗号都一样
//void print(int num...)
//{
//	std::cout << num << std::endl;
//}
//void test01()
//{
//	//表示从第四个字符开始复制4个给初始化name对象
//	std::string name( std::string("abcdefg"),3,4 );
//	std::cout << name << std::endl;
//}
//void test02()
//{
//	std::string name;
//	//第三个是可选参数，遇到.就把name拿出输入流，.和.以后的数据不会被储存，是无效数据
//	getline(std::cin, name, '.');
//	std::cout << name << std::endl;
//	std::cout << name.size() << std::endl;
//}
//void test03()
//{
//	//打印string的上限
//	std::cout << (std::string::npos) << std::endl;
//}
//void test04()
//{
//	std::string name = "12345678";
//	//结果是4，因为下标从0开始计算，返回查找的字符串首地址，第二个参数是从第几个开始查找
//	std::cout << (name.find("5678", 0)) << std::endl;
//}
//void test05()
//{
//	//string类重载了关系运算符
//	std::string name = "哈哈";
//	std::string name2(name);
//	std::cout << (name == name2)<< std::endl;
//}
//void test06()
//{
//	//调用
//	print(5);
//	print(5,20000,8888);
//}
//int main()
//{
//	//test01();
//	//test02();
//	//test03();
//	//test04();
//	//test05();
//	test06();
//	return 0;
//}

//不能的行为，错误的，不可能
//#include<iostream>
//class Person
//{
//public:
//	friend std::ostream& operator<<(const std::ostream& cout,const Person&v);
//	std::ostream& operator<<(std::ostream& cout,Person&v)
//	{
//		
//	}
//	Person(int name, int age)
//	{
//		this->m_Age = age;
//		this->m_Name = name;
//		
//	}
//private:
//	int m_Name;
//	int m_Age;
//};
//void test01()
//{
//	Person v(100, 12);
//}
//int main()
//{
//	test01();
//}
//#include<stdio.h>
//void arr(int* v,int num)
//{
//	int aver = 0,min=v[0], max = 0;
//	for (int i = 0; i < num; i++) {
//		aver += v[i];
//		if (v[i] > max)max = v[i];
//	}
//	for (int i = 1; i < num; i++) {
//		if (v[i] < min)min = v[i];
//	}
//	aver /= num;
//	printf("%d,%d,%d", max, min, aver);
//}
//void n(int t[], int b)
//{
//	int a, c, i;
//	for (a = 1; a < b; a++)
//	{
//		for (c = 0; c < b - a; c++)
//		{
//			if (t[c] < t[c + 1])
//			{
//				i = t[c]; t[c] = t[c + 1]; t[c + 1] = i;//冒泡排序从大到小
//			}
//		}
//	}
//}
//int main()
//{
//	int scores[20] = { 0 };
//	for (int i = 0; i < 20; i++)scanf("%d", scores + i);
//	arr(scores,20);
//	n(scores, 20);
//	for (int i = 0; i < 20; i++)printf("%d\t", scores[i]);
//	return 0;
//}

//#include<iostream>
//#include<string>
//void demon1()
//{
//	std::string name = "哈哈哈";
//	printf("%p\n", "哈哈哈");
//	printf("%p\n", name.data());
//}
//void test02()
//{
//	printf("%p\n", "哈哈哈");
//	printf("%p\n", "哈哈哈");
//}
//int main()
//{
//	demon1();
//	test02();
//	printf("%p\n", "哈哈哈");
//	return 0;
//}

//#include<iostream>
//void test01()
//{
//	int a[2][3]{ 1,2,3,4,5,6 };
//	int(*p)[3] = a;
//	int num = *(*(p + 1) + 1);
//	std::cout <<num<< std::endl;
//}
//int main()
//{
//	test01();
//}

//#include<iostream>
//#include<istream>
//void test01()
//{
//
//}
//int main()
//{
//	test01();
//	return 0;
//}
//#include<iostream>
//int main()
//{
//	int max = 0, temp;
//	for (int i = 0; i < 5; i++) {
//		std::cin >> temp;
//		if (temp > max)max = temp;
//	}
//	std::cout << max << std::endl;
//	return 0;
//}
//使用手写函数比较字符串
//#include<iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//int test01(const char*str,const char*str2)
//{
//	while (*str!='\0' or *str2!='\0')
//	{
//		if (*str++ != *str2++)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i=test01("傻子", "傻子");
//	cout << i << endl;
//}
//#include<iostream>
//void test01()
//{
//	//更改默认填充字符，从空格变成*，如果不更改回来一直都是这样
//	std::cout.fill('*');
//	//填充字符 只影响项目下第一句话，意思就是说打印10个*这么简单，默认是空格，其实就是调整格式的
//	std::cout.width(10);
//	std::cout << 2 << std::endl;
//	std::cout << 3 << std::endl;
//}
//void test02()
//{
//
//}
//int main()
//{
//	//填充字符
//	test01();
//
//	test02();
//	return 0;
//}
//#include<iostream>
//#include<fstream>
//int main() {
// //这种默认情况是会截短的，意思就是打开就会把文件数据清楚掉
//	std::ofstream ofs("文件.txt");
//}
//#include <fstream>
//#include <string>
//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	char m_Name[64];
//	int m_Age;
//};
//
////二进制文件  写文件
//void test01()
//{
//	//1、包含头文件
//
//	//2、创建输出流对象
//	ofstream ofs("person.txt", ios::out | ios::binary);
//
//	//3、打开文件
//	//ofs.open("person.txt", ios::out | ios::binary);
//
//	Person p = { "张三"  , 18 };
//
//	//4、写文件
//	ofs.write((const char*)&p, sizeof(p));
//
//	//5、关闭文件
//	ofs.close();
//}
//void test02()
//{
//	ifstream ifs("person.txt", ios::in | ios::binary);
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//	}
//
//	Person p;
//	ifs.read((char*)&p, sizeof(p));
//
//	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
//}
//void test03()
//{
//	fstream fs("文件.txt", ios::in |ios::out| ios::binary);
//	Person p{ "张三"  , 18 },p2;
//	fs.write((const char*)&p, sizeof(p));
//	fs.read((char*)&p2, sizeof(p2));
//	cout << p2.m_Age << " " << p2.m_Name << endl;
//	fs.close();
//}
//int main() {
//
//	//test01();
//
//	//test02();
//
//	test03();
//
//	return 0;
//}
//#include<iostream>
//int main()
//{
//	std::cout << typeid(5.2).name() << std::endl;
//	std::cout << typeid(5.2F).name() << std::endl;
//	std::cout << typeid(5).name() << std::endl;
//	std::cout << typeid(5L).name() << std::endl;
//	std::cout << typeid(5U).name() << std::endl;
//	std::cout << typeid(5LLU).name() << std::endl;
//	return 0;
//}

//c++ prime plus 641面复习题
//#include <iostream>
//#include <iomanip>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int count = str.find('$');
//	for (unsigned int i = 0; i < str.size(); i++)
//	{
//
//		if (str.at(i) != '$')
//			cout << str.at(i);
//	}
//	cout << endl << "Number: " << count << endl;
//	return 0;
//}
//#include<iostream>
//void func(int(*num)[5])
//{
//	for (int i = 0; i < 25; i++) {
//		std::cout << num[0][i] << std::endl;
//	}
//}
//int main()
//{
//	int a[5][5]{ 0 };
//	func(a);
//}
//#include <iostream>
//int main()
//{
//	int num[5]{ 10,2,3,4,5 };
//	int num2[5]{ 9,5,6,7,8 };
//	for (int i = 0; i < 5 - 1; i++) {
//		for (int j = 0; j < 5 - i - 1; j++) {
//			if (num[j] > num[j + 1]) {
//				std::swap(num[j], num[j + 1]);
//				std::swap(num2[j], num2[j + 1]);
//			}
//		}
//	}
//	for (int i : num)std::cout << i << " ";
//	std::cout<<std::endl;
//	for (int i : num2)std::cout << i << " ";
//	return 0;
//}
//#include<iostream>
//class MM
//{
//public:
//	void print()
//	{
//		std::cout << "1" << std::endl;
//	}
//};
//template<class T>
//void show(T print)
//{
//	std::cout << typeid(T).name() << std::endl;
//}
//void test01()
//{
//	MM mm;
//	show(&MM::print);
//}
//int main()
//{
//	test01();
//}
//#include<iostream>
//#include<valarray>
//int main()
//{
//	std::valarray<int>num{ 1,2,3,4,5,6,7,8,9,10 };
//	std::cout << num.min() << std::endl;
//}
//#include<stdio.h>
//int main()
//{
//	int num = 12345678, temp = 0,n=1;
//	while (num)
//	{
//		++n;
//		if (n % 2 != 0)
//		{
//			num /= 10;
//			continue;
//		}
//		temp = temp * 10 + num % 10;
//		num /= 10;
//	}
//	printf("%d", temp);
// 
//}
//#include<iostream>
//#include<conio.h>
//int main()
//{
//	char c;
//	c = _getch();
//	std::cout << std::dec << c << std::endl;
//}
//#include<iostream>
//int main()
//{
//	double i = 50;
//	double* p = &i;
//	int* q = (int*)&i;
//	std::cout << *q << std::endl;
//	std::cout << *p << std::endl;
//	std::cout << q << std::endl;
//	std::cout << p << std::endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//void test01()
//{
//	std::cout << "请输入数字" << std::endl;
//	std::string num;
//	std::getline(std::cin, num);
//	//字符串转数字
//	std::vector<int>num2;
//	int temp = std::stoi(num);
//	std::cout << "请问你要把10进制转成几进制数:";
//	int i;
//	std::cin >> i;
//	while (temp) {
//		num2.push_back(temp % i) ;
//		temp /= i;
//	}
//	//因为二进制是从右往左输出，所以我们使用vector容器提供的rbegin和rend方法倒序输出
//	for (auto i = num2.rbegin(); i != num2.rend(); i++) {
//		//设置16进制的情况
//		if (*i >= 10)
//		{
//			switch (*i)
//			{
//			case 10: std::cout.put('A'); break;
//			case 11: std::cout.put('B'); break;
//			case 12: std::cout.put('C'); break;
//			case 13: std::cout.put('D'); break;
//			case 14: std::cout.put('E'); break;
//			case 15: std::cout.put('F'); break;
//			}
//			continue;
//		}
//		std::cout << *i;
//	}
//}
//int main()
//{
//	test01();
//	std::cin.get();
//	std::cin.get();
//	return 0;
//}
//#include<iostream>
//#include<string>
//int main()
//{
//	typedef int a;
//	a i = 0;
//	using v = int;
//	v i2 = 0;
//	std::cout << typeid(i).name() << std::endl;
//	std::cout << typeid(i2).name() << std::endl;
//	return 0;
//}
//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//int main()
//{
//	int length = 0, temp = 0;
//	scanf("%d", &length);
//	while (length)
//	{
//		temp = temp * 10 + length%10;
//		length /= 10;
//	}
//	printf("%d", temp);
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//int f(int x)
//{
//    if (x == 0)
//        return 0;
//    else
//        return 2 * f(x - 1) + x * x;
//}
//
//int main()
//{
//    cout << "f(5) = " << f(5) << endl;
//    return 0;
//}
//#include<iostream>
//#include<string>
//void func(char*str) {
//	char* temp = str;
//	while (*temp)temp++;
//	--temp;
//	while (*temp == '*')*temp-- = 0;
//}
//int main()
//{
//	char str[20] = "123***a***";
//	func(str);
//	std::cout << str << std::endl;
//	return 0;
//}
//#include<iostream>
//#include<memory>
//void merge(int arr[],int start,int end,int mid,int*temp) {
//	int i_start = start;
//	int i_end = mid;
//	int j_start = mid + 1;
//	int j_end = end;
//
//	int Length = 0;
//	while (i_start <= i_end && j_start <= j_end) {
//		if (arr[i_start] < arr[j_start]) 
//			temp[Length++] = arr[i_start++];
//		else
//			temp[Length++] = arr[j_start++];
//	}
//	while (i_start <= i_end) {
//		temp[Length++] = arr[i_start++];
//	}
//	while (j_start <= j_end) {
//		temp[Length++] = arr[j_start++];
//	}
//	for (int i = 0; i < Length; i++) {
//		arr[start + i] = temp[i];
//	}
//}
//void mergeSort(int arr[], int start, int end, int* temp) {
//	if (start >= end) {
//		return;
//	}
//	int mid = (start + end) / 2;
//	mergeSort(arr, start, mid, temp);
//	mergeSort(arr, mid+1,end, temp);
//	merge(arr, start, end, mid, temp);
//}
//int main()
//{
//	int num[10]{ 10,9,8,7,6,5,4,3,2,1 };
//	std::unique_ptr<int>temp(new int[10]);
//	mergeSort(num, 0, 9, temp.get());
//	for (auto i : num)std::cout << i << ",";
//	return 0;
//}
//#include<iostream>
//void merge(int arr[], int start, int end, int mid, int* temp) {
//	int i_start = start;
//	int i_end = mid;
//	int j_start = mid + 1;
//	int j_end = end;
//	int Lenght = 0;
//	while (i_start <= i_end && j_start <= j_end) {
//		if (arr[i_start] < arr[j_start])
//			temp[Lenght++] = arr[i_start++];
//		else
//			temp[Lenght++] = arr[j_start++];
//	}
//	while (i_start <= i_end) {
//		temp[Lenght++] = arr[i_start++];
//	}
//	while (j_start <= j_end) {
//		temp[Lenght++] = arr[j_start++];
//	}
//	for (int i = 0; i < Lenght; i++) {
//		arr[start + i] = temp[i];
//	}
//}
//void mergeSort(int arr[], int start, int end, int* temp) {
//	if (start >= end) {
//		return;
//	}
//	int mid = (start + end) / 2;
//	mergeSort(arr, start, mid, temp);
//	mergeSort(arr, mid + 1, end, temp);
//	merge(arr, start, end, mid, temp);
//}
//int main()
//{
//	int num[10]{ 10,9,8,7,6,5,4,3,2,1 };
//	std::unique_ptr<int>temp(new int[10]);
//	mergeSort(num, 0, 9, temp.get());
//	for (auto i : num)std::cout << i << ",";
//	return 0;
//}
//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//int func(const char*a, const char*b) {
//	while (*a!='\0' && *b != '\0') {
//		if (*a ++!= *b++)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	char ch[10] = "哈哈", ch2[10] = "哈哈";
//	printf("%d", func(ch2, ch));
//	return 0;
//}
//#include<iostream>
//#include<string>
//int main()
//{
//	int a = 0;
//	[&]()mutable {a = 100;}();
//	std::cout << a << std::endl;
//	std::pair<int, int>V;
//	V.first = 1;
//	V.second = 10;
//	std::cout << V.first << std::endl;
//	return 0;
//}
//#include<iostream>//在模板类内给成员函数使用模板
//#include<string>
//template<typename T>
//class Test
//{
//public:
//	template<typename A>
//	void print(A i) {
//		std::cout << "test" << i << std::endl;
//	}
//
//private:
//	int a;
//	int b;
//};
//int main()
//{
//	Test<int>V;
//	V.print(10);
//	return 0;
//}

//#include<iostream>
//#include<string>
//int main()
//{
//	int a2 = 10;
//	char const a = 10;
//	char const* p = &a;
//	const char* q = &a;
//	constexpr const static int c = 10;
//
//	const int* p2 = &a2;//这两个一个意思
//	int const* p3 = &a2;
//	*p3 = 20;
//
//	int* const p4 = &a2;
//	*p4 = 10;
//	return 0;
//}
//#include<iostream>
//#include<string>
//int main()
//{
//	const char* a[2]{ "123","456" };
//	std::cout << *a[1] << "," << a[1][0] << std::endl;
//	return 0;
//}
//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//double func1(int r)//面积
//{
//	return 3.14 * 4 * pow(r, 2);
//}
//double func2(int r)//体积
//{
//	return 3.14 * pow(r, 2);
//}
//int prime(int n){
//	for (int i = 2; i < n; i++) {
//		if (n % i == 0)return 0;
//	}
//	return 1;
//}
//int main()
//{
//	printf("面积为:%lf,体积为%lf\n", func1(5), func2(4));
//	printf("%d", prime(34));
//	return 0;
//}
//#include<iostream>
//#include<string>
//
//	//template<typename T, typename... U> auto array(T, U...)->std::array<std::enable_if_t<(std::is_same_v<T, U>&& ...), T>,(1 + sizeof...(U))>;
//namespace st{
//template<typename T, typename ...U>
//auto array(T, U ...)->std::array<std::enable_if_t<(std::is_same_v<T, U>&&...), T>, (1 + sizeof ...(U))>;
//}
//int main()
//{
//
//	return 0;
//}
//#include<iostream>
//constexpr int func()
//{
//	return 5;
//}
//template<typename C, typename... Idx>
//void printElems(C const& coll, Idx... idx)
//{
//	((std::cout << coll[idx]<<","),...);
//}
//int main()
//{
//	const int num[func()] { 1, 2, 3, 4, 5 };
//	printElems(num, 1, 2, 3, 4);
//	return 0;
//}
//#include<iostream>
//#include<string>
//class Sun
//{
//public:
//	Sun() {};
//	Sun(int num) { this->num = num; };
//	int get_num() { return this->num; }
//	Sun* set_num(int num) { this->num = num; return this; }
//private:
//	int num;
//};
//class Base
//{
//public:
//	Base(Sun sun) { this->sun = sun; };
//	Sun& get_sun() { return this->sun; }
//	Base* set_sun(Sun sun) { this->sun = sun; return this; }
//private:
//	Sun sun;
//};
//
//int main()
//{
//	Base v(Sun(20));
//	std::cout << v.get_sun().get_num() << std::endl;
//	v.get_sun().set_num(10);
//	std::cout << v.get_sun().get_num() << std::endl;
//	v.set_sun(Sun(100));
//	std::cout << v.get_sun().get_num() << std::endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<limits.h>
//int main()
//{
//	std::cout << (1 << 31) << std::endl;
//	std::cout << (1 << 31)-1 << std::endl;
//	std::cout << INT_MAX << std::endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//template<typename T>
//void passR(T&& arg) { // arg declared as forwarding reference
//	std::cout << typeid(T).name()  << std::endl;
//}
//int main()
//{
//	std::string str{ "哈哈" };
//	std::string str2(std::move(str));
//	std::cout << str << std::endl;//被掏空无法输出
//	passR(std::move(str2));//str被掏空
//	std::cout << str2 << std::endl;//被掏空无法输出
//	//str = "哈哈";
//	//std::string&& str2(std::move(str));
//	//passR(std::move(str2));//再次被掏空
//	
//	return 0;
//}
//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//int function(int n) {
//	int i = 0;
//	while (n) {
//		n /= 10;
//		i++;
//	}
//	return i;
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int i = function(num);
//	printf("%d", i);
//	return 0;
//}
//#include<iostream>
//#include<string>
//template<unsigned p, unsigned d> // p：要检查的数字，d：当前除数
//struct DoIsPrime {
//	static constexpr bool value = (p % d != 0) && DoIsPrime<p, d - 1>::value;
//};
//template<unsigned p> // 如果除数为 2，则结束递归
//struct DoIsPrime<p, 2> {
//	static constexpr bool value = (p % 2 != 0);
//};
//template<unsigned p> // 主模板
//struct IsPrime {
//	// 从 p/2 开始用除数开始递归：
//	static constexpr bool value = DoIsPrime<p, p / 2>::value;
//};
//int main()
//{
//	int num[IsPrime<5>::value]{ 10 };	//因为编译期就已经得出结果，所以可以做数组下标
//	std::cout << *num << std::endl;
//	std::cout << IsPrime<21>::value << std::endl;
//	std::cout << IsPrime<17>::value << std::endl;
//	return 0;
//}
//比较字符串是否相等
//#include<iostream>
//#include<string>
//#include<algorithm>
//int main()
//{
//	std::string str;
//	std::cin >> str;
//	std::cout << str << std::endl;
//	std::string str_ = str;
//	std::reverse(str_.begin(), str_.end());
//	bool i = str == str_;
//	std::cout << i << std::endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//
//template<typename T,size_t num>
//auto func(T(&n)[num]) {
//	std::cout << num << std::endl;
//}
//int main()
//{
//	int num[10];
//	std::vector<int>n(10);
//	std::cout<<std::size(num);
//	std::cout << std::size(n);
//	func(n);
//	return 0;
//}
//#include<iostream>
//#include<string>
//template<typename T, typename...Types>
//void print(T const& firstArg, Types const&...args)
//{
//	std::cout << firstArg << std::endl;
//	if constexpr (sizeof...(args) > 0) {
//		print(args...); //代码仅在以下情况下可用...（args）>0 （自 C++17 起）
//	}
//}
//int main()
//{
//	print(1, 2, 3, 4, 5, 6);
//	return 0;
//}
//#include<iostream>
//#include<string>
//template<typename... Args>
//decltype(auto) call(Args&& ... args) {
//	return (... - args);
//}
//（在C++14 中引入）是一个占位符类型，它根据相关表达式决定了变量、返回值、或者模板实参的类型。

//template<typename T>
//decltype(auto) test1(T& v) {
//	std::cout << "decltype(auto) test1(T& v)" << std::endl;
//	return v;
//}
//
//template<typename T>
//auto test2(T& v) {
//	std::cout << "auto test2(T& v)" << std::endl;
//	return v;
//}
//
//template<typename T>
//auto test3(T& v)->decltype(v) {
//	std::cout << "auto test3(T& v)->decltype(v)" << std::endl;
//	return v;
//}
//auto test4(auto x, auto y) -> decltype(x < y ? y : x)
//{
//	return x < y ? y : x;
//}
//
//int main()
//{
//	int&& b = call(10, 5, 3);
//	std::cout << b << std::endl;
//
//	std::string str;
//	test1(str);
//	test2(str);
//	test3(str);
//	int i=test4(5, 6);
//	std::cout << i << std::endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//class A {
//public:
//	int a = 0;
//};
//auto Test(auto&v) {
//	return v;
//}
//decltype(auto) Test2(auto& v) {
//	return v;
//}
//int main()
//{
//	A a;
//	A &b = Test2(a);
//	std::cout << a.a << "," << b.a << std::endl;
//	b.a = 10;
//	std::cout << a.a << "," << b.a << std::endl;
//	//Test2这种方式能推导出返回引用
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        int i, j;
//        for (i = 0; i < nums.size() - 1; i++)
//        {
//            for (j = i + 1; j < nums.size(); j++)
//            {
//                if (nums[i] + nums[j] == target)
//                {
//                    return { i,j };
//                }
//            }
//        }
//        return {};
//    };
//};
//int main()
//{
//    vector<int>n{ 1,2,3,4,5 };
//    Solution v;
//    auto temp = v.twoSum(n, 4);
//    std::cout << temp[0] << "," << temp[1] << endl;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* dummyHead = new ListNode(0);//保存头结点作为返回
//        ListNode* cur = dummyHead;//cur辅助指针
//        int carry = 0;//保存值
//        while (l1 || l2 || carry) {
//            if (l1 != NULL) carry += l1->val;//获取值
//            if (l2 != NULL) carry += l2->val;//获取值
//            ListNode* tmp = new ListNode(carry % 10);//创建结点存储值
//            cur->next = tmp;//指针指向结点
//            cur = cur->next;//指针前进
//            if (l1 != NULL) l1 = l1->next;//前进
//            if (l2 != NULL) l2 = l2->next;//前进
//            carry /= 10;//我们不重置0，而是/=10，如果carry为12我们，在前面%10，存储了2，我们/=10,保存1
//        }
//        return dummyHead->next;//最后当不满足循环条件的时候退出循环返回头结点，即carry为0也就是储存完了所有的值，且传入的两个链表为空
//    }
//};
//int main()
//{
//
//    return 0;
//}
//#include<sort.h>
//#include<iostream>
//int main()
//{
//	int num[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	std::unique_ptr<int>temp(new int[10]);
//	sort_::mergeSort(num, 0, 9, temp.get());
//	//折半查找一样的得先排序才能进行，我们都是从小到大的规则
//	for (auto i : num)std::cout << i << ",";
//
//	std::endl(std::cout);
//	//第一个参数是数组，第二个是key，第三个是长度
//	std::cout << find_::binarySearch(num, 5, 10) << std::endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//    int reverse(int x) {
//		string str = to_string(x);
//		if (str[0] == '-')
//		{
//			std::reverse(str.begin()+1, str.end());
//			return stoi(str);
//		}
//		else
//		{
//			std::reverse(str.begin(), str.end());
//			return stoi(str);
//		}
//    }
//};
//int main()
//{
//	Solution temp;
//	cout << temp.reverse(1534236469) << endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    int reverse(int x) {
//        long n = 0;
//        while (x != 0) {
//            n = n * 10 + x % 10;
//            x = x / 10;
//        }
//        return (int)n == n ? (int)n : 0;
//    }
//};
//int main()
//{
//	cout<<Solution().reverse(-123) << endl;
//	return 0;
//}
//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//double aver(int* max, int* min, int num[], int len) {
//	*max = num[0], * min = num[0];
//	double sum = num[1];
//	for (int i = 1; i < len; i++) {
//		if (num[i] > *max)*max = num[i];
//		if (num[i] < *min)*min = num[i];
//		sum += num[i];
//	}
//	return sum / len;
//}
//int main()
//{
//	int max = 0, min = 0,  num[20] = { 0 };
//	double ave = 0;
//	for (int i = 0; i < 20; i++) {
//		scanf("%d", num + i);
//	}
//	ave=aver(&max, &min, num, 20);
//	printf("max=%d,min=%d,ave=%lf", max, min, ave);
//	return 0;
//}
//#include<iostream>
//#include<valarray>
//int main()
//{
//	std::valarray<int>num(20);
//	for (int i = 0; i < 20; i++)std::cin >> num[i];
//	std::cout << num.max() << "," << num.min() << "," << num.sum() / 20. << std::endl;
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//int main()
//{
//	int num[20]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 },aver=0;
//	std::sort(std::begin(num), std::end(num));
//	for (auto i : num)aver += i;
//	std::cout << "小=" << num[0] << "大=" << num[19] << "平均=" << aver / 20.0 << std::endl;
//	return 0;
//}
#include <functional>
#/*include<iostream>
#include<vector>
#include<set>
class T {
public:
	bool operator()(auto a, auto b)const {
		return a > b;
	}
};
int main()
{
	std::set<int, T>s1;
	s1.insert(10);
	s1.insert(5);
	s1.insert(3);
	for (auto i : s1)std::cout << i << ",";
	return 0;
}*/
//#include<iostream>
//int Sum(int i[], int n) {
//	return n < 1 ? 0 : Sum(i, n - 1) + i[n - 1];
//}
//int main()
//{
//	int t[5]{ 1,2,3,4,5 };
//	std::cout << Sum(t, 5) << std::endl;
//	return 0;
//}
//#include<stdio.h>
//int func(int n) {
//	if (n == 0 || n == 1)return 1;
//	return n*func(n - 1);
//}
//int main() {
//	int n,sum=0;
//	scanf("%d", &n);
//	for (int i = 2; i <= n; i++)sum += func(i);
//	printf("%d", sum);
//}
//#include<iostream>
//#include<unordered_map>
//#include<string>
//int main()
//{
//	std::unordered_map<std::string, std::string>tempUmap{
//		{"Python教程","http://c.biancheng.net/python/"},
//		{"Java教程","http://c.biancheng.net/java/"},
//		{"Linux教程","http://c.biancheng.net/linux/"} };
//	std::unordered_map<std::string, std::string>t(std::move(tempUmap));
//}
//#include<iostream>
//#include<string>
//#include<fstream>
//#include<cstdio>
//void newFolder(std::string s = "Test", std::string path = "") {
//	std::string temp = "md ";
//	temp += path;
//	temp += s;
//	std::cout <<"创建文件夹 " << temp  << std::endl;
//	system(temp.data());
//}
//void newWriteFile(std::string name = "Test.txt", std::string data = "yyds", std::string path = "") {
//	path += name;
//	std::ofstream ofs;
//	ofs.open(path, std::ios::app);
//	ofs << data;
//	ofs.close();
//}
//void deleteData(std::string name = "Test.txt", std::string path = "") {
//	path += name;
//	std::ofstream ofs(path, std::ios::trunc);
//	ofs.close();
//}
//void deleteFile(std::string path = "") {
//	if (remove(path.data()) == 0) { 
//		std::cout << "删除成功" << std::endl; 
//	}
//	else {
//		std::cout << "删除失败" << std::endl;
//	}
//}
//std::string readFile(std::string path) {
//	std::ifstream ifs;
//	ifs.open(path, std::ios::in);
//	if (!ifs.is_open())
//	{
//		std::cout << "文件打开失败" << std::endl;
//		return "";
//	}
//	std::string data{};
//	while (ifs >> data);
//	ifs.close();
//	return data;
//}
//template<typename _Type1, typename _Type2, typename... _Types>
//void print(_Type1 _Value1, _Type2 _Value2, _Types... _Values)
//{
//	std::cout << _Value1 << ',' << _Value2 << ",";
//	((std::cout << _Values << ','), ...);
//}
//
//int main()
//{
//	//newFolder("测试","D:\\自用\\");
//	//newWriteFile("测试.txt", "123456");
//	//deleteData("测试.txt");
//	//deleteFile("测试.txt");
//	//std::cout << readFile("测试.txt") << std::endl;
//	print("666666666", 5, 5.7, 8u);
//	return 0;
//}
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int main()
//{
//	time_t timep;
//	time(&timep);
//	char tmp[256];
//	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
//	cout << tmp << endl;
//	return 0;
//}
//#include<iostream>
//#include<array>
//#include<string>
//#include<vector>
//template<typename T>
//std::ostream& operator<<(std::ostream& os,const std::vector<T>&data)
//{
//	for (auto& str : data)
//	{
//		os << str;
//	}
//	return os;
//}
//void print(){}
//template<typename T,typename...Types>
//void print(T first, Types...args){
//	std::cout << first << '\n';
//	print(args...);
//	return;
//}
//int main()
//{
//	std::vector<std::string>a{ "离谱" }, b{ "6666" }, c{ "阿巴巴" };
//	print(a, b, c, 10);
//}
//#include<iostream>
//#include<string>
//template<typename T,size_t size>
//void leftMove(T(&v)[size], int n) {
//	int temp;
//	for (int i = 0; i < n; i++) {
//		temp = v[0];
//		for (int j = 0; j < size-1; j++) {
//			v[j] = v[j + 1];
//		}
//		v[size - 1] = temp;
//		temp = 0;
//	}
//}
//template<typename T, size_t size>
//void rightMove(T(&v)[size], int n) {
//	int temp;
//	for (int i = 0; i < n; i++) {
//		temp = v[size-1];
//		for (int j = size-1; j >0; j--) {
//			v[j] = v[j - 1];
//		}
//		v[0] = temp;
//		temp = 0;
//	}
//}
//template<typename T, size_t size>
//void arrayShift(T(&v)[size], int n,bool k=true) {
//	int temp;
//	if (k) {
//		for (int i = 0; i < n; i++) {
//			temp = v[0];
//			for (int j = 0; j < size - 1; j++) {
//				v[j] = v[j + 1];
//			}
//			v[size - 1] = temp;
//			temp = 0;
//		}
//	}
//	else{
//		for (int i = 0; i < n; i++) {
//			temp = v[size - 1];
//			for (int j = size - 1; j > 0; j--) {
//				v[j] = v[j - 1];
//			}
//			v[0] = temp;
//			temp = 0;
//		}
//	}
//}
//int main()
//{
//	int n[5]{ 1,2,3,4,5 };
//	leftMove(n, 2);
//	for (auto i : n)std::cout << i << ",";
//	std::cout << std::endl;
//	rightMove(n, 2);
//	for (auto i : n)std::cout << i << ",";
//	std::cout << std::endl;
//	arrayShift(n, 2);
//	for (auto i : n)std::cout << i << ",";
//	std::cout << std::endl;
//	arrayShift(n, 2, false);
//	for (auto i : n)std::cout << i << ",";
//	std::cout << std::endl;
//	return 0;
//}
//#include<iostream>
//#include<array>
//template<typename T, size_t size>
//void arrayShift(std::array<T, size>&v, int n, bool k = true) {
//	int temp;
//	if (k) {
//		for (int i = 0; i < n; i++) {
//			temp = v[0];
//			for (int j = 0; j < size - 1; j++) {
//				v[j] = v[j + 1];
//			}
//			v[size - 1] = temp;
//			temp = 0;
//		}
//	}
//	else {
//		for (int i = 0; i < n; i++) {
//			temp = v[size - 1];
//			for (int j = size - 1; j > 0; j--) {
//				v[j] = v[j - 1];
//			}
//			v[0] = temp;
//			temp = 0;
//		}
//	}
//}
//int main()
//{
//	
//	std::array<int, 10>n2{ 1,2,3,4,5,6,7,8,9,10 };
//	arrayShift(n2, 2);
//	for (auto i : n2)std::cout << i << ",";
//}
//#include<stdio.h>
//#include<math.h>
//int func(int n[],int i) {
//	int num = 0;
//	int t = 0;
//	for (int a = i-1; a >= 0; a--,t++) {
//		if (n[a] == 0)continue;
//		num += 1 << t;
//	}
//	return num;
//}
//int main()
//{
//	int n[7]{ 1,0,1,0,1,1,1 };
//	printf("%d",func(n, 7));
//	return 0;
//}
//#include<iostream>
//#include<vector>
//template<typename T>
//int uniquify(std::vector<T>v) {
//	int oldSize = v.size(); int i = 0;
//	while (i < v.size() - 1) {
//		if (v[i] == v[i + 1]) {
//			v.erase(v.begin() + i);
//		}
//		else {
//			i++;
//		}
//	}
//	return oldSize - v.size();
//}
//int main() {
//	std::vector<int>v{1,1,2,2,3};
//	std::cout << uniquify(v) << std::endl;
//}
//#include<iostream>
//int main()
//{
//	std::cout << static_cast<unsigned>(-1) << std::endl;
//	std::cout << (~- 256) << std::endl;
//	std::cout << (~- 1) << std::endl;
//	std::cout << (~- 2) << std::endl;
//}
//#include<iostream>
//template<class T>
//auto binSearch(T* A, T const& e, T lo, T hi) {
//	while (1 < (hi - lo)) {
//		T mi = (lo + hi) >> 1;
//		e < A[mi] ? hi = mi : lo = mi;
//	}
//	return e == A[lo] ? lo : -1;
//}
//int main() {
//	int num[10]{ 1,2,3,4,5,6,7,8,9,10 };
//	std::cout << binSearch(num, 5, 0, 9) << std::endl;
//}

//多态
//#include<func.h>
//using namespace show_;
//using namespace input_;
//class A {
//public:
//	virtual void show() = 0;
//	
//};
//class B:public A {
//public:
//	virtual void show() override;
//};
//void B::show() {
//	print("B");
//}
//int main()
//{
//	A* a = new B;
//	a->show();
//	delete a;
//
//	return 0;
//}
//#include<func.h>
//using namespace show_;
//using namespace input_;
//class X {
//public:
//	mutable const int* p;         // OK const修饰的是指针指向的，而非指针自身，所以与mutable
//};
//int main()
//{
//	int a = 10;
//	int b = 1;
//	X x;
//	x.p = &a;
//	//*x.p = 100;	//错误的
//	print(*x.p);
//
//	return 0;
//}
//#include<iostream>
//void merge(int arr[],int start,int end,int mid,int*temp) {
//	int i_start = start;
//	int i_end = mid;
//	int j_start = mid + 1;
//	int j_end = end;
//	int Length = 0;
//	while (i_start <= i_end && j_start <= j_end) {
//		arr[i_start] <= arr[j_start] ? temp[Length++] = arr[i_start++] : temp[Length++] = arr[j_start++];
//	}
//	while (i_start <= i_end || j_start <= j_end) {
//		i_start <= i_end ? temp[Length++] = arr[i_start++] : temp[Length++] = arr[j_start++];
//	}
//	for (int i = 0; i < Length; i++)arr[start + i] = temp[i];
//}
//void mergeSort(int arr[], int start, int end, int* temp) {
//	if (start >= end)return;
//	int mid = (start + end) / 2;
//	mergeSort(arr, start, mid, temp);
//	mergeSort(arr, mid + 1, end, temp);
//	merge(arr, start, end, mid, temp);
//}
//int main() {
//	int temp[11]{ 0 };
//	int n[11]{ 11,10,9,8,7,6,5,4,3,2,1 };
//	mergeSort(n, 0, 10, temp);
//	for (auto i : n)std::cout << i << " ";
//}
//#include<func.h>
//using namespace show_;
//using namespace input_;
//void insertion_sort(int arr[], int len) {
//	int  key;
//	for (int i = 1; i < len; i++) {
//		key = arr[i];
//		int j = i - 1;	//j表示有序的序列的下标
//		while ((j >= 0) && (arr[j] > key)) {
//			arr[j + 1] = arr[j];	//让无序序列的元素加入到有序序列
//			j--;
//		}
//		arr[j + 1] = key;
//	}
//}
//int main()
//{
//	int n[5]{ 4,3,8,9,2 };
//	insertion_sort(n, 5);
//	print(n);
//	return 0;
//}
//#include<func.h>
//using namespace show_;
//void bubbleSort(int arr[], int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (arr[j] < arr[j + 1])std::swap(arr[j], arr[j + 1]);
//		}
//	}
//}
//int main() {
//	int n[5]{ 5,10,3,2,1 };
//	bubbleSort(n, 5);
//	print(n);
//}
//#include<iostream>
//int main()
//{
//	const int num = 1;
//	int* p_num = (int*)&num;
//	*p_num = 2;
//	int a = num, b = *p_num;
//	std::cout << num << std::endl;
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//
//}
//#include<func.h>
//#include<stack>
//using namespace std;
//class Solution {
//public:
//    bool validateStackSequences(vector<int> pushed, vector<int> popped) {
//        stack <int>s;
//        int count = 0;
//        for (int i = 0; i < pushed.size(); i++) {
//            s.push(pushed[i]);
//            while (!s.empty() && s.top() == popped[count]) {
//                s.pop();
//                count++;
//            }
//        }
//        if (!s.empty())
//            return false;
//        else
//            return true;
//    }
//};
//int main() {
//    std::cout << Solution().validateStackSequences( vector<int>{1,2,3}, vector<int>{3,1,2});
//}
//#include<iostream>
//#include<vector>
//template<typename T>
//class Vector :public std::vector<T> {
//public:
//	using std::vector<T>::vector;	//继承基类的构造函数
//	Vector() : std::vector<T>() {}
//	decltype(auto) operator[](int n) {
//		return n >= 0 ? this->std::vector<T>::operator[](n) : this->std::vector<T>::operator[](this->size() + n);
//	}
//};
//template<typename T, size_t size_>
//class Array {
//public:
//	Array() = default;
//	Array(std::initializer_list<T> init)
//	{
//		std::copy(init.begin(), init.end(), arr);
//	}
//	decltype(auto) operator[](int n) {
//		return n >= 0 ? arr[n] : arr[size_ + n];
//	}
//	size_t size() {
//		return size_;
//	}
//private:
//	int arr[size_];
//}; 
//int main() {
//	Vector<int>a;
//	Vector<int>b{ 1,2,3,4,5,6 };
//	for (int i = 0; i < 10; i++) {
//		a.push_back(i);
//	}
//	a[2] = 5;
//	std::cout << a[-2] << std::endl;
//	std::cout << b[-6] << std::endl;
//	std::cout << a[2] << std::endl;
//
//	Array<int, 5>n{ 6,8,9,10,11 };
//	std::cout << n[-1] << std::endl;
//	std::cout << n.size() << std::endl;
//	return 0;
//}
//#include<func.h>
//using namespace show_;
//using namespace input_;
//int main()
//{
//	int a, b, c;
//	input(a, b, c);
//	print(a, b, c, "无聊", 8, 7, 8, 9, 3.2, 1111.89788,'\n');
//	int n[10]{ 1,2,3,4,5,6,7,8,9,10 };
//	range::print(n,n,n,6,7);
//	return 0;
//}
//#include<thread>
//#include<iostream>
//void f() {
//	std::cout << 123 << ' ';
//}
//int main() {
//	std::thread a(f);
//
//	a.join();
//}
//#include <iostream>
//#include <thread>
//
//int main() {
//	unsigned int n = std::jthread::hardware_concurrency();
//	std::cout << n << " concurrent threads are supported.\n";
//}
//#include <iostream>
//#include <iterator>
//#include <vector>
//
//int main()
//{
//	std::vector<int> v{ 3, 1, 4 };
//
//	auto vi = v.begin();
//
//	std::advance(vi, 2);
//
//	std::cout << *vi << '\n';
//}
//#include<iostream>
//#include<functional>
//void A(int& a)
//{
//	a = 100;
//	std::cout << a << std::endl;
//}
//int main() {
//	int a = 0;
//	std::function<void()>T = std::bind(A, a);
//	T();
//	std::cout << a << std::endl;
//}
//#include<iostream>
//#include<thread>
//#include<vector>
//#include<mutex>
//
//std::mutex I;
//
//void f(int& i) {
//	I.lock();
//	std::cout << i++ << std::endl;
//	I.unlock();
//}
//void g(int& i) {
//	std::lock_guard<std::mutex>a(I);
//	std::cout << i++ << std::endl;
//}
//int main() {
//	int n = 1;
//	std::vector<std::jthread>a;
//	for (int i = 0; i < 10; i++) {
//		//a.emplace_back(f, std::ref(n));
//		a.emplace_back(g, std::ref(n));
//	}
//}
//#include<iostream>
//#include<thread>
//#include<mutex>
//
//std::mutex I;
//
//void g(int& i) {
//	std::lock_guard<std::mutex>a{ I };
//	std::cout << i++ << std::endl;
//	
//}
//int main() {
//	int n = 1;
//	std::vector<std::thread>a;
//	for (int i = 0; i < 10; i++) {
//		a.emplace_back(g, std::ref(n));
//	}
//	for (auto& i : a) {				
//		i.join();
//	}
//}
//#include<iostream>
//decltype(auto) func() {
//	int a = 100;
//	return a;
//}
//int main() {
//	int a = func();
//	std::cout << a << std::endl;
//}
//#include<iostream>
//void swap(auto& a, auto& b) {
//	a ^= b;
//	b ^= a;
//	a ^= b;
//}
//int main() {
//	int a = 1, b = 2;
//	swap(a, b);
//	std::cout << a << ' ' << b << std::endl;
#include<iostream>
#include"lib/span.hpp"
#include<vector>
#include<list>

int main() {
	std::list l1{ 1,2,3 };
	std::list l2{ 1,2,3 };
	l1 = l2;
	std::cout << &(*l2.begin()) << '\n' << &(*l1.begin()) << '\n';
	std::list l3(l1.begin(), l1.end());
	std::cout << *++l1.begin() << std::endl;
}
