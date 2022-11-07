#include"lib//mylib.h"
#include<map>
#include<string>
struct X {
    enum A {
        I,O,P
    };
    void f() {
        std::cout << I;
    }
};
int main() {
    X().f();
    
}