//#include<iostream>
//#include<string>
//const int MAX = 5;
//
//enum class AV :int
//{
//	A=1,B,C,D
//};
//
//class Person
//{
//public:
//	Person() = default;
//
//	Person(int age, std::string name)
//	{
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//
//	const Person& copy(Person& v)const
//	{
//		v.m_Age = this->m_Age;
//		v.m_Name = this->m_Name;
//		return *this;
//	}
//
//	void print()
//	{
//		std::cout << this->m_Age << " " << this->m_Name << std::endl;
//	}
//
//private:
//	int m_Age;
//	std::string m_Name;
//};
//
//void test01()
//{
//	//创建对象数组并且初始化
//	Person V[MAX]
//	{
//		Person(0,"啊"),
//		Person(1,"行吧"),
//		Person(2,"好的呢"),
//		Person(3,"随你随你"),
//		Person(4,"哦哦哦哦哦")
//	};
//	
//	//使用c++11的方式遍历对象数组
//	for (Person v : V)
//	{
//		v.print();
//	}
//}
//
//void test02()
//{
//	Person v{ 12,"哈哈" };
//	
//	Person V[MAX];
//
//	//使用对象的成员函数拷贝给对象数组的元素赋值
//	v.copy(V[0]);
//	//输出对象数组元素
//	V[0].print();
//}
//
//void test03()
//{
//	//得强转数据类型，作用域内枚举不能隐式的转换为整形
//	std::cout << static_cast<int>(AV::A) << std::endl;
//}
//
//int main()
//{
//	//test01();
//	//test02();
//	//限定作用域枚举
//	test03();
//	return 0;
//}