#ifndef __DEQUE_HPP__
#define __DEQUE_HPP__

#include<iterator>
#include<algorithm>
#include<type_traits>
#include<iterator>

template<class Ty>
class Deque_const_iterator {
public:

};

template<class Ty>
class Deque_iterator:public Deque_const_iterator<Ty> {
public:

};

template<class Ty>
class Deque_unchecked_const_iterator {
public:

};

template<class Ty>
class Deque_unchecked_iterator :public Deque_unchecked_const_iterator<Ty> {
public:

};

template <class Ty, class Alloc = std::allocator<Ty>>
class deque {
private:
    using Alty_traits = std::allocator_traits<Alloc>;
public:
    using allocator_type            = Alloc;
    using value_type                = Ty;
    using size_type                 = typename Alty_traits::size_type;
    using difference_type           = typename Alty_traits::difference_type;
    using pointer                   = typename Alty_traits::pointer;
    using const_pointer             = typename Alty_traits::const_pointer;
    using reference                 = Ty&;
    using const_reference           = const Ty&;                      
    using iterator                  = Deque_iterator<value_type>;
    using const_iterator            = Deque_const_iterator<value_type>;
    using reverse_iterator          = std::reverse_iterator<iterator>;
    using const_reverse_iterator    = std::reverse_iterator<const_iterator>;
};

#endif