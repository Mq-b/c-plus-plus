#include<iostream>

/*C++ 属性： noreturn (C++11 起)指示函数不返回。
此属性仅应用到函数声明中正在声明的函数名。若拥有此属性的函数实际上返回，则行为未定义。
若函数的任何声明指定此属性，则其首个声明必须指定它。若函数在一个翻译单元中声明为带 [[noreturn]] 属性，而同一函数在另一翻译单元中声明为不带 [[noreturn]] 属性，则程序非良构；不要求诊断。*/

[[ noreturn ]] void f() {
    throw "error";
    // OK
}
void q [[ noreturn ]] (int i) {
    // 若以 <= 0 的参数调用则行为未定义
    if (i > 0) {
        throw "positive";
    }
}
/*void f()表示“f返回非值”。
[[noreturn]] void g()意思是“g根本不回来；它会做其他事情而不是返回。

通常没有理由使[[noreturn]]函数具有非void返回类型，但在不寻常的情况下，您可能需要这样做。
意思就是你可以写一个[[noreturn]] int g(),为了通过编译你需要return一个值，但是这并不一定导致UB，因为你可以让这个函数一直不return，比如死循环，或者运行完了直接exit(0)，throw
void类型的函数一样如此，不能正常的使用和结束
*/

[[nodiscard("什么？你忽略返回值？！")]] int n(int i) {//鼓励编译器在返回值被舍弃时发布警告c++17，带参数的是c++20
    return i;
}
[[deprecated("这个方法过时了！别再用了！")]] [[nodiscard("什么？你忽略返回值？！")]] int c() {//指示声明有此属性的名字或实体被弃用，即允许但因故不鼓励使用。
    return 0;
}

int main() {
    int a [[maybe_unused]] ;//压制编译器在未使用实体上的警告，若存在(c++17)。(如果没有使用这个属性说明符那么就会“a:未引用的局部变量”)
    int b;//对照组
    n(10);
    c();
}
/*我们介绍了一些常用的，有意思的C++标准库的属性，其实还可以使用编译器扩展，也还有使用using的其他语法可以看文档
https://zh.cppreference.com/w/cpp/language/attributes
*/