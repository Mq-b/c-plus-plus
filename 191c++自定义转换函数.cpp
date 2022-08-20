#include<iostream>
#include<string>
struct X
{
    // 隐式转换
    operator int() const noexcept{ return 7; }

    // 显式转换
    explicit operator int* () const noexcept{ return nullptr; }

    // 错误：转换类型标识中不能出现数组运算符
//  operator int(*)[3]() const { return nullptr; }

    using arr_t = int[3];
    operator arr_t* () const { return nullptr; } // 可以通过 typedef 转换
    //  operator arr_t () const; // 错误：任何情况下都不能转换到数组
};

struct Test {
    explicit Test(size_t n) : i(n) {}
    operator std::string()const noexcept {
        std::cout << "调用Test::operator std::string()const noexcept转换函数" << std::endl;
        return std::to_string(i); 
    }
private:
    size_t i = 0;
};

struct Number {
    explicit Number(double i) :n(i) {}
    operator double()const noexcept { return this->n; };
private:
    double n;
};

int main()
{
    X x;

    int n = static_cast<int>(x);   // OK：设 n 为 7 这里其实写不写强转都可以，static_cast<int>会调用转换函数
    int c = int(x);                //Ok: n为7，其实和上面是一个意思,一般写成上面这样就行
    int m = x;                     // OK：设 m 为 7 X类型的x隐式转换为int

    int* p = static_cast<int*>(x); // OK：设 p 为空
    //  int* q = x; // 错误：没有隐式转换 int*的转换函数有explicit修饰
    
    int* q = static_cast<int*>(x);//只能先调用转换函数，无法直接隐式转换

    int(*pa)[3] = x;  // OK

    Test s(123);
    std::string str = s;//调用隐式转换函数，将Test转换为std::string
    std::cout << str << std::endl;

    //在和基本数据类型运算的时候也会自动隐式的调用转换函数进行转换
    auto ret = 10 + 5.2 + Number(20.5);
    std::cout << ret << std::endl;
}