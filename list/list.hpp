#ifndef __LIST_HPP__
#define __LIST_HPP__

#include<iterator>
#include<memory>
#include<algorithm>
#include<numeric>
#include<type_traits>
#include<initializer_list>

namespace mylib {

    template <typename Object> struct Node {
        Object object;
        Node* previous;
        Node* next;

        Node(const Object& obj = Object{}, Node* p = nullptr, Node* n = nullptr) :object(obj), previous(p), next(n) {}

        Node(Object&& obj = Object{}, Node* p = nullptr, Node* n = nullptr) :object(std::move(obj)), previous(p), next(n) {}
    };

    template<typename Ty>
    class List_const_iterator {
    public:
        Node<Ty>* current;

        List_const_iterator(Node<Ty>* p) :current{ p } {}
        
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

        List_iterator(Node<Ty>* p) :List_const_iterator<Ty>{ p } {}

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

    template<class Ty, class Allocator = std::allocator<Node<Ty>>> 
    class list {
    public:
        using value_type             = Ty;
        using allocator_type         = Allocator;
        using size_type              = std::size_t;
        using difference_type        = std::ptrdiff_t;
        using pointer                = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer          = typename std::allocator_traits<Allocator>::const_pointer;
        using reference              = value_type&;
        using const_reference        = const value_type&;
        using iterator               = List_iterator<Ty>;
        using const_iterator         = List_const_iterator<Ty>;
        using reverse_iterator       = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        list() { _init(); }

        explicit list(const Allocator& alloc) :Alloc(alloc) { _init(); }

        list(size_type count, const Ty& value, const Allocator& alloc = Allocator()) :_theSize(count) {
            _init();
            _fill(count, value);
        }

        explicit list(size_type count, const Allocator& alloc = Allocator()) :_theSize(count) {}

        template< std::input_or_output_iterator InputIt >
        list(InputIt first, InputIt last, const Allocator& alloc = Allocator()) {

        }

        list(const list& other) :Alloc(other.Alloc), head(other.head), tail(other.tail), _theSize(other._theSize) {}

        list(const list& other, const Allocator& alloc) :Alloc(alloc),head(other.head), tail(other.tail), _theSize(other._theSize) {}

        list(list&& other) :Alloc(other.Alloc), head(other.head), tail(other.tail), _theSize(other._theSize) {}

        list(list&& other, const Allocator& alloc) :Alloc(alloc),head(other.head), tail(other.tail), _theSize(other._theSize) {}

        template<typename T>
        list(std::initializer_list<T> init, const Allocator& alloc = Allocator()) {
            _init();
            _init_list(init);
        }

        ~list() {

        }

        list& operator=(const list& other) {

        }

        list& operator=(list&& other) noexcept {

        }

        list& operator=(std::initializer_list<Ty> ilist) {

        }

    //private:
        Node<value_type>* head;
        Node<value_type>* tail;
        size_type _theSize;
        allocator_type Alloc;

        void _init() {
            head = new Node<value_type>{ 0 };
            tail = new Node<value_type>{ 0 };
            _theSize = 0;
        }

        void _fill(size_type count,const value_type& v) {
            Node<value_type> *p = head;
            for (size_type i = 0; i < count; i++){
                p->next = ::new(Alloc.allocate(1))Node<value_type>{ v, p, p->next };
                p = p->next;
            }
            _theSize = count;
        }

        template<typename T>
        void _init_list(std::initializer_list<T> init) {
            size_type count = init.size();
            Node<value_type>* p = head;
            for (size_type i = 0; i < count; i++) {
                p->next = ::new(Alloc.allocate(1))Node<value_type>{ init.begin()[i], p, p->next };
                p = p->next;
            }
            _theSize = count;
        }

    };

    template<typename T>
    list(std::initializer_list<T>)->list<T>;

}

#endif // !__LIST_HPP__
