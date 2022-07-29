//#include<iostream>
//using namespace std;
//#include<fstream>//包含头文件
//class Person
//{
//public:
//	char m_Name[64];
//	int m_Age;
//};
//void test01()
//{
//	//写文件用ofstream定义流对象，读文件用ifstream定义流对象
//	ifstream ifs2;//和写入的定义不一样
//	ifs2.open("文件.txt", ios::in | ios::binary);
//	if (!ifs2.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return ;
//	}
//	Person p2;
//	ifs2.read((char*)&p2, sizeof(Person));
//	cout << "姓名=" << p2.m_Name << "年龄=" << p2.m_Age << endl;
//	ifs2.close();
//}
//
//int main()
//{
//	ofstream ofs("文件.txt", ios::out | ios::binary);//创建流对象的同时打开文件
//	Person p= { "张三", 18 };
//	ofs.write((const char*)&p, sizeof(Person));//二进制写入
//	ofs.close();
//	test01();//读取输出函数
//	return 0; 
//}