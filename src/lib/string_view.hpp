#ifndef __STRING_VIEW_HPP__
#define __STRING_VIEW_HPP__

#include<iterator>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<string>
#include<type_traits>
#include<memory>

template<typename Traits>
struct _string_view_iterator {
    using value_type        = typename Traits::char_type;
    using difference_type   = ptrdiff_t;
    using pointer           = const value_type*;
    using reference         = const value_type&;

    constexpr reference operator*()const noexcept {
        return *m_ptr;
    }

    constexpr pointer operator->()const noexcept {
        return m_ptr;
    }

    constexpr _string_view_iterator& operator++()noexcept {
        ++m_ptr;
        return *this;
    }

    constexpr _string_view_iterator operator++(int)noexcept {
        _string_view_iterator tmp{ *this };
        ++* this;
        return tmp;
    }

    constexpr _string_view_iterator& operator--()noexcept {
        --m_ptr;
        return *this;
    }

    constexpr _string_view_iterator operator--(int)noexcept {
        _string_view_iterator tmp{ *this };
        --* this;
        return tmp;
    }

    [[nodiscard]] constexpr _string_view_iterator operator+(size_t n)const noexcept {
        _string_view_iterator tmp{ *this };
        tmp.m_ptr += n;
        return tmp;
    }

    [[nodiscard]] constexpr _string_view_iterator operator-(size_t n)const noexcept {
        _string_view_iterator tmp{ *this };
        tmp.m_ptr -= n;
        return tmp;
    }

    constexpr void operator+=(size_t n) {
        m_ptr += n;
    }

    constexpr void operator-=(size_t n) {
        m_ptr -= n;
    }

    [[nodiscard]] constexpr reference operator[](size_t n) {
        return m_ptr[n];
    }

    friend constexpr bool operator==(const _string_view_iterator& v1, const _string_view_iterator& v2) {
        return v1.m_ptr == v2.m_ptr;
    }

    friend constexpr bool operator<=>(const _string_view_iterator& v1, const _string_view_iterator& v2) {
        if (v1.m_ptr > v2.m_ptr) {
            return 1;
        }
        else if (v1.m_ptr < v2.m_ptr) {
            return -1;
        }
        else {
            return 0;
        }
    }

    friend constexpr size_t operator-(const _string_view_iterator& v1, const _string_view_iterator& v2) {
        return v1.m_ptr - v2.m_ptr;
    }

    pointer m_ptr = nullptr;
};

namespace mylib {
    template<class Elem,class Traits = std::char_traits<Elem>> 
    class basic_string_view {
    public:

        using traits_type            = Traits;
        using value_type             = Elem;
        using pointer                = Elem*;
        using const_pointer          = const Elem*;
        using reference              = Elem&;
        using const_reference        = const Elem&;
        using const_iterator         = _string_view_iterator<Traits>;
        using iterator               = const_iterator;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
        using reverse_iterator       = const_reverse_iterator;
        using size_type              = size_t;
        using difference_type        = ptrdiff_t;

        static constexpr auto npos{ static_cast<size_type>(-1) };

        constexpr basic_string_view() noexcept : m_data(nullptr), m_size(0) {}

        constexpr basic_string_view(const basic_string_view&) noexcept = default;

        constexpr basic_string_view(const const_pointer Ntcts) noexcept : m_data(Ntcts), m_size(Traits::length(Ntcts)) {}

        constexpr basic_string_view(const const_pointer Cts, const size_type Count) noexcept : m_data(Cts), m_size(Count) {}

        template <std::contiguous_iterator It, std::sized_sentinel_for<It> Se>
            requires (std::is_same_v<std::iter_value_t<It>, Elem> && !std::is_convertible_v<Se, size_type>)
        constexpr basic_string_view(It First, Se Last) noexcept(noexcept(Last - First)) 
            : m_data(std::to_address(First)), m_size(static_cast<size_type>(Last - First)) {}

        constexpr basic_string_view(const std::string& s) : m_data(s.data()), m_size(s.size()) {}

        constexpr basic_string_view& operator=(const basic_string_view&) noexcept = default;

        constexpr const_iterator begin() const noexcept {
            return { m_data };
        }

        constexpr const_iterator cbegin() const noexcept {
            return  { m_data };
        }

        constexpr const_iterator end() const noexcept {
            return { m_data + m_size };
        }

        constexpr const_iterator cend() const noexcept {
            return { m_data + m_size };
        }

        constexpr const_reverse_iterator rbegin() const noexcept {
            return reverse_iterator(end());
        }
        
        constexpr const_reverse_iterator crbegin() const noexcept {
            return reverse_iterator(end());
        }

        constexpr const_reverse_iterator rend() const noexcept {
            return reverse_iterator(begin());
        }
        
        constexpr const_reverse_iterator crend() const noexcept {
            return reverse_iterator(begin());
        }
        
        constexpr const_reference at(size_type pos) const {
            pos >= size() ? throw  std::out_of_range("out_of_range") : begin()[pos];
        }

        constexpr const_reference operator[](size_type pos) const {
            return begin()[pos];
        }

        constexpr const_reference front() const {
            return *begin();
        }

        constexpr const_reference back() const {
            return *(end() - 1);
        }

        constexpr const_pointer data() const noexcept {
            return m_data;
        }

        constexpr size_type size()const noexcept {
            return m_size;
        }

        constexpr size_type length() const noexcept {
            return m_size;
        }

        constexpr size_type max_size() const noexcept {
            return std::min(static_cast<size_t>(PTRDIFF_MAX), static_cast<size_t>(-1) / sizeof(Elem));
        }

        [[nodiscard]] constexpr bool empty() const noexcept {
            return m_size == 0;
        }

        constexpr void remove_prefix(size_type n) {
            m_data += n;
            m_size -= n;
        }

        constexpr void remove_suffix(size_type n) {
            m_size -= n;
        }

        constexpr void swap(basic_string_view& v) noexcept {
            std::swap(m_data, v.m_data);
            std::swap(m_size, v.m_size);
        }

        constexpr size_type copy(Elem* dest, size_type count, size_type pos = 0) const {
            if (pos > size()) {
                throw std::out_of_range("out_of_range");
            }
            Traits::copy(dest, data() + pos, std::min(count, size() - pos));
            return count;
        }

        constexpr basic_string_view substr(size_type pos = 0, size_type count = npos) const {
            return { m_data + pos, std::min(count, size() - pos) };
        }

        constexpr int compare(basic_string_view v) const noexcept {
            auto ret = Traits::compare(data(), v.data(), std::min(size(), v.size()));
            if (ret < 0) {
                return -1;
            }
            else if (ret == 0) {
                if (size() < v.size()) { return -1; }
                if (size() == v.size()){return 0;}
                if (size() > v.size()) { return 1; }
            }
            else if (ret > 0) {
                return 1;
            }
            return 0;
        }

        constexpr int compare(size_type pos1, size_type count1, basic_string_view v) const {
            return substr(pos1, count1).compare(v);
        }

        constexpr int compare(size_type pos1, size_type count1, basic_string_view v, size_type pos2, size_type count2) const {
            return substr(pos1, count1).compare(v.substr(pos2, count2));
        }

        constexpr int compare(const Elem* s) const {
            return compare(basic_string_view(s));
        }

        constexpr int compare(size_type pos1, size_type count1, const Elem* s) const {
            return substr(pos1, count1).compare(basic_string_view(s));
        }

        constexpr int compare(size_type pos1, size_type count1, const Elem* s, size_type count2) const {
            return substr(pos1, count1).compare(basic_string_view(s, count2));
        }

        constexpr bool starts_with(basic_string_view sv) const noexcept {
            return substr(0, sv.size()) == sv;
        }

        constexpr bool starts_with(Elem c) const noexcept {
            return !empty() && Traits::eq(front(), c);
        }

        constexpr bool starts_with(const Elem* s) const {
            return starts_with(basic_string_view(s));
        }

        constexpr bool ends_with(basic_string_view sv) const noexcept {
            return size() >= sv.size() && compare(size() - sv.size(), npos, sv) == 0;
        }

        constexpr bool ends_with(Elem c) const noexcept {
            return !empty() && Traits::eq(back(), c);
        }

        constexpr bool ends_with(const Elem* s) const {
            return ends_with(basic_string_view(s));
        }

        constexpr size_type find(basic_string_view v, size_type pos = 0) const noexcept {
            return std::search(begin() + pos , end(), v.begin(), v.end()) - begin();
        }

        constexpr size_type find(Elem ch, size_type pos = 0) const noexcept {
            return find(basic_string_view(std::addressof(ch), 1), pos);
        }

        constexpr size_type find(const Elem* s, size_type pos, size_type count) const {
            return find(basic_string_view(s, count), pos);
        }

        constexpr size_type find(const Elem* s, size_type pos = 0) const {
            return find(basic_string_view(s), pos);
        }
        
        constexpr size_type rfind(basic_string_view v, size_type pos = 0) const noexcept {
            return std::find_end(begin() + pos, end(), v.begin(), v.end()) - begin();
        }

        constexpr size_type rfind(Elem ch, size_type pos = 0) const noexcept {
            return rfind(basic_string_view(std::addressof(ch), 1), pos);
        }

        constexpr size_type rfind(const Elem* s, size_type pos, size_type count) const {
            return rfind(basic_string_view(s, count), pos);
        }

        constexpr size_type rfind(const Elem* s, size_type pos = 0) const {
            return rfind(basic_string_view(s), pos);
        }

        constexpr size_type find_first_of(basic_string_view v, size_type pos = 0) const noexcept {
            for (const auto& i : v) {
                auto t = std::find(begin() + pos , end(), i);
                if (t != end()) {
                    return t - begin();
                }
            }
            return pos;
        }
    
        constexpr size_type find_first_of(Elem c, size_type pos = 0) const noexcept {
            return find_first_of(basic_string_view(std::addressof(c), 1), pos);
        }
    
        constexpr size_type find_first_of(const Elem* s, size_type pos, size_type count) const {
            return find_first_of(basic_string_view(s, count), pos);
        }
    
        constexpr size_type find_first_of(const Elem* s, size_type pos = 0) const {
            return find_first_of(basic_string_view(s), pos);
        }

        constexpr size_type find_last_of(basic_string_view v, size_type pos = npos) const noexcept {
            size_type ret{};
            for (const auto& i : v) {
                auto t = std::find(begin() + pos, end(), i);
                if (t != end()) {
                    ret = t - begin();
                }
            }
            return ret != 0 ? ret : pos;
        }
        
        constexpr size_type find_last_of(Elem c, size_type pos = npos) const noexcept {
            return find_last_of(basic_string_view(std::addressof(c), 1), pos);
        }
        
        constexpr size_type find_last_of(const Elem* s, size_type pos, size_type count) const {
            return find_last_of(basic_string_view(s, count), pos);
        }
        
        constexpr size_type find_last_of(const Elem* s, size_type pos = npos) const {
            return find_last_of(basic_string_view(s), pos);
        }

        constexpr size_type find_first_not_of(basic_string_view v, size_type pos = 0) const noexcept {
            for (const auto& i : v) {
                auto t = std::find(begin() + pos , end(), i);
                if (t == end()) {
                    return  t - begin();
                }
            }
            return npos;
        }

        constexpr size_type find_first_not_of(Elem c, size_type pos = 0) const noexcept {
            return find_first_not_of(basic_string_view(c), pos);
        }

        constexpr size_type find_first_not_of(const Elem* s, size_type pos, size_type count) const {
            return find_first_not_of(basic_string_view(s, count), pos);
        }

        constexpr size_type find_first_not_of(const Elem* s, size_type pos = 0) const noexcept {
            return find_first_not_of(basic_string_view(s), pos);
        }

        constexpr size_type find_last_not_of(basic_string_view v, size_type pos = npos) const noexcept {
            size_type ret{};
            for (const auto& i : v) {
                auto t = std::find(begin() + pos , end(), i);
                if (t == end()) {
                    ret =  t - begin();
                }
            }
            return ret != 0 ? ret : pos;
        }
        
        constexpr size_type find_last_not_of(Elem c, size_type pos = npos) const noexcept {
            return find_last_not_of(basic_string_view(std::addressof(c), 1), pos);
        }
        
        constexpr size_type find_last_not_of(const Elem* s, size_type pos, size_type count) const {
            return find_last_not_of(basic_string_view(s, count), pos);
        }
        
        constexpr size_type find_last_not_of(const Elem* s, size_type pos = npos) const {
            return find_last_not_of(basic_string_view(s), pos);
        }
        
    private:
        
        const_pointer m_data;
        size_type m_size;
    };
    
    using string_view    = mylib::basic_string_view<char>;
    using wstring_view   = mylib::basic_string_view<wchar_t>;
    using u8string_view  = mylib::basic_string_view<char8_t>;
    using u16string_view = mylib::basic_string_view<char16_t>;
    using u32string_view = mylib::basic_string_view<char32_t>;

    template< class CharT, class Traits >
    constexpr bool operator==(mylib::basic_string_view<CharT, Traits> lhs,mylib::basic_string_view<CharT, Traits> rhs) noexcept {
        return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template< class CharT, class Traits >
    constexpr auto operator<=>(mylib::basic_string_view<CharT, Traits> lhs, mylib::basic_string_view<CharT, Traits> rhs) noexcept {
        return lhs.compare(rhs);
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const mylib::basic_string_view<T>& v) {
        for (const auto& i : v) {
            std::cout << i;
        }
        return out;
    }

    constexpr string_view operator "" _sv(const char* str, std::size_t len) noexcept {
        return { str,len };
    }		  
              
    constexpr u8string_view operator "" _sv(const char8_t* str, std::size_t len) noexcept {
        return { str,len };
    }		  
              
    constexpr u16string_view operator "" _sv(const char16_t* str, std::size_t len) noexcept {
        return { str,len };
    }		  
              
    constexpr u32string_view operator "" _sv(const char32_t* str, std::size_t len) noexcept {
        return { str,len };
    }		  
              
    constexpr wstring_view operator "" _sv(const wchar_t* str, std::size_t len) noexcept {
        return { str,len };
    }

    template<class It, class End>
    basic_string_view(It, End)->basic_string_view<std::iter_value_t<It>>;

}

#endif