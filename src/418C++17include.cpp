#if __has_include(<iostream>)//检查能不能找到这个文件，如果能找到这个宏就返回1
#  include <iostream>
#endif

#if __has_include(<6>)
#include<6>
#endif

int main() {
	
}
/*
https://zh.cppreference.com/w/cpp/preprocessor/include
*/