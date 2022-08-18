#include<iostream>
#include<typeinfo>//在此处定义

/*类 type_info 保有一个类型的实现指定信息，包括类型的名称和比较二个类型相等的方法或相对顺序。这是 typeid 运算符所返回的类。

type_info 既不满足可复制构造 (CopyConstructible) 也不满足可复制赋值 (CopyAssignable) 。*/

int main() {
	using a = decltype(typeid(int(10)));//a是const type_info&

	/*true如果 this的类型在实现的排序规则中type_info的类型之前，则返回。rhs不提供任何保证；特别是，排序规则可以在同一程序的调用之间改变。*/
	/*我们目前得出的排序规则: 是前面的类型范围小于后面的即为真*/
	std::cout << typeid(int).before(typeid(intmax_t)) << std::endl;
	
	//std::type_info::hash_code用的很少，就不说了，看文档就行

	//最基本的使用就不用说了
	std::cout << typeid(int).name() << std::endl;

	//这个是编译器扩展，标准库是没有的，打印的是经过Name Mangling处理后的符号
	/*那么这个Name Mangling是什么呢 ?
	* 
	 其实说白了就是对名字进行重新编码的一种规则

	 在编译器构造中，名称修饰是一种用于解决由于需要为许多现代编程语言中的编程实体解析唯一名称而引起的各种问题的技术。

	 对于C++的Name Mangling规则，C++标准并没有做具体的规定，但各个编译器平台形成了一些事实性的标准，比如GCC的一个简单规则：

	 就是一个类的成员函数可能会被Name Mangling编码为：_Z+N+长度+名字+E

	 提供一个权威性的 https://en.wikipedia.org/wiki/Name_mangling
	*/
	std::cout << typeid(int).raw_name() << std::endl;
} 