#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include <queue>
#include<deque>

template<typename T, template<typename> typename Container>//模板的第二个参数为模板，外部的typename表示这是一个类型，模板，不需要变量
class XCls
{
private:
    Container<T> c;//用模板的模板参数创建模板对象
};
template<typename T>
class test
{
private:
    T t;
};
//也可以设置默认参数,我们发现一件有趣的事情，不能使用using或者typedef的别名,比如string，vector,模板的参数必须和传入的模板吻合，如下
template<typename T, template <class _Ty, class _Container = std::deque<_Ty>>typename Container=std::queue>
class XCls2
{
private:
    Container<T> c;
};

int main(void)
{
    XCls<std::string, test> mylst1;
    XCls2<std::string> mylst2;
    return 0;
}