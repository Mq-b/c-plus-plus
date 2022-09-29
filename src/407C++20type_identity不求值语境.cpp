#include<iostream>
#include<vector>

template<class T>
void f(T, T) {}

template<class T>
void g(T, std::type_identity_t<T>) {}

int main() {

	//f(4.2, 0); // 错误：对 'T' 推导出冲突的类型
	g(4.2, 0); // OK ：调用 g<double>
}