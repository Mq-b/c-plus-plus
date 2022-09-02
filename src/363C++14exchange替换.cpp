#include <iostream>
#include <utility>
#include <vector>
#include <iterator>

void f() { std::cout << "f()"; }

int main()
{
    std::vector<int> v{0,0,0,0};

    // 因为第二模板形参有默认值，故能以花括号初始化列器表为第二参数。
    // 下方表达式等价于 std::exchange(v, std::vector<int>{1,2,3,4});
    auto v2=std::exchange(v, { 1,2,3,4 });//返回旧值

    std::copy(begin(v2), end(v2), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, ", "));

    std::cout << "\n\n";

    void (*fun)();
    // 模板形参的默认值亦使得能以通常函数为第二参数。
    // 下方表达式等价于 std::exchange(fun, static_cast<void(*)()>(f))
    std::exchange(fun, f);
    fun();
}