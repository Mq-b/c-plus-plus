#ifndef __LIST_HPP__
#define __LIST_HPP__

#include<iterator>
#include<memory>
#include<algorithm>
#include<numeric>
#include<type_traits>

namespace mylib {

    template <typename Object> struct Node {
        Object object;
        Node<Object>* previous;
        Node<Object>* next;
        Node(const Object& obj) :object(obj), next(nullptr), previous(nullptr) {}
        Node() :next(nullptr), previous(nullptr) {}
    };

    template<typename Ty>
    class List_const_iterator {
    protected:
        Node<Ty>* current;

    public:
        
        constexpr Ty& operator*()const {
            return current->object;
        }

        constexpr List_const_iterator& operator++(int) {
            auto old = *this;
            ++(*this);
            return old;
        }

        constexpr List_const_iterator& operator++() {
            current = current->next;
            return *this;
        }

        constexpr List_const_iterator& operator--(int) {
            auto old = *this;
            --(*this);
            return old;
        }

        constexpr List_const_iterator& operator--() {
            current = current->previous;
            return *this;
        }

        constexpr bool operator==(const List_const_iterator& rhs) {
            return current == rhs.current;
        }

        constexpr bool operator!=(const List_const_iterator& rhs) {
            return !(current == rhs.current);
        }

    };

    template<typename Ty>
    class List_iterator :public List_const_iterator<Ty> {
    public:
        List_iterator(){}
        constexpr Ty& operator*() {
            return this->current->object;
        }

        constexpr Ty& operator*()const {
            return List_const_iterator<Ty>::operator*();
        }

        constexpr List_iterator& operator++(int) {
            this->current = this->current->next;
            return *this;
        }

        constexpr List_iterator& operator++() {
            auto old = *this;
            ++(*this);
            return old;
        }

        constexpr List_iterator& operator--(int) {
            this->current = this->current->previous;
            return *this;
        }

        constexpr List_iterator& operator--() {
            auto old = *this;
            --(*this);
            return old;
        }
        
    };

    template<class Ty, class Allocator = std::allocator<Ty>> 
    class list {
        using value_type = Ty;
        using allocator_type = Allocator;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = List_iterator<Ty>;
        using const_iterator = List_const_iterator<Ty>;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    };

}

#endif // !__LIST_HPP__
