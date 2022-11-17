#include<iostream>
#include<boost/pfr/functions_for.hpp>

struct X {
    template<class T>
    void operator()(T& a) {
        a += 1;
    }
};
int main() {

    struct test {
        int f1;
        long f2;
        size_t f3;
    };

    test var{ 42, 43,44 };

    boost::pfr::for_each_field(var, X{});
    std::cout << var.f1 << ' ' << var.f2 << ' ' << var.f3 << '\n';
}