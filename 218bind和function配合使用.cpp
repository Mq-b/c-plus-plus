#include<iostream>
#include<string>
#include<functional>//头文件提供原型
using namespace std;
using namespace std::placeholders;//引入命名空间减少代码量
class Test
{
public:
	void func(int x, int y)
	{
		cout << x << " " << y << endl;
	}
	int a;
};
int main()
{
	Test obj;

	//绑定成员函数
	function<void(int, int)>f1 = bind(&Test::func, &obj, _1, _2);
	f1(11, 22);

	function<int&()>f2 = bind(&Test::a, &obj);
	f2() = 111;//obj.a=111;
	cout << obj.a << endl;
	return 0;
}
