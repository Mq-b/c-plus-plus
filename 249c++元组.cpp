#include<iostream>
//tuple 本质是一个以可变模板参数定义的类模板，它定义在 <tuple> 头文件并位于 std 命名空间中。因此要想使用 tuple 类模板，程序中需要首先引入以下代码：
#include <tuple>
using std::tuple;

/*实例化 tuple 模板类对象常用的方法有两种，一种是借助该类的构造函数，另一种是借助 make_tuple() 函数。
类的构造函数
tuple 模板类提供有很多构造函数，包括：*/

/*
1) 默认构造函数
constexpr tuple();
2) 拷贝构造函数
tuple (const tuple& tpl);
3) 移动构造函数
tuple (tuple&& tpl);
4) 隐式类型转换构造函数
template <class... UTypes>
    tuple (const tuple<UTypes...>& tpl); //左值方式
template <class... UTypes>
    tuple (tuple<UTypes...>&& tpl);      //右值方式
5) 支持初始化列表的构造函数
explicit tuple (const Types&... elems);  //左值方式
template <class... UTypes>
    explicit tuple (UTypes&&... elems);  //右值方式
6) 将pair对象转换为tuple对象
template <class U1, class U2>
    tuple (const pair<U1,U2>& pr);       //左值方式
template <class U1, class U2>
    tuple (pair<U1,U2>&& pr);            //右值方式
*/
void test01() {
    int size;
    //创建一个 tuple 对象存储 10 和 'x'
    std::tuple<int, char> mytuple(10, 'x');
    //计算 mytuple 存储元素的个数
    size = std::tuple_size<decltype(mytuple)>::value;
    //输出 mytuple 中存储的元素
    std::cout << std::get<0>(mytuple) << " " << std::get<1>(mytuple) << std::endl;
    //修改指定的元素
    std::get<0>(mytuple) = 100;
    std::cout << std::get<0>(mytuple) << std::endl;
    //使用 makde_tuple() 创建一个 tuple 对象
    auto bar = std::make_tuple("test", 3.1, 14);
    //拆解 bar 对象，分别赋值给 mystr、mydou、myint
    const char* mystr = nullptr;
    double mydou;
    int myint;
    //使用 tie() 时，如果不想接受某个元素的值，实参可以用 std::ignore 代替
    std::tie(mystr, mydou, myint) = bar;
    //std::tie(std::ignore, std::ignore, myint) = bar;  //只接收第 3 个整形值
    //将 mytuple 和 bar 中的元素整合到 1 个 tuple 对象中
    auto mycat = std::tuple_cat(mytuple, bar);
    size = std::tuple_size<decltype(mycat)>::value;
    std::cout << size << std::endl;
}
int main()
{
    std::tuple<int, char> first;                             // 1)   first{}
    std::tuple<int, char> second(first);                     // 2)   second{}
    std::tuple<int, char> third(std::make_tuple(20, 'b'));   // 3)   third{20,'b'}
    std::tuple<long, char> fourth(third);                    // 4)的左值方式, fourth{20,'b'}
    std::tuple<int, char> fifth(10, 'a');                    // 5)的右值方式, fifth{10.'a'}
    std::tuple<int, char> sixth(std::make_pair(30, 'c'));    // 6)的右值方式, sixth{30,''c}

    // make_tuple()函数
    auto first2 = std::make_tuple(10, 'a');   // tuple < int, char >
    const int a = 0; int b[3];
    auto second2 = std::make_tuple(a, b);     // tuple < int, int* >

    test01();
	return 0;
}
3