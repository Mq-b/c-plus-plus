////题目:用宏定义得到一个字的高位和低位字节
//#define WORD_LOW(a) (( a & 255))
//#define WORD_HIGH(a) (a>>8)
//
////一个字由两个字节组成，因此WORD_LOW取参数xxx的低8位，WORD_HIGH取参数的高8位
//
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 62597;   //1111 0100 1000 0101
//
//	cout << WORD_LOW(a) << endl;
//	cout << WORD_HIGH(a) << endl;
//}