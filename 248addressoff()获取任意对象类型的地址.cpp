#include<iostream>
#include<string>
void f(auto&& x)//string对象无法绑定右值引用，auto自动去掉了一个&，所以实际是普通的左值引用
{
	auto p = &x; 
	auto q = std::addressof(x); 
	x = "哈哈哈";
	std::cout << typeid(p).name() << std::endl;
	std::cout << typeid(q).name() << std::endl;
}

int main()
{
	std::string name{ "123" };
	f(name);
	std::cout << name << std::endl;
	return 0;
}
/*函数模板std::addressof<>()会返回一个对象或者函数的准确地址。即使一个对象重载了运算
符&也是这样。虽然后者中的情况很少遇到，但是也会发生（比如在智能指针中）。因此，
如果需要获得任意类型的对象的地址，那么推荐使用addressof()：*/