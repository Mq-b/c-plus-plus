#include<iostream>
#include<string>
#include<functional>
using namespace std;

//普通函数
void func()
{
	cout << __func__ << endl;
}

//2、类中静态函数
class Test
{
public:
	static int test_func(int a)
	{
		cout << __func__ << "(" << a << ")->:";
		return a;
	}
};
//3、类中的仿函数
class MyFunctor
{
public:
	int operator()(int a)
	{
		cout << __func__ << "(" << a << ")->:";
		return a;
	}
};
int main()
{
	//1、绑定普通函数
	function<void()>f1 = func;//相当于函数指针
	f1();
	//2、绑定类中静态函数	要写作用域
	function<int(int)>f2 = Test::test_func;
	cout << f2(10) << endl;//Test::test_func(10);
	//3、绑定类中的仿函数，绑定对象		我们绑定匿名对象
	function<int(int)>f3 = MyFunctor();
	cout << f3(20) << endl;
	return 0;
}
