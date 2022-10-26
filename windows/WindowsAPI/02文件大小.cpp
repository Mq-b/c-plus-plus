#include<Windows.h>
#include<iostream>

int main() {
	HANDLE hFile = CreateFile(L"1.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, NULL, NULL);
	DWORD count = 0;
	if (INVALID_HANDLE_VALUE == hFile) {
		fputs("CreateFile failed!", stderr);
		exit(1);
	}
	
	ULARGE_INTEGER ulFileSize;
	ulFileSize.LowPart = GetFileSize(hFile, &ulFileSize.HighPart);
	printf("%I64u\n", ulFileSize.QuadPart);

	LARGE_INTEGER lFileSize;
	BOOL ret = GetFileSizeEx(hFile, &lFileSize);
	if (ret) {
		printf("%I64u\n", lFileSize.QuadPart);
	}

	CloseHandle(hFile);
}