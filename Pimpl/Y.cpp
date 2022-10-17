#include "Y.h"//注意引入两个声明文件
#include"X.h"

Y::Y() :pimpl(new X) {}

void Y::f()
{
	this->pimpl->f();
}
