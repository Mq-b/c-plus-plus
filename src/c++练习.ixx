#include<iostream>
#include<string.h>

void f(int arr[0]) { std::cout << *arr << '\n'; }

int main() {
    int* p = new int{ 1 };
    f(p);
}