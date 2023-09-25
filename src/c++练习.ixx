#include <iostream>
#include <memory>
consteval void f(int n)
{
    constexpr int v = n;
}

int main()
{
    f(1);
}