#include<iostream>

template<typename T>
concept C2 = requires(T x)
{
    // 表达式 *x 必须合法
    // 并且 类型 T::inner 必须存在
    // 并且 *x 的结果必须可以转换为 T::inner
    {*x} -> std::convertible_to<typename T::inner>;

    // 表达式 x + 1 必须合法
    // 并且 std::same_as<decltype((x + 1)), int> 必须满足
    // 即, (x + 1) 必须为 int 类型的纯右值
    {x + 1} -> std::same_as<int>;

    // 表达式 x * 1 必须合法
    // 并且 它的结果必须可以转换为 T
    {x * 1} -> std::convertible_to<T>;
};