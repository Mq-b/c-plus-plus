#include<iostream>
struct test
{
	int a;
	double b;
	char c[0];
};
int main() {
	auto t = (test*)malloc(sizeof(test) + 27 * sizeof(char));
	memset(t->c, 0, 27);//记得置0
	std::cout << sizeof * t << std::endl;
	for (int i = 0; i < 26; i++) {
		t->c[i] = 'A' + i;
	}
	std::cout << t->c << std::endl;
	free(t);
}
/*柔性数组是非标准扩展，不是c++的东西，C/C++标准规定不能定义长度为0的数组*/
/*
柔性数组成员允许结构中包含一个大小可变的数组。柔性数组成员只作为一个符号地址存在，而且必须是结构体的最后一个成员，sizeof 返回的这种结构大小不包括柔性数组的内存。

柔性数组成员不仅可以用于字符数组，还可以是元素为其它类型的数组。包含柔性数组成员的结构用malloc ()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小
*/