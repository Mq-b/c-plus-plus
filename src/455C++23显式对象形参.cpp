#include<iostream>
//非静态成员函数的声明可以通过在第一个形参前附关键词 this 来指定该形参为显式对象形参
struct X{
    void foo(this X const& self, int i) {};
    //void foo(int i) const &;二者等价，且不能重复声明

    auto bar(this X self, int i) {
        return self;
    };
};

//对于成员函数模板，显式对象形参的类型和值类别可以被推导，因此该语言特性也被称为“推导 this”：
struct Y{
    template<typename Self>
    void foo(this Self&&, int) {};
};

struct D : Y {};

void ex(Y& x, D& d){
    x.foo(1);       // Self = X&
    std::move(x).foo(2); // Self = X&&
    d.foo(3);       // Self = D&
}

struct C{
    void bar();

    void foo(this C c)
    {
        //auto x = this; // 错误：不能使用 this
        //bar();         // 错误：没有隐式的 this->
        c.bar();       // OK
    }
};

struct Y2{
    void f(int, int)  const& { puts("f"); }
    void g(this Y2 const&, int, int) { puts("g"); }
};

int main() {
    Y y_;D d;
    ex(y_, d);
    X x;
    auto t = x.bar(1);

    Y2 y;
    auto pf = &Y2::f;
    //pf(y, 1, 2);              // 错误：不能调用指向成员函数的指针
    (y.*pf)(1, 2);            // OK
    std::invoke(pf, y, 1, 2); // OK

    auto pg = &Y2::g;
    pg(y, 3, 4);              // OK

    //(y.*pg)(3, 4);            // 错误：pg 不是指向成员函数的指针
    std::invoke(pg, y, 3, 4); // OK
}