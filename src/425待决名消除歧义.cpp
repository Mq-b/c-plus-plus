#include<iostream>
#include<vector>

struct A {
	struct X {};
};

struct B {
	struct X {};
};

template<typename T>
void f() {
	//如果不使用typename，将认为const_iterator是静态成员变量从而出现问题，所有类似情况都是
	typename std::vector<T>::const_iterator iter_t;
}
template<class T>
void f2(T t)
{
	typename T::X x;//和上面的一样，不加typename就不会认为X是类型
}
//模板定义中不是当前实例化的成员的待决名同样不被认为是模板名，除非使用消歧义关键词 template，或它已被设立为模板名：
template<typename T>
struct S
{
	template<typename U>
	void foo() {}
};

template<typename T>
void bar()
{
	S<T> s;//S是待决的
	s.foo<T>();          // 错误：< 被解析为小于运算符，不是当前实例化的成员的待决名不被认为是模板名(但是牛马MSVC可以解析)
	s.template foo<T>(); // OK
}
int main() {
	f<int>();
	A a;
	B b;
	f2(a);
	f2(b);

	bar<int>();
}
//关键词 template 只能以这种方式用于运算符 ::（作用域解析）、->（通过指针的成员访问）和 .（成员访问）之后，下列表达式都是合法示例：
/*T::template foo<X>();
s.template foo<X>();
this->template foo<X>();
typename T::template iterator<int>::value_type v;*/

// https://zh.cppreference.com/w/cpp/language/dependent_name