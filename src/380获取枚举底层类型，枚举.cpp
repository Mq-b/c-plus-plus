#include<iostream>
#include<any>
enum struct C :int {//声明枚举底层类型
	A,
	B,
	C
};
enum struct D :short {//声明枚举底层类型，注意作用域枚举使用class或struct毫无区别
	A,
	B,
	C
};
enum E :int {
	a,
	b,
	c
};
int main() {
	using Type = std::underlying_type_t<C>;//纯属开洞实现，获取枚举的底层类型，只对完整枚举类型有效，否则行文未定义
	using Type2 = std::underlying_type_t<D>;
	using Type3 = std::underlying_type_t<E>;
	std::cout << sizeof C << "," << sizeof D << ',' << sizeof E << std::endl;//sizeof的大小只是底层类型的大小
}
/*可以把枚举项当成类似静态数据成员的东西，除了它们是纯右值。
https://zh.cppreference.com/w/cpp/language/enum
*/