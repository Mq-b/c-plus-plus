#include<iostream>
#include<string>
#include <iostream>
#include<array>

struct test {
    int a;
    std::string str;
};

test ave() {
    return test{ 56,"可怕" };
}

void test01()
{
    test temp;
    auto [first, second] = temp;
    temp = ave();
    std::cout << temp.a << " " << temp.str << std::endl;
    
}
void test04()
{
    char ch = 0;
    int num = 0;
    char str[100]{ 0 };
    int i = 0;
        ch=std::cin.get();
        //判断cin是否检测到EOF，如果检测到就是true就结束输入和输出
        while (std::cin.fail() == false)
        {
            str[i++] = ch;
            ch = std::cin.get();
            
        }
        std::cout <<str << std::endl;
}
int main() {
    
    //test01();
    test04();
}