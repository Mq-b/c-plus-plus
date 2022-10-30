#include<iostream>
#include<Windows.h>

using Addl = int(*)(int, int);

int main() {
	WCHAR path[255]{};
	HMODULE hModule = GetModuleHandle(L"WindowsAPI.dll");
	DWORD len = 0;
	if (NULL == hModule) {		// //若源程序没载入user32.dll则LoadLibrary它
		hModule = LoadLibrary(L"WindowsAPI.dll");
		printf("源程序未载入dll\n");
		if (NULL == hModule) {
			printf("导入错误\n");
			exit(1);
		}
	}
	len = GetModuleFileName(hModule, path, 255);
	printf("%ws ", path);
	Addl addl = (Addl)GetProcAddress(hModule,"?add@@YAHHH@Z");
	printf("%d\n", addl(10, 10));
}
//GetModuleHandle是对已经在内存中的进程操作，LoadLibrary是可能不在内存中要新建进程
//所以我们这里写个GetModuleHandle也只是写着看而已，一般可以全部使用LoadLibrary