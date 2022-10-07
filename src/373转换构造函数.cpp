struct A
{
    A() { }         // 转换构造函数 (C++11 起)  
    A(int) { }      // 转换构造函数
    A(int, int) { } // 转换构造函数 (C++11 起)
};

struct B
{
    explicit B() { }
    explicit B(int) { }
    explicit B(int, int) { }
};

int main()
{
    A a1 = 1;      // OK：复制初始化选择 A::A(int)
    A a2(2);       // OK：直接初始化选择 A::A(int)
    A a3{ 4, 5 };    // OK：直接列表初始化选择 A::A(int, int)
    A a4 = { 4, 5 }; // OK：复制列表初始化选择 A::A(int, int)
    A a5 = (A)1;   // OK：显式转型进行 static_cast，是直接初始化

    //  B b1 = 1;      // 错误：复制初始化不考虑 B::B(int)
    B b2(2);       // OK：直接初始化选择 B::B(int)
    B b3{ 4, 5 };    // OK：直接列表初始化选择 B::B(int, int)
    //  B b4 = {4, 5}; // 错误：复制列表初始化选择了显式构造函数 B::B(int, int)
    B b5 = (B)1;   // OK：显式转型进行 static_cast，是直接初始化
    B b6;          // OK：默认初始化
    B b7{};        // OK：直接列表初始化
    //  B b8 = {};     // 错误：复制列表初始化选择了显式构造函数 B::B()
}
/*不以说明符 explicit 声明且可以用单个参数调用 (C++11 前)的构造函数被称为转换构造函数
https://zh.cppreference.com/w/cpp/language/converting_constructor
*/