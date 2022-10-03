#include<iostream>

int fo() { return 10; }
void bar()
{
	return (void)fo();//转换到void显示弃值
	return static_cast<void>(100);//一个意思
}
int main() {
	bar();
}

/*
在弃值表达式中也有介绍
https://zh.cppreference.com/w/cpp/language/expressions#.E8.BD.AC.E6.8D.A2
*/