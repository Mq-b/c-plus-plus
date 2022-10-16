#include <iostream>
#include <type_traits>
#include <typeinfo>

int main()
{
    typedef std::conditional_t<true, int, double> Type1;                            //int
    typedef std::conditional_t<false, int, double> Type2;                           //double
    typedef std::conditional_t<sizeof(int) >= sizeof(double), int, double> Type3;   //double

    std::cout << typeid(Type1).name() << '\n';
    std::cout << typeid(Type2).name() << '\n';
    std::cout << typeid(Type3).name() << '\n';
}