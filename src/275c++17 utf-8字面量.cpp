#include<iostream>

int main()
{
	using A = decltype(u'A');
	using B = decltype(u"A");
	using C = decltype(u8'A');
	using D = decltype(u8"A");
	using E = decltype(U'A');
	using F = decltype(U"A");
	using G = decltype(L'A');
	using H = decltype(L"A");
	std::cout << typeid(A).name() << std::endl;
	std::cout << typeid(B).name() << std::endl;
	std::cout << typeid(C).name() << std::endl;
	std::cout << typeid(D).name() << std::endl;
	std::cout << typeid(E).name() << std::endl;
	std::cout << typeid(F).name() << std::endl;
	std::cout << typeid(G).name() << std::endl;
	std::cout << typeid(H).name() << std::endl;
	
}
/*
u8用于单字节US-ASCII和UTF-8编码
u用于两字节的UTF-16编码
U用于四字节的UTF-32编码
L用于没有明确编码的宽字符，可能是两个或者四个字节
*/