#ifndef __DEQUE_HPP__
#define __DEQUE_HPP__

#include<iterator>
#include<algorithm>
#include<type_traits>
#include<iterator>

template<class Ty>
class Deque_const_iterator {
public:
    using value_type      = Ty;
    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;
    using pointer         = Ty*;
    using const_pointer   = const Ty*;
    using reference       = const Ty&;
    using const_reference = const Ty&;
    using map_pointer     = Ty**;
public:

    void set_node(map_pointer new_node) {
        node = new_node;//记录新的连续空间在 map 数组中的位置
        first = *new_node; //更新 first 指针
        //更新 last 指针，difference_type(buffer_size())表示每段连续空间的长度
        last = first + difference_type(buffer_size());
    }

    constexpr reference operator*()const noexcept {
        return *cur;
    }

    constexpr pointer operator->() const { 
        return &(operator *()); 
    }

    reference operator++() {
        ++cur;
        //处理 cur 处于连续空间边缘的特殊情况
        if (cur == last) {
            //调用该函数，将迭代器跳跃到下一个连续空间中
            set_node(node + 1);
            //对 cur 重新赋值
            cur = first;
        }
        return *this;
    }
    //重置前置 -- 运算符
    reference operator--() {
        //如果 cur 位于连续空间边缘，则先将迭代器跳跃到前一个连续空间中
        if (cur == first) {
            set_node(node - 1);
            cur == last;
        }
        --cur;
        return *this;
    }

    constexpr size_type buffer_size()const noexcept {
        return 512 / sizeof(value_type);
    }

protected:

    pointer cur;
    pointer first;
    pointer last;
    map_pointer node;
};

template<class Ty>
class Deque_iterator:public Deque_const_iterator<Ty> {
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

protected:
    iterator start;
    iterator finish;
    const_iterator::map_pointer map_ptr;
};

#endif