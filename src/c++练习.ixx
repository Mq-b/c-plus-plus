#include<iostream>
#include<string.h>

struct S {
    int a;
};
using s2 = S[2];

int main() {
    //s2{ 1,2 };//error
    s2 s2{ 1,2 };//ok
}