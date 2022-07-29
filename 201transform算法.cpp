//#include<iostream>
//#include<vector>
//#include<iterator>
//#include<algorithm>
//#include<cmath>
//#include<functional>
//
//auto print(double a)
//{
//	return sqrt(a);
//}
//auto aver(double a, double b)
//{
//	return (a + b) / 2;
//}
//auto sum(double a, double b)
//{
//	return a + b;
//}
//
//void test01()
//{
//	double num[5]{ 25,16,9,8,4 };
//	std::vector<double>v(num, num + 5);
//	std::ostream_iterator<int, char>co(std::cout, " ");
//	//搬运算法，不过我们搬运到输出迭代器，也就是输出流输出，同时函数返回sqrt的值输出
//	std::transform(v.begin(), v.end(), co, print);
//}
//void test02()
//{
//	double num[5]{ 25,16,9,8,4 };
//	double num2[5]{ 29,17,3,8,4 };
//	std::vector<double>v(num, num + 5);
//	std::vector<double>v2(num2, num2 + 5);
//	std::ostream_iterator<int, char>co(std::cout, " ");
//
//	//这五个参数，前两个参数是第一个容器的范围，第三个参数是第二个容器的起始，第四个是搬运到的地方，第五个是仿函数或者普通函数都行
//	//计算的两个数的平均值然后搬运到输出流输出
//	std::transform(v.begin(), v.end(), v2.begin(), co, aver);
//	std::cout << std::endl;
//
//	//通过遍历我们可以看出，第二个容器并没有被改变，第四个参数才决定搬运到哪
//	for (auto i : v2) {
//		std::cout << i << " ";
//	}
//}
//void test03()
//{
//	double num[5]{ 25,16,9,8,4 };
//	double num2[5]{ 29,17,3,8,4 };
//	std::vector<double>v(num, num + 5);
//	std::vector<double>v2(num2, num2 + 5);
//	std::ostream_iterator<int, char>co(std::cout, " ");
//
//	//和test02一样，只是最后一个函数的参数不一样
//	std::transform(v.begin(), v.end(), v2.begin(), co, sum);
//	std::cout << std::endl;
//}
//void test04()
//{
//	double num[5]{ 25,16,9,8,4 };
//	double num2[5]{ 29,17,3,8,4 };
//	std::vector<double>v(num, num + 5);
//	std::vector<double>v2(num2, num2 + 5);
//	std::vector<double>v3(5);
//
//	//和test03一样，只是第四个函数的参数不一样，两个容器和搬运到第三个，而不是搬运到输出流
//	std::transform(v.begin(), v.end(), v2.begin(), v3.begin(), sum);
//	//我们遍历测试一下容器，没有问题
//	for (auto i : v3) {
//		std::cout << i << " ";
//	}
//}
//void test05()
//{
//	int num[5]{ 1,2,3,4,5 };
//	int num1[5]{ 10,10,10,10,10 };
//
//	std::vector<int>v(num, num + 5);
//	std::ostream_iterator<int, char>co(std::cout, " ");
//	//最后一个参数由functional头文件提供原型，也就是内建函数对象，或者叫预定义函数符
//
//	//前面两个参数表示容器范围，第三个表示相乘的数，我们得使用数组或者容器地址都行，搬运到co也就是输出流，最后一个参数提供相乘算法
//	std::transform(v.begin(), v.end(),num1, co, (std::multiplies<int>()));
//
//}
//int main()
//{
//	//一个容器搬运打印
//	//test01();
//
//	//两个容器平均值搬运打印
//	//test02();
//
//	//两个容器和打印搬运
//	//test03();
//
//	//两个容器和搬运另一个容器
//	//test04();
//
//	//将容器的数据乘2.5倍然后搬运到输出流输出
//	//test05();
//	return 0;
//}