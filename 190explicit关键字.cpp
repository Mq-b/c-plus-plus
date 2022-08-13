//#include <iostream>
//using namespace std;
//class Test1
//{
//public:
//	Test1(int num) :n(num) {}
//	void showTest02()
//	{
//		cout << this->n << endl;
//	}
//private:
//	int n;
//};
//class Test2
//{
//public:
//	explicit Test2(int num) :n(num) {}
//	void showTest02()
//	{
//		cout << this->n << endl;
//	}
//private:
//	int n;
//};
//
//int main()
//{
//	Test1 t1 = 12;
//	Test2 t2(13);
//	Test2 t3(1);
//	t1.showTest02();
//	t2.showTest02();
//	t3.showTest02();
//	return 0;
//}
////注意：当类的声明和定义分别在两个文件中时，explicit只能写在在声明中，不能写在定义中。
///*explicit修饰的构造函数不能被隐式调用
//禁止类对象之间的隐式转换*/
