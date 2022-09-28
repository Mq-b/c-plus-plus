#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/gmp.hpp>
#include <iostream>
#include<boost/atomic.hpp>

int main() {
    using Int = boost::multiprecision::cpp_int;
    using Float = boost::multiprecision::number<boost::multiprecision::gmp_float<0>>;

    Float fake_pi;
    boost::multiprecision::default_ops::calc_pi(fake_pi.backend(), 2000);

    Int value("12345678901234567890123456789012345678901234567890");

    std::cout << std::fixed << value << " * " << fake_pi << " = " << Float(value.convert_to<Float>() * fake_pi);

    boost::atomic<int> c();
}