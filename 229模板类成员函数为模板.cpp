#include <iostream>

template <typename T>
class Foo
{
public:
    Foo() {}
    ~Foo() {}
    //成员函数有自己的模板参数
    template <typename S>
    void print_s_a(S p)
    {
        std::cout << "S= " << p << std::endl;
        std::cout << "T = " << _a << std::endl;
    }

    template <typename TT>
    void print_tt_a(TT p);//声明模板类成员函数

private:
    T _a = 0;
};

//注意成员模板函数定义在类外的方法
template <typename T>
template <typename TT>
void Foo<T>::print_tt_a(TT p)
{
    std::cout << "TT = " << p << std::endl;
    std::cout << "T = " << _a << std::endl;
}

int main()
{
    Foo<int> f;
    f.print_s_a("123");//类内实现的调用

    f.print_tt_a("456");//类外实现的调用
    return 0;
}
//对类模板而言，其成员函数只有在被用到的时候才会被实例化