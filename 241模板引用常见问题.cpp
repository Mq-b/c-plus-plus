#include<iostream>
#include<string>
template<typename T>
auto func(T& v) {
	std::cout << typeid(v).name() << std::endl;
}

template<typename T>
auto func2(T a){

	std::cout << typeid(a).name() << std::endl;
}
template<typename T>
void outR(T& arg) {//is_array用来判断是否为数组，返回bool类型
	if (std::is_array<T>::value){
		std::cout << "got array of " << std::extent<T>::value << std::endl;
	}
}
int main()
{
	std::string str;
	//func(std::string("n"));//错误的不合法的，不允许使用零时对象
	func(str);
	func("哈哈");
	//func(std::move(str));//不允许通过std::move()处理过的已存在的变量（xvalue）用作其参数
	std::endl(std::cout);

	//按照值传递的话则都可以实例化使用
	func2(std::string("n"));
	func2(str);
	func2("哈哈");//退化为指针
	func2(std::move(str));

	std::endl(std::cout);
	std::string const str2;
	func(str2);//对于string类创建的对象，typeid没有办法区别cv限定符，所以结果和上面的一样 ，但是传递的的确是常量
	//outR(str2);
	return 0;
}
/*按引用传递参数时，其类型不会退化（decay）。也就是说不会把裸数组转换为指针，也不会移除const 和volatile 
等限制符。而且由于调用参数被声明为T const &，被推断出来的模板参数T 的类型将不包含const。*/