//#include<iostream>
//#include<string>
//using namespace std;
//
////分别用普通写法和多态计数实现计算器
//
////普通写法
//class Calculator
//{
//public:
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return m_Name1 + m_Name2;
//		}
//		else if (oper == "-")
//		{
//			return m_Name1-m_Name2;
//		}
//		else if (oper == "*")
//		{
//			return m_Name1 * m_Name2;
//		}
//		//如果想扩展新的功能，需要修改源码
//		//在真实开发中	提倡	开闭原则
//		//开闭原则：对扩展进行开发，对修改进行关闭
//	}
//	int m_Name1;
//	int m_Name2;
//};
//
//void test01()
//{
//	//创建计算器对象
//	Calculator c;
//	c.m_Name1 = 10;
//	c.m_Name2 = 10;
//	cout << c.m_Name1 << "+" << c.m_Name2 << "=" << c.getResult("+") << endl;
//}
////利用多态实现计算器
////多态的好处:
//// 1、组织结构清晰
//// 2、可读性强
//// 
////实现计算器抽象类
//class AbstractCalculator
//{
//
//public:
//	virtual int getResult()//想写多态，父类中得有一个虚函数，子类再去重写它
//	{
//		return 0;
//	}
//	int m_Num1;
//	int m_Num2;
//};
//
////加法计算器类
//class AddCalculate : public AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//
////减法计算器类
//class NulCalculate : public AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
////乘法计算器类
//class SulCalculate : public AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//
//void test02()
//{
//	//多态使用条件
//	//父类指针或者引用指向子类对象
//
//	//加法运算
//	AbstractCalculator* abc = new AddCalculate;//堆区,创建一个父类的指针，指向开辟的其中一个子类的地址
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	delete abc;//销毁
//
//	//减法运算
//	abc = new NulCalculate;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	delete abc;
//
//	//乘法运算
//	abc = new SulCalculate;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	delete abc;
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}