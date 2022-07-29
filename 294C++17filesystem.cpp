#include <iostream>
#include <filesystem>
//所有的方法都被放入std::filesystem::命名空间，但是引入filesystem头文件，命名空间也被引入

int main(int argc, char* argv[])
{
	std::filesystem::path p{ "D:/自用/vs的c++/c++2022_1_19/c++2022_1_19.vcxproj.filters" };   // p代表一个文件系统路径（可能不存在）
	if (is_regular_file(p)) { //如果p是文件
		std::cout << p << " size is " << file_size(p) << " bytes\n";//file_size方法打印文件大小，单位byte
	}
	else if (is_directory(p)) {//如果p是目录
		for (const auto& e : std::filesystem::directory_iterator{ p }) {//directory_iterator方法会获取当前目录所有文件
			std::cout << "  " << e.path() << '\n';//全部打印
		}
	}
	else if (exists(p)) {//判断p是否存在
		std::cout << p << " 是一个特殊文件\n";
	}
	else {
		std::cout << "path " << p << " 不存在\n";
	}
}