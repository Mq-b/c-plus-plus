#include "extrenTemplate.h"
#include<vector>
extern template void f<int>();

/*在 C++03 中，每当在翻译单元中遇到完全指定的模板时，编译器都必须实例化模板。如果在许多翻译单元中使用相同的类型实例化模板，这可能会大大增加编译时间。
在 C++03 中没有办法阻止这种情况，因此C++11 引入了外部模板声明，类似于外部数据声明
*/
extern template class std::vector<int>;//外部模板对于模板函数，模板类，乃至模板成员函数都有效
int main() {
    f<char>();
    
}