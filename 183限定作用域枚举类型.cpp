#include<iostream>
#include<iomanip>
#include<iostream>
#include<vector>
//限定作用域枚举类型!!!
//1、枚举类型中枚举成员的类型可以显式指定，指定方式是在枚举类型名称后加冒号和枚举成员类型。
enum class move :int	//这个int其实也没啥用
{

	up = 72,//向上
	down = 80,//向下
	left = 75,//向左
	right = 77//向右
};

int main()
{
	std::cout << static_cast<int>(move::down) << std::endl;
	std::cout << static_cast<uint32_t>(move::down) << std::endl;
}