//#include<iostream>
//class Outside
//{
//public:
//	Outside()
//	{
//		std::cout << "外部的无参构造" << std::endl;
//	}
//	~Outside()
//	{
//		std::cout << "外部的析构函数" << std::endl;
//	}
//	Outside(int num)
//	{
//		this->m_Num = num;
//		std::cout << "外部的有参构造" << std::endl;
//	}
//	int m_Num;
//public:
//	class Nested
//	{
//	public:
//		Nested()
//		{
//			std::cout << "嵌套的无参构造" << std::endl;
//		}
//		~Nested()
//		{
//			std::cout << "嵌套的析构函数" << std::endl;
//		}
//		Nested(int num)
//		{
//			this->z_Num = num;
//			std::cout << "嵌套的有参构造" << std::endl;
//		}
//		int z_Num;
//	};
//	//我们也可以直接在嵌套类所在的类内创建嵌套类对象
//	//Nested num;
//};
//void test01()
//{
//	Outside v(10);
//	std::cout << sizeof v << std::endl;
//	//创建嵌套类对象,得使用作用域解析运算符，先声明在哪个类才能创建
//	//嵌套类只是语义上的嵌套，并不包含
//	//因为是嵌套类是公工权限，所以可以在外部访问创建
//	Outside::Nested num;
//	std::cout << sizeof num << std::endl;
//}
//int main() {
//	test01();
//}
