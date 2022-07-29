#include<iostream>
#include<vector>

class Test {
public:
	void* operator new(size_t size)
	{
		std::cout << "重载operator new" << std::endl;
		return malloc(size);
	}
	void operator delete(void* _Block)
	{
		std::cout << "重载operator delete" << std::endl;
		free(_Block);
	}
	friend void* operator new[](size_t size) 
	{
		void* p = nullptr;
		std::cout << "重载operator new[]" << std::endl;
		p = malloc(size);
		if (p == nullptr) {
			throw std::bad_alloc();//异常处理
		}
		return p;
	}
	int m_a = 0;
	int m_b = 0;
};

int main()
{
	
	Test* test = new Test;
	test->m_a = 10;
	test->m_b = 20;
	::std::cout << test->m_a << ' ' << test->m_b << std::endl ;
	delete test;
	
	int* p = new int[ 1024*1024*500 ];//抛出异常
}
/*https://zhuanlan.zhihu.com/p/354046948
* /
/*new是一个关键字，和sizeof一样，我们无法修改其具体功能。new主要做三件事：分配空间、初始化对象、返回指针。调用operator new分配空间。
operator new是一个操作符，和 + - 操作符一样，作用是分配空间。我们可以重写它们，修改分配空间的方式。*/
/*operator new返回值必须是void*。第一个参数必须是size_t，还可加其它参数*/
/*在类中的operator new默认就是static。所以加static可以，不加也是全局，可以正常使用。*/