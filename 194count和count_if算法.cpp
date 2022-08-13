//#include<iostream>
//#include<algorithm>
//#include<array>
//
//bool show(int a)
//{
//	return a > 5;
//}
//
//void test01()
//{
//	std::array<std::string, 3>str{ "哈哈", "嗯嗯", "哈哈" };
//	//count按照值查找，找到就返回值相同的数量
//	int num = std::count(str.begin(), str.end(), "哈哈");
//	std::cout << num << std::endl;
//}
//void test02()
//{
//	int num[5]{ 1,2,2,2,3 };
//	int i = std::count(num, num + 5, 2);
//	std::cout << i << std::endl;
//}
//
//void test04()
//{
//	int num[10]{ 1,2,3,4,5,6,7,8,9,10 };
//	//第三个参数可以是谓词也可以是普通函数，最终返回大于5的数的数量
//
//	//也可以对自定义数据类型进行操作，但是需要重载比较运算符，这里就不写出来了
//	int a = std::count_if(num, num + 10, show);
//	std::cout << a << std::endl;
//}
//int main()
//{
//	//对string对象
//	test01();
//	//对普通数组
//	test02();
//
//	//count_if
//	test04();
//}