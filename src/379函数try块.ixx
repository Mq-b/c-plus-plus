//建立围绕整个函数体的异常处理块
#include <iostream>
#include <string>

struct S
{
    std::string m;

    S(const std::string& str, int idx) try : m(str, idx)//此构造将抛出异常
    {
        std::cout << "S(" << str << ", " << idx << ") 构造完成，m = " << m << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << "S(" << str << ", " << idx << ") 失败：" << e.what() << '\n';
    } // 此处有隐含的 "throw;"catch的时候对象已经销毁了
};
export struct alignas(int) Test{
    int value = 0;
    consteval Test(int v) :value{ v } {}

    [[nodiscard("什么？你忽略返回值？！")]] constexpr auto f(double a, double b) const& noexcept(false)->double try {
        return a / b;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
};
int main()
{
    S s1{ "ABC", 1 }; // 不抛出（索引在范围内）

    try
    {
        S s2{ "ABC", 4 }; // 抛出（越界）
    }
    catch (std::exception& e)
    {
        std::cout << "S s2... 抛出了一个异常：" << e.what() << '\n';
    }

    Test c(10);
    std::cout << c.f(10.1, 0) << std::endl;
}
/*一个s2构造抛出了两个异常，首先构造函数，用std::string，int构造一个string，是越界的，非法，两个是同一个异常，原因：第二次是捕获了函数try重抛的异常
离开函数要么返回要么抛出，在函数try的catch子句中对象已经销毁了，不可能正确返回
*/