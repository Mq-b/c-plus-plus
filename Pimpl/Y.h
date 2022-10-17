#pragma once
#include<memory>
class X;//声明

class Y {
public:
	Y();
	void f();
private:
	X* pimpl;
};