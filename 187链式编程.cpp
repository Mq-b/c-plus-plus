//#include<iostream>
//#include<string>
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
//
//	int m_Age;
//	std::string m_Name;
//};
//void test01()
//{
//	Person v1{ 12,"哈哈" };
//	Person v2;
//	Person v3;
//	Person v4;
//	Person v5;
//	//这就是链式编程
//	v1.copy(v2).copy(v3).copy(v4).copy(v5);
//	v5.print();
//
//	//可以修改，因为返回的对象虽然都是const，但是与传入的参数无关，我们通过返回的对象进行链式编程。
//	v5.m_Age = 20;
//	v5.print();
//}
//int main()
//{
//	test01();
//	return 0;
//}

//友元和重载
//#include<iostream>
//#include<fstream>
////阶乘
//long double factorial(size_t num)
//{
//	if (num == 1 || num == 0)return 1;
//	return num * factorial(num - 1);
//}
//
//class Person
//{
//	//使用友元让函数能直接访问类内私有权限
//	friend int operator*(int i, Person& v);
//	friend std::ostream& operator<<(std::ostream& cout, Person& V);
//
//public:
//
//	Person(int age)
//	{
//		this->m_Age = age;
//	}
//
//	void print()
//	{
//		std::cout << this->m_Age << std::endl;
//	}
//private:
//	int m_Age;
//};
//
////使用全局函数重载可以让自定义数据类型在右边，且作用于全局而非类
//int operator*(int i, Person& v)
//{
//	return i * v.m_Age;
//}
//
////返回输出流对象的引用就能链式编程
//std::ostream& operator<<(std::ostream& cout, Person& V)
//{
//	cout << V.m_Age << " ";
//	return cout;
//}
//
//void test01()
//{
//	Person v(12);
//	std::cout << 5 * v << std::endl;
//}
//
//void test02()
//{
//	Person v(16);
//	//重载了左移运算符
//	std::cout << v << std::endl;
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}

