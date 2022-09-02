//#include<iostream>
//void test01()
//{
//	//更改默认填充字符，从空格变成*，如果不更改回来一直都是这样
//	std::cout.fill('*');
//	//填充字符 只影响项目下第一句话，意思就是说打印10个*这么简单，默认是空格，其实就是调整格式的
//	std::cout.width(10);
//	std::cout << 2 << std::endl;
//	std::cout << 3 << std::endl;
//}
//void test02()
//{
//	//我们可以看出默认是保留六位
//	std::cout << 1 / 3.0 << std::endl;
//
//	//使用precision()也就是cout的成员函数设置保留小数位，这个和fill一样，如果不该回来，在整个项目一直都是
//	//顺便说一句在32位的环境下double只会保证小数点后16位的精度
//	std::cout.precision(2);//设置保留两位小数
//	std::cout << 1 / 3.0 << std::endl;
//
//}
//void test03()
//{
//	//我们知道，对于浮点数，小数点后的0是不会显示的，iostream也没有专门完成这项任务的，我们使用ios_base类的setf()函数,具体查看c++ prime plus P605
//	std::cout.setf(std::ios_base::showpoint);
//
//	std::cout.precision(3);//设置保留两位小数，这里的两位实际上是包含了小数点前，所以如果想打印出5.20我们得设置为三位
//	std::cout << 5.2 << std::endl;
//}
//int main()
//{
//	//填充字符
//	//test01();
//
//	//设置浮点数保留小数位
//	//test02();
//
//	//通过输出我们可以看出和作用域无关，设置的是cout输出流对象 
//	//std::cout << 1 / 3.0 << std::endl;
//
//	//打印末尾的0和小数点
//	test03();
//	return 0;
//}
////顺便说一句std::cout的三个控制字符dec,hex,oct分别对应10,16,8进制
////c++ prime plus P606，到610面很值得看，提供了大量的格式常量和标准控制符，类似test03的使用方式

//这是cin的格式，详情看c++ prime plus 617到622
//#include<iostream>
//#include<string>
//void test01()
//{
//	int temp;
//	//设置输入16进制
//	std::cin >> std::hex >> temp;
//	//默认是输出10进制
//	std::cout << temp;
//}
//void test02()
//{
//	int temp, sum = 0;
//	while (std::cin >> temp) {
//		sum += temp;
//	}
//	std::cout << sum << std::endl;
//}
//void test03()
//{
//	char ch[6]{ 0 };
//
//	//read函数不会自己添加空字符，所以得留一位做空字符才能以字符串的形式输出
//	std::cin.read(ch, 5);
//	std::cout << ch << std::endl;
//}
//int main()
//{
//	//test01();
//	//test02();
//	test03();
//}