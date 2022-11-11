#include<iostream>

#define SECNAME ".CRT$XCG"
#pragma section(SECNAME,long,read)
void foo() {
	std::cout << "hello" << '\n';
}

typedef void(__cdecl* _PVFV)();
__declspec(allocate(SECNAME)) _PVFV dummy[] = { foo };

int main() {//foo函数将先于main函数执行,也就是自己添加初始化函数,如果在GCC可以直接使用 __attribute__((constructor))声明函数就好
	std::cout << "main" << '\n';
}