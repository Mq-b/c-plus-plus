#include<Windows.h>
#include<iostream>

/*异步IO完成通知方法:																
* 触发设备内核对象:允许一个线程发出IO请求，另一个线程对结果进行处理
* 当向一个设备同时发出多个IO请求的时候，此方法无效
* 
* 触发事件内核对象:这种方法允许我们向一个设备同时发出多个IO请求
* 它允许一个线程发出IO请求，另一个线程对结果进行处理
* 
* 使用提醒IO:这种方法允许我们向一个设备发出多个IO请求
* 发出IO请求的线程必须对结果进行处理
* 
* 使用IO完成端口:这种方法允许我们向一个设备同时发出多个IO请求
* 它允许一个线程发出IO请求，另一个线程对结果进行处理。推荐使用，伸缩性和灵活性都很好
* IO完成接口的初衷就是与线程池配合使用
*/

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
	ol2.Offset = 2;
	OVERLAPPED ol1 = { 0 };
	ol1.hEvent = CreateEvent(NULL, true, false, NULL);
	ol2.hEvent = CreateEvent(NULL, true, false, NULL);
	BOOL ret2 = ReadFile(hFile2, buffer, 64, &readCount, &ol2);
	if (false == ret2) {
		DWORD err = GetLastError();
		if (ERROR_IO_PENDING == err) {
			HANDLE h[2]{};
			h[0] = ol1.hEvent;
			h[1] = ol2.hEvent;
			DWORD objnum = WaitForMultipleObjects(2, h, true, INFINITE);
			switch (objnum) 
			{
				case WAIT_OBJECT_0:
					break;
				case WAIT_OBJECT_0+1:
					break;
			}

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

	CloseHandle(ol1.hEvent);
	CloseHandle(ol2.hEvent);
	CloseHandle(hFile2);
}
int main() {
	write();	//异步写
	read();		//异步读
}