#include <iostream>
#include <memory>

struct S {
    int x;
    float y;
    double z;

    S(int x, float y, double z) : x{ x }, y{ y }, z{ z } { std::cout << "S::S();\n"; }

    ~S() { std::cout << "S::~S();\n"; }

    void print() const {
        std::cout << "S { x=" << x << "; y=" << y << "; z=" << z << "; };\n";
    }
};

int main()
{
    unsigned char storage[sizeof(S)]{};

    S* ptr = std::construct_at(reinterpret_cast<S*>(storage), 42, 2.71828f, 3.1415);
    ptr->print();
    std::cout << ptr << ' ' << &storage << std::endl;
    std::destroy_at(ptr);

    //原理也就是下面这种
    char s[4]{};
    auto p = ::new(reinterpret_cast<void*>(s))int(10);
    std::cout << *p << std::endl;
    std::cout << p << '\t' << &s << std::endl;
}
/*
::(可选) new (布置参数) ( 类型 ) 初始化器(可选)
::(可选) new (布置参数) new类型 初始化器(可选)
" (类型) "和" new类型 "的区别只是new类型不能包含括号
*/