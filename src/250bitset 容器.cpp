/*bitset容器其实就是个01串。可以被看作是一个bool数组。它比bool数组更优秀的优点是：节约空间，节约时间，支持基本的位运算。在bitset容器中，8位占一个字节，
* 
相比于bool数组4位一个字节的空间利用率要高很多。同时，n位的bitset在执行一次位运算的复杂度可以被看作是n/32，这都是bool 数组所没有的优秀性质。

容器包含在C++自带的bitset库中。*/
#include<bitset>
#include<iostream>

int main() {
	std::bitset<10>s;
	for (int i = 0; i < 10; i++)s[i] = false;
	//count()函数	count，数数的意思。它的作用是数出1的个数。即s.count()返回s中有多少个1.
	std::cout << s.count() << std::endl;//输出0

	/*any()/none()函数*/
	//any，任何的意思。none，啥也没有的意思。这两个函数是在检查bitset容器中全0的情况。

	//如果，bitset中全都为0，那么s.any()返回false，s.none()返回true。
	std::cout << s.any() << "," << s.none() << std::endl;

	//set()函数,把bitset全部设置为1	
	s.set();							//全部设置为1
	std::cout << s.count() << std::endl;//输出10
	//set()函数里面可以传参数。set(u, v)的意思是把bitset中的第u位变成v, v∈0 / 1。
	s.set(0, 5);

	//reset()函数,和上面的相反,不过只接收一位参数
	s.reset(2);							//把0-2范围的换成0
	std::cout << s.count() << std::endl;//输出9
	//s.reset();							//全部换成0
	//std::cout << s.count() << std::endl;//输出0

	//flip()函数与前两个函数不同，它的作用是将整个bitset容器按位取反。
	s.flip();
	std::cout << s << std::endl;	//0000000100
	//同上，其传进的参数表示把其中一位取反。相当于位运算的~
	s.flip(1);						//从右边数第二位也就是1反转
	std::cout << s << std::endl;	//0000000110
	/*我们在编写程序的时候对数进行的二进制运算均可以用在bitset

	函数上。

	比如：

	~：按位取反

	&：按位与

	|：按位或

	^：按位异或

	<< >>：左/右移

	==/！=：比较两个bitset
	是否相等。*/
	return 0;
}