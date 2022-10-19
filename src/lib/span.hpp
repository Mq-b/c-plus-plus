#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include<type_traits>
#include<iterator>

template<typename T,typename Ty>
auto address(const Ty& v) {
	return  const_cast<T*>(std::data(v));
}

template<typename Ty>
struct span_iterator {
	using value_type	= std::remove_cv_t<Ty>;
	using pointer		= Ty*;
	using reference		= Ty&;

	constexpr reference operator*()const noexcept {
		return *_ptr;
	}

	constexpr pointer operator->()const noexcept {
		return _ptr;
	}

	constexpr span_iterator& operator++()noexcept {
		++_ptr;
		return *this;
	}

	constexpr span_iterator operator++(int)noexcept {
		span_iterator tmp{ *this };
		++*this;
		return tmp;
	}

	constexpr span_iterator& operator--()noexcept {
		--_ptr;
		return *this;
	}

	constexpr span_iterator operator--(int)noexcept {
		span_iterator tmp{ *this };
		--* this;
		return tmp;
	}

	constexpr span_iterator operator+(size_t n)noexcept {
		span_iterator tmp{ *this };
		++tmp;
		return tmp;
	}

	constexpr span_iterator operator-(size_t n)noexcept {
		span_iterator tmp{ *this };
		--tmp;
		return tmp;
	}

	friend constexpr bool operator==(const span_iterator& v1, const span_iterator& v2) {
		return v1._ptr == v2._ptr;
	}

	friend constexpr bool operator!=(const span_iterator& v1, const span_iterator& v2) {
		return !(v1 == v2);
	}

	pointer _ptr   = nullptr;
	pointer _begin = nullptr;
	pointer _end   = nullptr;
};

template<typename Ty>
class span {
public:

	using element_type             =	Ty;
	using size_type                = size_t;
	using pointer                  =	Ty*;
	using const_pointer            = const Ty*;
	using reference                = Ty&;
	using const_reference          = const Ty&;
	using iterator                 = span_iterator<Ty>;
	using reverse_iterator         = std::reverse_iterator<iterator>;

	constexpr span()noexcept :_ptr{ nullptr }, _size(0) {}

	template<typename T>
	constexpr span(const T& v)noexcept :_ptr{ address<Ty>(v)}, _size{std::size(v)} {}

	constexpr span(const span& v)noexcept = default;

	constexpr span(pointer ptr, size_type size) :_ptr{ ptr }, _size{ size } {}

	constexpr span& operator=(const span& other) noexcept = default;

	constexpr iterator begin()const noexcept {
		return { _ptr,_ptr,_ptr + _size };
	}

	constexpr iterator end()const noexcept {
		const auto End = _ptr + _size;
		return { End,_ptr,End };
	}

	constexpr reverse_iterator rbegin()const noexcept {
		return reverse_iterator{ end() };
	}

	constexpr reverse_iterator rend()const noexcept {
		return reverse_iterator{ begin() };
	}

	constexpr reference front() const {
		return *begin();
	}

	constexpr reference back() const {
		return *(end() - 1);
	}

	constexpr reference operator[](size_type idx) const {
		return _ptr[idx];
	}

	constexpr const_pointer data()const noexcept {
		return _ptr;
	}

	constexpr size_type size()const noexcept { 
		return _size; 
	}

	constexpr size_type size_types()const noexcept {
		return size() * sizeof(element_type);
	}

	constexpr bool empty()const noexcept {
		return _size == 0;
	}

	constexpr span first() const {
		return *this;
	}

	constexpr span first(const size_type Count) const {
		return { _ptr, Count };
	}

	constexpr span last() const {
		return {_ptr+_size,_size};
	}

	constexpr span last(const size_type Count) const {
		return { _ptr + Count, _size - Count };
	}

	constexpr span subspan(std::size_t Offset, std::size_t Count = 0) {
		return { _ptr + Offset,Count == 0 ? _size - Offset : Count };
	}

private:
	pointer _ptr;
	std::size_t _size;
};

#endif // __SPAN_HPP
