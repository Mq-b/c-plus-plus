#include <iostream> // std::cout
#include <type_traits> // std::is_same

template<class T1, class T2>
void print_is_same() {
	std::cout << std::is_same_v<T1, T2> << '\n';
}

//它的简单实现
template<class T>
struct Test {
	using type = T;
};
template<class T>
struct Test<T&> {
	using type = T;
};
template<class T>
struct Test<T&&> {
	using type = T;
};

template<class T>
using Test_t = typename Test<T>::type;

int main() {
	std::cout << std::boolalpha;

	print_is_same<int, int>();
	print_is_same<int, int&>();
	print_is_same<int, int&&>();

	print_is_same<int, std::remove_reference_t<int>>();
	print_is_same<int, std::remove_reference_t<int&>>();
	print_is_same<int, std::remove_reference_t<int&&>>();
	//std::remove_reference_t的作用非常简单，类型不管是左值还是右值都变成引用的类型的，即:就是T&& T& T通通变成T

	using a = Test_t<int&>;//int
	using b = Test_t<int&&>;//int
	using c = Test_t<int>;//int
	std::cout << typeid(a).name() << "," << typeid(b).name() << "," << typeid(c).name() << std::endl;
}