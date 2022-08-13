//#include<iostream>
//using namespace std;
//#include<string>
//void test01()
//{
//	//string 的本质是一个类
//	string s1;//默认构造
//	const char* str = "hello word";
//	string s2(str);//把c语言风格的字符串赋值给s2
//	cout << "s2=" << s2 << endl;
//
//	string s3(s2);//s2赋值给s3
//	cout << "s3=" << s3 << endl;
//
//	s3=s2;//s2赋值给s3，重载=了
//	cout << "s3=" << s3 << endl;
//
//	string s4(10, 'a');//10个a赋值给自身字符串
//	cout << "s4=" << s4 << endl;
//
//	string s5;
//	s5.assign("helloword", 5);//表示把第一个参数字符串的5个字符赋值给当前的字符串，也就是s5
//	cout << s5 << endl;
//
//	string s6;
//	s6.assign(s5);//把s5赋值给s6
//	cout << s6 << endl;
//
//	string s7;//和s4一个意思
//	s7.assign(10, 'w');
//	cout << "s7=" << s7 << endl;
//
//}
//int main()
//{
//	test01();
//	return 0;
//} 