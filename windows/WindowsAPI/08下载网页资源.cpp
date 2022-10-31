#include<windows.h>
#include<tchar.h>
#pragma comment(lib, "Urlmon.lib")
int main() {
	//MessageBox(NULL, _T("this is first winapp"), _T("this is title"), MB_OK);
	HRESULT hresult = URLDownloadToFile(NULL, _T("https://pic3.zhimg.com/v2-6b78f654de9c1d3b3fe9eddac0fe7f7e_b.jpg"),
		_T("D:\\刻晴.jpg"), 0, NULL);//存放目录的和名称
	if (hresult == S_OK) {
		MessageBox(NULL, _T("下载成功"), _T("this is title"), MB_OK);
	}
	else {
		MessageBox(NULL, _T("下载失败"), _T("this is title"), MB_OK);
	}
}