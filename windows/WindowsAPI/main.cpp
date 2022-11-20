
#include <iostream>
#include <assert.h>
#include <Windows.h>
#include <WinBase.h>

#define BAD_POS 0xFFFFFFFF // returned by SetFilePointer and GetFileSize
#define SUCCESS 0
using namespace std;

typedef DWORD mmf_share_mode;
typedef DWORD mmf_access_mode;
typedef DWORD mmf_flags;


int main() {
    cout << "create memorymapfile..." << endl;
    const char* shared_name = "testMmf";
    const char* file_name = "d:\\testMmf.mmf";
    const DWORD mmf_size = 512 * 1024;
    //存取模式
    mmf_access_mode access_mode = (GENERIC_READ | GENERIC_WRITE);
    //共享模式
    mmf_share_mode share_mode = FILE_SHARE_READ | FILE_SHARE_WRITE;
    //文件属性
    mmf_flags flags = FILE_FLAG_SEQUENTIAL_SCAN;//|FILE_FLAG_WRITE_THROUGH|FILE_FLAG_NO_BUFFERING;
    DWORD error_code;

    //创建文件
    HANDLE mmHandle =
        CreateFile(file_name,
            access_mode,
            share_mode,
            NULL,
            PAGE_READWRITE,
            flags,
            NULL);

    if (mmHandle == INVALID_HANDLE_VALUE) {
        error_code = GetLastError();
        cout << "创建mmf失败:" << error_code << endl;
    }
    else {
        DWORD high_size;
        DWORD file_size = GetFileSize(mmHandle, &high_size);
        if (file_size == BAD_POS && (error_code = GetLastError()) != SUCCESS) {
            CloseHandle(mmHandle);
            cout << "error：" << error_code << endl;
        }
        cout << "create mmf sucessfully" << endl;

        DWORD size_high = 0;
        //创建文件映射，如果要创建内存页面文件的映射，第一个参数设置为INVALID_HANDLE_VALUE
        HANDLE mmfm = CreateFileMapping(mmHandle,
            NULL,
            PAGE_READWRITE,
            size_high,
            mmf_size,
            shared_name);

        error_code = GetLastError();
        if (SUCCESS != error_code) {
            cout << "createFileMapping error" << error_code << endl;
        }
        else {
            if (mmfm == NULL) {
                if (mmHandle != INVALID_HANDLE_VALUE) {
                    CloseHandle(mmHandle);
                }
            }
            else {
                size_t view_size = 1024 * 256;
                DWORD view_access = FILE_MAP_ALL_ACCESS;

                //获得映射视图
                char* mmfm_base_address = (char*)MapViewOfFile(mmfm, view_access, 0, 0, view_size);
                if (mmfm_base_address == NULL) {
                    error_code = GetLastError();
                    if (error_code != SUCCESS) {
                        cout << "error code " << error_code << endl;
                    }
                }
                else {
                    char write_chars[] = "hello chars";
                    const size_t write_chars_size = sizeof(write_chars);
                    //向内存映射视图中写数据
                    CopyMemory((PVOID)mmfm_base_address, write_chars, write_chars_size);

                    //memcpy(mmfm_base_address,write_chars,write_chars_size);

                    size_t position = 0;
                    char read_chars[write_chars_size];

                    //读数据
                    memcpy(read_chars, mmfm_base_address, write_chars_size);
                    cout << "read chars " << read_chars << endl;

                    //卸载映射
                    UnmapViewOfFile(mmfm_base_address);
                    //关闭内存映射文件
                    CloseHandle(mmfm);
                    //关闭文件
                    CloseHandle(mmHandle);
                }
            }
        }
    }
    return EXIT_SUCCESS;
}