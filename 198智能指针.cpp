//#include<iostream>
//#include<memory>
//#include<algorithm>
//class Person
//{
//public:
//	Person(int age, std::string name)
//	{
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//	//提供无参构造是为了new能够有构造函数调用，如果只有有参构造就会出问题
//	Person()
//	{
//		this->m_Age = 0;
//		this->m_Name = "";
//	}
//
//	void showPerson()
//	{
//		std::cout << "名字:" << this->m_Name << " 年龄:" << this->m_Age << std::endl;
//	}
//	void ave(int age, std::string name)
//	{
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//private:
//	int m_Age;
//	std::string m_Name;
//};
//void ram(const std::string& str)
//{
//	//调用智能指针创建对象，智能指针是一个类，第一个参数是创建的
//	//指针类型，然后对象的括号是new动态内存，在括号内用str初始化指针
//
//	//unique是特殊的意思，ptr是指针单词的缩写，下划线连接意思是特殊的指针
//	std::unique_ptr<std::string>ps(new std::string(str));
//	std::cout << *ps << std::endl;
//	//动态内存自动回收，不需要手动delete，离开代码块的时候指针过期，自动析构
//}
//void test01()
//{
//	//传递一个string的匿名对象过去
//	ram(std::string("傻子"));
//}
//void test02()
//{
//	//使用智能指针对自定义数据类型，申请10个对象的大小
//	//注意类型得写成Person[]，这样释放的时候才是delete[]与new[]对应
//	std::unique_ptr<Person[]>ps(new Person[5]);
//	for (int i = 0; i < 5; i++) {
//		ps[i].ave(i, "傻子");//赋值
//	}
//	for (int i = 0; i < 5; i++) {
//		ps[i].showPerson();//遍历显示
//	}
//}
//int main() {
//	//test01();
//	test02();
//}