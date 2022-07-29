//#include<iostream>
//#include<array>
//#include<string>
//
//template<class T,class B>
//class Person
//{
//public:
//	Person(T name, B age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//	void show()
//	{
//		std::cout << this->m_Age << " " << this->m_Name << std::endl;
//	}
//
//private:
//	T m_Name;
//	B m_Age;
//};
//void test01()
//{
//	//arr就是array<int,10>的别名
//	using arr = std::array<int, 10>;
//	arr num{0,1,2,3,4,5,6,7,8,9};
//	for (int i : num)std::cout << i << " ";
//	std::cout << typeid(num).name() << std::endl;
//
//	//这是c++提供的别名方式,也可以使用c风格的typedef
//	typedef std::array<int, 10>i;
//	std::cout << typeid(i).name() << std::endl;
//}
//
//void test02()
//{
//	//p就是这个模板的别名,已经写好了模板参数，所以可以直接把p当类型名使用即可
//	using p = Person<std::string,int>;
//	p person("离谱", 12);
//	person.show();
//}
//int main()
//{
//	//test01();
//	//使用模板using提供别名
//	test02();
//	return 0;
//}