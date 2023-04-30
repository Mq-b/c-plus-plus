#include<iostream>
void f(const int(&)[]) { puts("const int(&)[]"); }
void f(const int(&)[2]) { puts("const int(&)[2]"); }
void f(int(&&)[]) { puts("const int(&&)[]"); }

int main() {
    f({ 1,2,3 });
    f({ 1,2 });
}