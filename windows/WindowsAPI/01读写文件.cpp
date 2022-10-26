#include<Windows.h>
#include<iostream>

int main() {
	const char* str = "66666好啊好好";
	HANDLE hFile = CreateFile(L"1.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, NULL, NULL);
	DWORD count = 0;
	if (INVALID_HANDLE_VALUE == hFile) {
		fputs("CreateFile failed!", stderr);
		exit(1);
	}
	BOOL ret = WriteFile(hFile, str , strlen(str), &count, NULL);
	if (false == ret) {
		exit(1);
	}

	printf("%d\n", count);

	//刷新指定缓冲区
	FlushFileBuffers(hFile);
	CloseHandle(hFile);

	HANDLE hFile2 = CreateFile(L"1.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, NULL, NULL);
	char buffer[64]{};
	DWORD readCount = 0;
	BOOL ret2 = ReadFile(hFile2, buffer, 64, &readCount, NULL);
	if (false == ret2) {
		exit(1);
	}
	
	CloseHandle(hFile2);
	printf("%s\n", buffer);

}