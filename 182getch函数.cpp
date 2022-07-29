//#include<iomanip>
//#include<iostream>
//#include<conio.h>
//#include<Windows.h>
//void test01()
//{
//	char ch = 0;
//	//不回显函数，从输入流中获取数据
//	while (ch = getch())
//	{
//		if (ch == '0')break;
//		else 
//		{ 
//			std::cout <<"哈哈" << std::endl;
//		}
//	}
//	std::cout << "退出" << std::endl;
//}
//
//void test02()
//{
//	std::cout << typeid(5.2).name() << std::endl;
//	std::cout << typeid(5.2l).name() << std::endl;
//	std::cout << typeid(5.2f).name() << std::endl;
//	std::cout << typeid(5u).name() << std::endl;
//	std::cout << typeid(5l).name() << std::endl;
//	std::cout << typeid(5ull).name() << std::endl;
//	std::cout << typeid(5ll).name() << std::endl;
//	std::cout << typeid(5).name() << std::endl;
//	//测试数据的类型
//	//直接越界读取
//	int a[2][2]{ 1,2,3,4 };
//	std::cout << a[0][3] << std::endl;
//}
//
//void test03()
//{
//	HANDLE hOut;
//	COORD pos = { 15,5 };
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(hOut, pos);
//
//	SetConsoleTextAttribute(hOut, 0x01 | 0x05);
//
//	printf("HelloWorld!\n");
//	SetConsoleCursorPosition(hOut, pos);
//	SetConsoleTextAttribute(hOut, 0x01 | 0x05);
//	printf("123132!\n");
//
//}
//int main()
//{
//	//test01();
//	//test02();
//	test03();
//	return 0;
//}
