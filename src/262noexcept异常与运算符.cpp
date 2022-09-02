#include<iostream>
/*C++11新标准引入的noexcept运算符，可以用于指定某个函数不抛出异常。预先知道函数不会抛出异常有助于简化调用该函数的代码，而且编译器确认函数不会抛出异常，它就能执行某些特殊的优化操作。*/
void test1() {
	void func(int x) noexcept;  //不抛出异常
	void func1(int x);  //抛出异常
}
/*（1）对于一个函数来说，noexcept说明要么出现在该函数的所有声明语句和定义语句中，要么一次也不出现。
（2）可以再函数指针的声明和定义中指定noexcept。
（3）在typedef和类型别名中不可以出现noexcept。
（4）在成员函数中，noexcept需要跟在const以及引用限定符之后，在final、override或虚函数=0之前。

对于程序违反了异常说明，编译器在编译阶段不会检查报错。*/
void test2() {
	//noexcept可以接受一个可选的实参，该参数必须能转换为bool类型
	void func(int x) noexcept(true);  //不抛出异常
	//void func(int x) noexcept(false); //抛出异常

}
void f() {}
void test3() {
	//noexcept运算符是一个一元运算符，它的返回值是一个bool类型的右值常量表达式，用于表示给定的表达式是否会抛出异常。
	noexcept(f());   //如果f()不抛出异常则结果为true，否则为false
	//noexcept(e);     //当e调用的所有函数都做了不抛出说明且e本身不含有throw语句时，表达式为true，否则返回fals

}

/*4、异常说明与指针、虚函数和拷贝控制

（1）函数指针及该指针指向的函数必须具有一致的异常说明。如果一个指针做出了不抛出异常的声明，则该指针将只能指向不抛出异常的函数。
（2）如果显示或隐式说明了指针可能抛出异常，那么该指针可以指向任何函数。
（3）如果一个虚函数承诺不会抛出异常，则后续派生出来的衍生类的虚函数也必须做出同样的承诺。反之则不需要。
（4）当编译器合成拷贝控制成员的时候，也会生成一个异常说明。如果对所有成员和基类的所有操作都承诺了不抛出异常，则合成的成员是noexcept的；如果有任意一个函数可能抛出异常，则合成的成员是noexcept(false)。

总结
noexcept关键字主要用于对一个函数做出不抛出异常的说明，不抛出异常可以优化函数代码，但是具体改善多少，就以后在研究了。*/

//(1)的示例
void t()noexcept {}
void t2() {}
void test4() {
	void (*fp)() noexcept;
	fp = t;
	//fp = t2;		//错误行为
}
int main() {
	test1();
	test2();
	test3();
	test4();
}