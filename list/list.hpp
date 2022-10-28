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

        using value_type      = Ty;
        using difference_type = std::ptrdiff_t;
        using pointer         = Ty*;
        using reference       = const value_type&;
        using const_reference = const value_type&;

        Node<value_type>* current;

        List_const_iterator(Node<value_type>* p) :current{ p } {}
        
        constexpr reference operator*()const noexcept{
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

        using value_type      = typename List_const_iterator<Ty>::value_type;
        using difference_type = typename List_const_iterator<Ty>::difference_type;
        using pointer         = typename List_const_iterator<Ty>::pointer;
        using reference       = typename value_type&;

        List_iterator(){}

        List_iterator(Node<value_type>* p) :List_const_iterator<value_type>{ p } {}

        constexpr reference operator*()const {
            return this->current->object;
        }

        constexpr List_iterator& operator++(int) {
            auto old = *this;
            ++(*this);
            return old;
        }

        constexpr List_iterator& operator++() {
            this->current = this->current->next;
            return *this;
        }

        constexpr List_iterator& operator--(int) {
            auto old = *this;
            --(*this);
            return old;
        }

        constexpr List_iterator& operator--() {
            this->current = this->current->previous;
            return *this;
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

        list(std::initializer_list<Ty> init, const Allocator& alloc = Allocator()) {
            _init();
            _init_list(init);
        }

        ~list() {
            _free();
        }

        list& operator=(const list& other) {
            _free();
            _init();
            _copy(other.head, other.tail, other._theSize);
            return *this;
        }

        list& operator=(list&& other) noexcept {
            _free();
            _init();
            _copy(other.head, other.tail, other._theSize);
            return *this;
        }

        list& operator=(std::initializer_list<Ty> ilist) {
            _free();
            _init();
            _init_list(ilist);
            return *this;
        }

        void assign(size_type count, const Ty& value) {
            if (count > size()) {
                _free();
                _init();
                _fill(count, value);
            }else {
                _fill(count, value);
            }
        }

        template< std::input_or_output_iterator InputIt >
        void assign(InputIt first, InputIt last) {
            size_type count = std::distance(first, last);
            Node<value_type>* p = head;
            if (count <= size()) {
                for (auto i = first; i != last; i++) {
                    p->next->object = *i;
                    p = p->next;
                }
            }else {
                _free();
                _init();
                for (auto i = first; i != last; i++) {
                    p->next = ::new(Alloc.allocate(1))Node<value_type>{ *i , p, p->next };
                    p = p->next;
                }
                _theSize = count;
                p->next = tail;
                tail->previous = p;
            }
        }

        void assign(std::initializer_list<Ty> ilist) {
            if (ilist.size() > size()) {
                _free();
                _init();
                _init_list(ilist);
            }else {
                _init_list(ilist);
            }
        }

        allocator_type get_allocator() const noexcept {
            return Alloc;
        }

        reference front() {
            return head->next->object;
        }

        const_reference front() const {
            return head->next->object;
        }

        reference back() {
            return tail->previous->object;
        }

        const_reference back() const {
            return tail->previous->object;
        }

        iterator begin() noexcept {
            return head->next;
        }

        const_iterator begin() const noexcept {
            return head->next;
        }

        const_iterator cbegin() const noexcept {
            return head->next;
        }

        iterator end() noexcept {
            return tail;
        }

        const_iterator end() const noexcept {
            return tail;
        }

        const_iterator cend() const noexcept {
            return tail;
        }

        reverse_iterator rbegin() noexcept {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const noexcept {
            return reverse_iterator(cend());
        }

        const_reverse_iterator crbegin() const noexcept {
            return const_reverse_iterator(cend());
        }

        reverse_iterator rend() noexcept {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const noexcept {
            return const_reverse_iterator(cbegin());
        }

        const_reverse_iterator crend() const noexcept {
            return const_reverse_iterator(cbegin());
        }

        [[nodiscard]] bool empty() const noexcept {
            return size() == 0;
        }

        size_type size() const noexcept {
            return _theSize;
        }

        size_type max_size() const noexcept {
            return std::numeric_limits<difference_type>::max();
        }

        void clear() noexcept {
            _free();
        }

    //private:
        Node<value_type>* head;
        Node<value_type>* tail;
        size_type _theSize;
        allocator_type Alloc;

        void _init() {
            head = ::new(Alloc.allocate(1))Node<value_type>{ 0 };
            tail = ::new(Alloc.allocate(1))Node<value_type>{ 0 };
            _theSize = 0;
        }

        void _fill(size_type count,const value_type& v) {
            Node<value_type> *p = head;
            if (count > size()) {
                for (size_type i = 0; i < count; i++) {
                    p->next = ::new(Alloc.allocate(1))Node<value_type>{ v, p, p->next };
                    p = p->next;
                }
                _theSize = count;
            }else {
                for (size_type i = 0; i < count; i++) {
                    p->next->object = v;
                    p = p->next;
                }
            }
            p->next = tail;
            tail->previous = p;
            tail->next = nullptr;
        }

        template<typename T>
        void _init_list(std::initializer_list<T> init) {
            size_type count = init.size();
            Node<value_type>* p = head;
            if (count > size()) {
                for (size_type i = 0; i < count; i++) {
                    p->next = ::new(Alloc.allocate(1))Node<value_type>{ init.begin()[i], p, p->next };
                    p = p->next;
                }
                _theSize = count;
            }else {
                for (size_type i = 0; i < count; i++) {
                    p->next->object = init.begin()[i];
                    p = p->next;
                }
            }
            p->next = tail;
            tail->previous = p;
            tail->next = nullptr;
        }

        void _copy(Node<value_type>* head, Node<value_type>* tail, size_type count) {
            Node<value_type>* mp = this->head;
            Node<value_type>* tp = head;
            for (size_type i = 0; i < count; i++) {
                mp->next = ::new(Alloc.allocate(1))Node<value_type>{ tp->next->object, mp, mp->next };
                mp = mp->next;
                tp = tp->next;
            }
            mp->next = tail;
            tail->previous = mp;
            tail->next = nullptr;
            _theSize = count;
        }

        void _free() {//!!!!!!!!!!!!!!
            /*if (empty()) return;
            Node<value_type>* p = head->next;
            Node<value_type>* tmp = nullptr;
            while (p != nullptr) {
                tmp = p;
                p = tmp->next;
                Alloc.deallocate(tmp, 1);
            }
            Alloc.deallocate(head, 1);
            Alloc.deallocate(tail, 1);
            _theSize = 0;
            head->next = nullptr;
            tail->next = nullptr;*/
        }

    };
}

#endif // !__LIST_HPP__
