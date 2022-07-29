//#include<iostream>
//#include<iomanip>
//#include<string>
//#include"conio.h"
//#include"windows.h"
//#include<vector>
//#include<Windows.h>
//using namespace std;
//
////方向枚举
////限定作用域枚举类型!!!
////1、枚举类型中枚举成员的类型可以显式指定，指定方式是在枚举类型名称后加冒号和枚举成员类型。
//enum class MOVE :int
//{
//
//	UP = 72,//向上
//	DOWN = 80,//向下
//	LEFT = 75,//向左
//	RIGHT = 77//向右
//};
//
//int main()
//{
//
//	HANDLE hOut;
//	COORD pos = { 1,1 };
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO CursorInfo;
//	GetConsoleCursorInfo(hOut, &CursorInfo);//获取控制台光标信息
//	CursorInfo.bVisible = false; //隐藏控制台光标
//	SetConsoleCursorInfo(hOut, &CursorInfo);//设置控制台光标状态
//
//	int x = 0;
//	int y = 0;
//	char c;
//	while (true)
//	{
//		c = _getch();
//		switch (c)
//		{
//		case (int)MOVE::UP: //上 
//		{
//			if (x > 1)
//			{
//				x--;
//			}
//			break;
//		}
//		case (int)MOVE::DOWN://下
//		{
//			if (x < 8)
//			{
//				x++;
//			}
//			break;
//		}
//		case (int)MOVE::LEFT://左
//		{
//			if (y > 1)
//			{
//				y--;
//			}
//			break;
//		}
//		case (int)MOVE::RIGHT://右
//		{
//			if (y < 8)
//			{
//				y++;
//			}
//			break;
//		}
//		}
//		for (int i = 0; i < 10; i++)
//		{
//			for (int j = 0; j < 10; j++)
//			{
//				if (i == 9 || i == 0 || j == 9 || j == 0 || (i == y && j == x))
//				{
//					pos.X = i * 2;
//					pos.Y = j;
//					SetConsoleCursorPosition(hOut, pos);
//					cout << "■";
//				}
//				else
//				{
//					pos.X = i * 2;
//					pos.Y = j;
//					SetConsoleCursorPosition(hOut, pos);
//					cout << "  ";
//				}
//			}
//			cout << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}
