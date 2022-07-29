//#include<iostream>
//using namespace std;
//#include<fstream>//头文件包含
////文本文件 写文件
//
//int main()
//{
//	//1、包含头文件
//	//2、创建流对象
//	ofstream ofs;
//
//	//3、指定打开方式
//	ofs.open("文件.txt", ios::out);
//	//4、写内容
//	ofs<< "姓名:张三" << endl;
//	ofs<< "性别:男" << endl;
//	ofs<< "年龄:18" << endl;
//	//5、关闭文件
//	ofs.close();
//	return 0;
//}
//边读边写
//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<string>
//int main()
//{
//	ifstream ifs;
//	ifs.open("文件.txt", ios::in);
//	if (ifs.is_open() == NULL)
//	{
//		cout << "打开失败" << endl;
//		return 0;
//	}
//	ofstream ofs;
//	ofs.open("文件2.txt", ios::out);
//	char ch[1024] = { 0 };
//	while (ifs >> ch)//边读取数据边写入数据
//	{
//		cout << ch << endl;
//		ofs << ch << endl;
//	}
//
//	ifs.close();//关闭读取文件
//	ofs.close();//关闭写入文件
//	return 0;
//}
