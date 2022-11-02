#include<Windows.h>
#include<iostream>
#include<string>
#include <fcntl.h>
#include <io.h>

int main(int argc, char* argv[]){
    if (OpenClipboard(nullptr))//打开剪贴板
    {
        const WCHAR content[] = L"逆天";

        if (EmptyClipboard())//清空剪贴板
        {
            auto hMemory = GlobalAlloc(GMEM_MOVEABLE, sizeof(content));//对剪贴板分配内存

            auto lpMemory = (LPTSTR)GlobalLock(hMemory);//将内容区域锁定

            CopyMemory(lpMemory, content, sizeof(content));//复制数据到内存区域

            GlobalUnlock(hMemory);                         //解除内存锁定
            SetClipboardData(CF_UNICODETEXT, hMemory);
            CloseClipboard();
        }
    }
}