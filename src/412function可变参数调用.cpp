#include<iostream>
#include<functional>

template<class ...Args, class T>
T ExecuteFunc(const std::function<T(Args...)>& f, Args&& ...args) {
	return (T)f(args...);
}
int t(int, int) { return 10; }
void n(int) {  }
int main() {
	std::function f(t);
	std::cout << ExecuteFunc(f, 1, 1) << std::endl;
	std::function f2(n);
	ExecuteFunc(f2, 5);
}