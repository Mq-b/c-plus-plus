#include<iostream>
#include<string>
#include<vector>
template<typename T>
struct S {
	T val;
};

S(const char*)->S<std::string>;   // 把S<字符串字面量>映射为S<std::string>

template<typename T1, typename T2>
struct Pair3 {
    T1 first;
    T2 second;
    Pair3(const T1& x, const T2& y) : first{ x }, second{ y } {
    }
};
// 为构造函数定义的推导指引
template<typename T1,typename T2>
Pair3(T1, T2)->Pair3<T1, T2>;

template<typename T1,typename T2>
class Test {
public:
    Test(T1 s1, T2 s2) :a(s1), b(s2) {}//只需要保证对应模板类型个数进行初始化即可
private:
    T1 a;
    T2 b;
    T1 d;
};

int main() {
    //得益于c++17，一些简单的推导我们不用再写明模板类的类型
	S s("阿巴巴");
	std::cout << typeid(s.val).name() << std::endl;
    Pair3 s2(1, "阿巴");

    Test s3("阿巴", 1);//都可以自行推导
}