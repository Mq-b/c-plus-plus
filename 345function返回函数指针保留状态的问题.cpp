#include<functional>
#include<iostream>

int main() {
	auto ff = [a=0,b=0](int c)constexpr noexcept{
		return c;
	};
	std::function f(ff);//这相当于仿函数给function绑定，c++17以后类模板也能自己推导就不用写明了
	auto F=f.target<int(int)>();		//lamda是不能这么做的，它会返回一个空指针
	std::cout << F << std::endl;//00000000
	std::cout << ff(100) << std::endl;
	std::cout << f(100) << std::endl;
	//std::cout << F(100) << std::endl;	//调用跳转到的地址是一个lambda对象的地址
}
//草，写了个什么jb