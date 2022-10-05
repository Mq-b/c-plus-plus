#include<iostream>
template<class T> // 主模板
class X;
template<>        // 特化（声明，不定义）
class X<int>;

X<int>* p;//OK：指向不完整类型的指针

template<>
class X<int> {//定义
public:
	X() { std::cout << "6\n"; }
};

int main() {
	p = new X<int>;
}
/*
使用场景也就是你需要先声明而不定义的时候了
*/