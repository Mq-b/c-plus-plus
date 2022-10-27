#include<windows.h>
#include<iostream>

int main() {
	HANDLE hFile = CreateFile("1.txt", GENERIC_WRITE, 0, 0, OPEN_ALWAYS, 0, 0);
	LARGE_INTEGER liMove;
	//设置移动文件指针的字节数
	liMove.QuadPart = 2;
	//移动指定文件的文件指针
	SetFilePointerEx(hFile, liMove, NULL, FILE_BEGIN);
	//将文件的物理文件大小设置为文件指针当前位置
	SetEndOfFile(hFile);
	CloseHandle(hFile);
}