#include<iostream>
struct Test {
	int a, b;
	char c[10];
};
struct Test2 {
	int a, b;
	alignas(16) char c[10];
};
int main() {
	alignas(Test) unsigned char size[sizeof(Test)]{};
	char size2[sizeof(Test)]{};

	std::cout << sizeof(Test) << std::endl;
	std::cout << sizeof(Test2) << std::endl;
}