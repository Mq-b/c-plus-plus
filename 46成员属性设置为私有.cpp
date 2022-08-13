//#include<iostream>
//#include<string>
//using namespace std;
//
////成员属性设置为私有
////1.可以设置自己控制读写权限
////2.对于写入可以检测数据的有效性
//
////设计人类
//class Person
//{
//public:
//	//设置姓名
//	void setname(string name)
//	{
//		m_name = name;
//	}
//	//获取姓名
//	string getname()
//	{
//		return m_name;
//	}
//	//获取年龄
//	
//	void go_age(int age)//写入年龄，设置条件
//	{
//		if (age < 150 && age>0)m_age = age;
//		else m_age = 0; puts("你输入的有误!!");
//	}
//    int getage()
//	{
//		return m_age;
//	}
//	void lovename(string name)
//	{
//		m_m_lover = name;
//	}
//	string getlover()
//	{
//		return m_m_lover;
//	}
//	//设置情人 只写
//
//private:
//	string m_name;//姓名	可读可写
//	int m_age;//年龄	只读
//	string m_m_lover;//情人	只写
//};
//int main()
//{
//	Person p;
//
//	p.setname("张三");
//	p.lovename("仓井");
//	p.go_age(-1);
//	cout << "情人为:" << p.getlover() << endl;
//	cout << "姓名为:" << p.getname() << endl;
//	cout << "年龄为:" << p.getage() << endl;
//	//总共公共权限内6个函数，每两个函数分别负责一个成员的读和写
//
//	//注意不用感到复杂，哪怕是私有的，我们只要写入两个函数，一个读一个写，
//    //也能在main函数随意更改或者输出，前提是类内的函数是公共权限，类外能访问就行。
//	return 0;
//}