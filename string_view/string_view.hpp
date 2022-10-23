#ifndef __STRING_VIEW_HPP__
#define __STRING_VIEW_HPP__

#include<iterator>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<string>

namespace mylib {
    template<class CharT,class Traits = std::char_traits<CharT>> 
    class basic_string_view {

    };
    
    using string_view = mylib::basic_string_view<char>;
}

#endif