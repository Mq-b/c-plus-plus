//#include<iostream>
//#include<iterator>
//#include<string>
//#include<array>
//#include<fstream>
//#include<vector>
//
//void test01()
//{
//	std::array<std::string, 5>name{ "1a","2a","3a","4a","5a" };
//	std::array<std::string, 5>temp;
//	//copy算法，三个参数，前两个表示容器范围，第三个表示拷贝到的容器的首地址，我们直接使用指针做迭代器参数，因为迭代器实际上是泛型的指针等，具体的话可以自行了解
//	std::copy(name.begin(), name.end(), temp.begin());
//	for (auto i : temp) {
//		std::cout << i << std::endl;
//	}
//
//	//然后我们操作普通数组来拷贝
//	int num1[5]{ 1,2,3,4,5 }, num2[5]{ 0 };
//	//把num1拷贝给num2
//	std::copy(num1, num1 + 6, num2);
//	for (auto i : num2) {
//		std::cout << i << std::endl;
//	}
//}
//void test02()
//{
//	//使用ostream_iterator模板创建cout_iter迭代器，初始化第一个参数是输入流对象，第二个是打印空格只是为了发送到输出流的时候分隔一下
//	std::ostream_iterator<std::string>cout_iter(std::cout);
//
//	std::array<std::string, 5>name{ "1a","2a","3a","4a","5a" };
//
//	//copy使用cout_iter接口让两个迭代器内的内容复制到输入流中，最终打印出来
//	std::copy(name.begin(), name.end(), cout_iter);
//
//	//当然也可以使用匿名容器	其实没什么不同，无非就是没写名字，把创建对象的步骤写在copy参数内
//	//std::copy(name.begin(), name.end(), std::ostream_iterator<std::string, char>(std::cout, " "));
//}
//void test03()
//{
//	std::array<std::string, 5>temp;
//	//使用istream_iterator模板创建迭代器	这里都使用匿名迭代器，两个参数表示输入流范围,需要Ctrl+z+Enter才能在Windows环境下表示EOF,达到流末尾退出，不然一直输入会越界
//	std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), temp.begin());
//	for (auto i : temp) {
//		std::cout << i << std::endl;
//	}
//}
//void test04()
//{
//	std::fstream fstr("笔记.md");
//	//和之前不同的是这里使用的是文件流对象，而不是标准输入流cout
//	std::ostream_iterator<std::string>cout_iter(fstr);
//
//	std::array<std::string, 5>name{ "1a","2a","3a","4a","5a" };
//
//	//拷贝到文件流中
//	std::copy(name.begin(), name.end(), cout_iter);
//	//创建储存读取数据的容器数组
//	std::array<std::string, 5>temp;
//
//	fstr.close();
//	//不清楚为啥，总之读取不了
//	std::ifstream ifs("文件.md");
//	//一样的，把之前使用的标准输入流对象cin换成了我们的读文件流对象
//	std::copy(std::istream_iterator<std::string>(ifs), std::istream_iterator<std::string>(), temp.begin());
//	//读到temp内遍历打印
//	for (auto i : temp) {
//		std::cout << i << std::endl;
//	}
//
//	ifs.close();
//}
//void test05()
//{
//	int num[5]{ 1,2,3,4,5 };
//	//初始化arr容器提前开辟存放5个元素的内存
//	std::vector<int>arr(5);
//
//	//先把数组的值拷贝到容器中
//	std::copy(num, num + 5, arr.begin());
//	//必须打印空格做分割，不然无法输出
//	std::ostream_iterator<int,char>cout_ar(std::cout," ");
//	std::cout << std::endl;
//	//倒序遍历
//	std::copy(arr.rbegin(), arr.rend(), cout_ar); 
//
//	//通过作用域解析运算符得出迭代器	特点是这个迭代器执行递增将会递减
//	std::vector<int>::reverse_iterator ri;
//	//和上一个倒序输出的方式不同，这里使用的是一个新的迭代器reverse_iterator，for循环遍历
//	for (ri = arr.rbegin(); ri != arr.rend(); ++ri) {
//		std::cout << *ri << " ";
//	}
//}
//int main()
//{
//	//基础的copy拷贝
//	//test01();
//
//	//拷贝到输出流
//	//test02();
//
//	//输入流数据拷贝到对象中
//	//test03();
//
//	//使用读写模式把array数组的数据拷贝到文件中
//	test04();
//
//	//copy拷贝到vector容器和倒序输出，另一个迭代器
//	//test05();
//	return 0;
//}
////总结:总共提到了iterator头文件下三种迭代器