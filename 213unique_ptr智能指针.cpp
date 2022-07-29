#include<iostream>
#include<string>
#include<memory>//智能指针头文件
using namespace std;
int main()
{
	unique_ptr<int>up1(new int(11));//创建指针对象同时初始化
	cout << "up1=" << *up1 << endl;

	//unique_ptr<int>up2 = up1;//禁止拷贝构造，err

	//移动构造，把up1的使用权转移给up2，up1不能再操作堆区空间
	unique_ptr<int>up2 = std::move(up1);
	cout << "up2=" << *up2 << endl;

	//多次手动释放智能指针不会导致错误
	up2 = nullptr;
	up2 = NULL;
	up2.reset();

	//up2.reset();//如果是无参，作用是显式释放堆区内存
	//如果是有参，先使用原来的堆区内存，重新给up1绑定一个新的堆区内容
	up2.reset(new int(22));
	cout << "up2=" << *up2 << endl;

	//释放控制权不释放堆区内存
	int* p = up2.release();
	cout << "p=" << *p << endl;
	//需要手动释放
	delete p;
	return 0;
}
//移动构造后原来的智能指针不能再操控它的内存了，是野指针
//释放控制权后的智能指针不能再操控了，且需要手动释放