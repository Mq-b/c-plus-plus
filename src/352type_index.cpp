#include<iostream>
#include<typeindex>//定义
#include<unordered_map>
/*
	type_index 类是一个围绕 std::type_info 的包装类，它可用作关联与无序关联容器的索引。它与 type_info 对象的关系通过一个指针维系，故而 type_index 
	为可复制构造 (CopyConstructible) 且为可复制赋值 (CopyAssignable) 。
*/

struct A {
    virtual ~A() {}
};

struct B : A {};
struct C : A {};
/*
std::hash<std::type_index>(C++11)std::type_index 的散列支持(类模板特化)
有了它我们才不需要自己特例化注入std，就能直接用std::type_index做key
*/
int main()
{
    //第一个参数是std::type_index，它的构造函数的类型其实就是typeid运算符返回的类型:const type_info&
    std::unordered_map<std::type_index, std::string> type_names;

    type_names[std::type_index(typeid(int))] = "int";
    type_names[std::type_index(typeid(double))] = "double";
    type_names[std::type_index(typeid(A))] = "A";
    type_names[std::type_index(typeid(B))] = "B";
    type_names[std::type_index(typeid(C))] = "C";

    int i;
    double d;
    A a;

    // 注意我们正在存储指向类型 A 的指针
    std::unique_ptr<A> b(new B);
    std::unique_ptr<A> c(new C);

    std::cout << "i is " << type_names[std::type_index(typeid(i))] << '\n'; //int
    std::cout << "d is " << type_names[std::type_index(typeid(d))] << '\n'; //double
    std::cout << "a is " << type_names[std::type_index(typeid(a))] << '\n'; //A
    std::cout << "b is " << type_names[std::type_index(typeid(*b))] << '\n';//B
    std::cout << "c is " << type_names[std::type_index(typeid(*c))] << '\n';//C
}
//有一说一我还真不知道这有什么具体用处