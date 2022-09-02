#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    fs::create_directory("sandbox");//创建一个新目录
    std::ofstream("sandbox/file1.txt").put('a');//创建一个文件然后写入一个a

    fs::copy_file("sandbox/file1.txt", "sandbox/file2.txt");//复制，如果第二个参数的文件不存在就会创建

    // 现在 sandbox 中有二个文件：
    std::cout << "file1.txt holds : "
        << std::ifstream("sandbox/file1.txt").rdbuf() << '\n';
    std::cout << "file2.txt holds : "
        << std::ifstream("sandbox/file2.txt").rdbuf() << '\n';

    // 复制目录失败(它只能用于复制普通文件内容)
    fs::create_directory("sandbox/abc");
    try {
        fs::copy_file("sandbox/abc", "sandbox/def");
    }
    catch (fs::filesystem_error& e) {//接住异常，这里是文件的标准异常
        std::cout << "Could not copy sandbox/abc: " << e.what() << '\n';
    }
    fs::remove_all("sandbox");//递归的移除一个目录的所有文件
}
//C++17的filesystem里面有很多很多好用的，随便尝试一下而已。