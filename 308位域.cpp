#include<iostream>
/*“ 位域 “ 或 “ 位段 “(Bit field)为一种数据结构，可以把数据以位的形式紧凑的储存，并允许程序员对此结构的位进行操作。这种数据结构的一个好处是它可以使数据单元节省储存空间，当程序需要成千上万个数据单元时，
这种方法就显得尤为重要。第二个好处是位段可以很方便的访问一个整数值的部分内容从而可以简化程序源代码。而这种数据结构的缺点在于，位段实现依赖于具体的机器和系统，在不同的平台可能有不同的结果，这导致了位段在
本质上是不可移植的。*/

struct _PRCODE
{
	unsigned int code1 : 2;//位域的类型只能为int unsigned, int或者signed int 
	unsigned int code2 : 2;
	unsigned int code3 : 8;
};

struct SIZE
{
	unsigned int a : 1;
};

struct _PRCODE prcode;
int main() {
	//我们可以使用结构体的成员运算符对其进行赋值
	prcode.code3 = 255;		//赋值时要注意值的大小不能超过位域成员的容量，例如 prcode.code3 为 8 Bits 的位域成员，其容量为 2^8 = 256，即赋值范围应为 [0,255]。
	prcode.code2 = 4;		//2^2的范围是[0-3]，4的话就相当于0
	prcode.code1 = 5;		//2^2只有4，但是却赋值5，那么结果会是1，只能显示[0,3]
	std::cout << prcode.code3 << std::endl;
	std::cout << prcode.code2 << std::endl;
	std::cout << prcode.code1 << std::endl;

	struct _PRCODE a = { 1,2,3 };//聚合初始化也可
	std::cout << sizeof _PRCODE << std::endl;//在 x86 系统中为 32 Bits，即四字节。也就是说目前sizeof，必须是4的倍数
	std::cout << sizeof SIZE << std::endl;//就算只有一个比特，那也是四个字节

}