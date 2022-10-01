#include<iostream>
struct A
{
    A() :m_a(1) {}
    int m_a;
    virtual void f() { std::cout << "A   fun " << m_a << std::endl; };
};
struct B
{
    B() :m_b(2) {}
    int m_b;
    virtual void f() { std::cout << "666666666666\n"; };
};

void ff() { std::cout << "1\n"; }

int main()
{
    A* a = new A;
    a->f();
    int* vptr = reinterpret_cast<int*>(a);

    B* b1 = new B;
    *vptr = *reinterpret_cast<int*>(b1);
    a->f();
}