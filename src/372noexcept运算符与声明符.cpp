#include<iostream>
void f()noexcept(false);//声明
//这里是做声明符的作用，c++17以后noexcept是函数类型的一部分，但是不是函数签名的一部分(也就是和返回值类似，不可做重载)

void ff()noexcept(true);

int main() {
	f();
	ff();

	//noexcept运算符,如果函数可能抛出异常返回false，反之返回true
	std::cout << std::boolalpha << noexcept(f()) << '\n' << noexcept(ff()) << std::endl;
	//再给你们回忆一下noexcept指定函数是否抛出异常，使用noexcept可以编译器可以进行更好的优化
}

void f() {//由此得知noexcept(false)等价于没有noexcept说明，noexcept(true)等价于noexcept
	std::cout << "f()noexcept(false)\n";
}
void ff()noexcept {
	std::cout << "f()noexcept(true)\n";
}