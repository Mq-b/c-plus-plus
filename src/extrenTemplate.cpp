#include"extrenTemplate.h"

template<typename T>
void f() {
	std::cout << "66\n";
}
//explicit instantation 显式实例化
template void f<int>();