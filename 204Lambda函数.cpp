////lambda 具体看c++ prime plus P662-665
//#include<iostream>
//#include<algorithm>
//void print(int a)
//{
//	std::cout << "hello " << a << std::endl;
//}
//void test01()
//{
//	int num[10]{ 1,2,3,4,5,6,7,8,9,10 };
//	//这里的第三个参数使用lamdba函数，也是匿名函数做参数
//	int a = std::count_if(num, num + 10, [](int a) {return a > 3; });
//	std::cout << a << std::endl;
//}
//void test02()
//{
//	int num[10]{ 1,2,3,4,5,6,7,8,9,10 };
//	//此时的v相当于这个匿名lambda函数的名字一样使用
//	auto v = [](int a) {return a > 3; };
//	int a = std::count_if(num, num + 10, v);
//	std::cout << a << std::endl;
//
//	//我们甚至可以像调用普通的函数一样调用它
//	bool temp = v(10);
//	std::cout << temp << std::endl;
//
//}
//int main()
//{
//	test01();
//	test02();
//}
////具体这样好处不再介绍。

//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//int main()
//{
//	int n = 1;
//	std::vector<double> V(10);
//	for (auto& i : V) {
//		i = n++;
//	}
//	std::for_each(V.begin(), V.end(), [=](int i) {std::cout << i << ","; });
//	return 0;
//}
