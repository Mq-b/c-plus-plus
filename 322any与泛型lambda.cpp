﻿#include<iostream>
#include<string>
#include<any>
#include<vector>

int main() {

	auto a = [](auto a, auto b) {return a + b; };
	using Type = decltype(a);	//获得泛型lambda的类型
	std::vector<std::any>V;
	V.push_back(a);		//将泛型lambda插入到容器中，any 类为任何可复制构造类型的单个值描述了一个类型安全的容器。

	auto ret = std::any_cast<Type>(V[0])(10, 20);						//调用泛型lambda
	auto ret2 = std::any_cast<Type>(V[0])(std::string("傻子:"), "666");	//调用泛型lambda
	std::cout << ret << std::endl;
	std::cout << ret2 << std::endl;

	V.push_back(100);	//any可以接收任何类型
	std::cout << std::any_cast<int>(V[1]) << std::endl;	//使用std::any_cast将类型转换回来即可
}