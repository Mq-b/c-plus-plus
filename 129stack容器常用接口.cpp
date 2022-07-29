//#include<iostream>
//using namespace std;
//#include<stack>
//
////栈stack容器不能遍历
//
//void test01()
//{
//	//特点:先进后出数据结构
//	stack<int>s;
//
//	//入栈
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.push(40);
//	//初始大小
//	cout << "栈的大小:" << s.size() << endl;
//
//	//只要栈不为空我们就查看栈顶，并且执行出栈操作
//	while (!s.empty())//空就为真，所以取反，空就停止
//	{
//		//查看栈顶元素
//		cout << "栈顶元素为:" << s.top() << endl;
//		//结果 40 30 20 10
//		//出栈
//		s.pop();
//	}
//
//	cout << "栈的大小:" << s.size() << endl;//结果是0,因为上面的循环让数据全部出栈了，大小就为0
//}
//
//int main()
//{
//	test01();
//	return 0;
//}
////入栈--push
////出栈--pop
////返回栈顶--top
////判断栈是否为空--empty
////返回栈大小--size