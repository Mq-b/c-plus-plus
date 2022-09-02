#include<iostream>
#include<string>
#include<memory>
using namespace std;
int main()
{
	shared_ptr<int>sp1(new int(11));
	shared_ptr<int>sp2(sp1);//和unique_ptr不同，允许拷贝构造,有两个对象和堆区绑定

	cout << "num=" << sp2.use_count() << endl;//打印计数器，也就是有多少个对象和堆区绑定了

	//释放这个智能指针和堆区的绑定，没有释放堆区内存，无法通过sp1操作堆区内存
	sp1.reset();
	cout << "num=" << sp2.use_count() << endl;

	//释放sq2，当计数器的值为0，堆区空间就会释放
	sp2.reset();
	cout << "num=" << sp2.use_count() << endl;
	return 0;
}
