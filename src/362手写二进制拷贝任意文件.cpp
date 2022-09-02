#include<iostream>
#include<fstream>
int main() {
	std::ifstream ifs{ "D:\\汇编语言 第四版.pdf", std::ios::binary | std::ios::in };
	std::ofstream ofs{ "D:\\汇编.pdf",std::ios::binary | std::ios::out };
	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cerr << "文件打开失败" << std::endl;
		throw std::runtime_error("文件打开失败");
	}
	char* buffer = new char[1024];
	std::streamsize len = 1024;
	while(!ifs.eof()) {
		len = ifs.read(buffer, 1024).gcount();//gcount返回最近的无格式输入操作所提取的字符数，这很重要，能防止多写多度
		ofs.write(buffer, len);
	}

	ifs.close();
	ofs.close();
}
/*它可以用来复制PDF，mps，mp4等二进制文件*/