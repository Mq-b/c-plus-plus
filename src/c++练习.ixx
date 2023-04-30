#include<iostream>
struct X { int x, y; };

struct Y {
    Y(std::initializer_list<int>) {}
};

void f(const int(&)[]) { puts("const int(&)[]"); }
void f(const int(&)[2]) { puts("const int(&)[2]"); }
void f(int(&&)[]) { puts("int(&&)[]"); }
void f(X) { puts("X"); }
void f(Y) { puts("Y"); }


int main() {
    f({ 1,2,3 });
    f({ 1,2 });
    f({ .x = 1,.y = 2 });
}