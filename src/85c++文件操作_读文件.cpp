//#include<iostream>
//using namespace std;
//#include<fstream>//头文件包含
//#include<string>
////文本文件 读文件
//
//void test01()
//{
//	//1、包含头文件
//
//	//2、创建流对象
//	ifstream ifs;
//	//3、打开文件，判断是否打开成功
//	ifs.open("文件.txt",ios::in);
//	if (ifs.is_open()==NULL)
//	{
//		cout << "文件打开失败" << endl;
//		return ;
//	}
//	//4、读数据
//
//	//第一种
//	char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		cout << buf << endl;
//	}
//	//第二种
//	char buf2[1024] = { 0 };
//	while (ifs.getline(buf2, sizeof(buf2)))
//	{
//		cout << buf2 << endl;
//	}
//	//第三种
//	string buf3;
//	while (getline(ifs, buf3))
//	{
//		cout << buf3 << endl;
//	}
//	//第四种
//	char c;
//	while ((c = ifs.get()) != EOF)//不推荐
//	{
//		cout << c;
//	}
//
//	ifs.close();
//}
//int main()
//{
//	test01();
//	return 0;
//}