#include<Windows.h>
#include<iostream>

void write() {
	const char* str = "66666好啊好好";
	//注意倒数第二个参数，异步
	HANDLE hFile = CreateFile(L"1.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_FLAG_SEQUENTIAL_SCAN | FILE_FLAG_OVERLAPPED, NULL);
	DWORD count = 0;
	if (INVALID_HANDLE_VALUE == hFile) {
		fputs("CreateFile failed!", stderr);
		exit(1);
	}

	OVERLAPPED ol1 = { 0 };
	//注意最后一个参数
	BOOL ret = WriteFile(hFile, str, strlen(str), &count, &ol1);
	//写是异步，那么返回值必然false，这里的判断也就没有意义了，改写
	if (false == ret) {
		DWORD err = GetLastError();
		if (ERROR_IO_PENDING == err) {
			printf("正在异步操作\n");
			WaitForSingleObject(hFile, INFINITE);//等待
			printf("异步写入完毕\n");
		}
		else {
			fputs("读取错误", stderr);
			exit(1);
		}
	}

	//此时写操作在另外一个线程做，而不是在当前线程做，在这里刷新就不合时宜
	//FlushFileBuffers(hFile);
	CloseHandle(hFile);
}
void read() {
	HANDLE hFile2 = CreateFile(L"1.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN | FILE_FLAG_OVERLAPPED, NULL);
	char buffer[64]{};
	DWORD readCount = 0;

	OVERLAPPED ol2 = { 0 };
	BOOL ret2 = ReadFile(hFile2, buffer, 64, &readCount, &ol2);
	if (false == ret2) {
		DWORD err = GetLastError();
		if (ERROR_IO_PENDING == err) {
			printf("正在异步操作\n");
			WaitForSingleObject(hFile2, INFINITE);//等待
			printf("异步读完毕\n");
			printf("%s\n", buffer);
		}
		else {
			fputs("读取错误", stderr);
			exit(1);
		}
	}

	CloseHandle(hFile2);
}
int main() {
	write();	//异步写
	read();		//异步读
	
}