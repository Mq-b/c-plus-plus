#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include<iterator>
#include<type_traits>
#include<utility>
#include<memory>
#include<initializer_list>
#include<algorithm>
#include<numeric>
#include<execution>
#include<limits>
#include<iostream>
#include<ranges>

namespace mylib {

	template<typename Ty>
	struct _vector_iterator {
		using value_type = std::remove_cv_t<Ty>;
		using pointer = Ty*;
		using reference = Ty&;

		[[nodiscard]] constexpr reference operator*()const noexcept {
			return *_ptr;
		}

		[[nodiscard]] constexpr pointer operator->()const noexcept {
			return _ptr;
		}

		[[nodiscard]] constexpr _vector_iterator& operator++()noexcept {
			++_ptr;
			return *this;
		}

		constexpr _vector_iterator operator++(int)noexcept {
			_vector_iterator tmp{ *this };
			++* this;
			return tmp;
		}

		constexpr _vector_iterator& operator--()noexcept {
			--_ptr;
			return *this;
		}

		constexpr _vector_iterator operator--(int)noexcept {
			_vector_iterator tmp{ *this };
			--* this;
			return tmp;
		}

		[[nodiscard]] constexpr _vector_iterator operator+(size_t n)const noexcept {
			_vector_iterator tmp{ *this };
			tmp._ptr += n;
			return tmp;
		}

		[[nodiscard]] constexpr _vector_iterator operator-(size_t n)const noexcept {
			_vector_iterator tmp{ *this };
			tmp._ptr -= n;
			return tmp;
		}

		[[nodiscard]] constexpr void operator+=(size_t n) {
			_ptr += n;
		}

		[[nodiscard]] constexpr void operator-=(size_t n) {
			_ptr -= n;
		}

		[[nodiscard]] constexpr reference operator[](size_t n) {
			return _ptr[n];
		}

		friend constexpr bool operator==(const _vector_iterator& v1, const _vector_iterator& v2) {
			return v1._ptr == v2._ptr;
		}

		friend constexpr bool operator<=>(const _vector_iterator& v1, const _vector_iterator& v2) {
			if (v1._ptr > v2._ptr) {
				return 1;
			}
			else if (v1._ptr < v2._ptr) {
				return -1;
			}
			else {
				return 0;
			}
		}

		friend constexpr size_t operator-(const _vector_iterator& v1, const _vector_iterator& v2) {
			return v1._ptr - v2._ptr;
		}

		pointer _ptr = nullptr;

	};

	template<typename Ty, typename Alloc = std::allocator<Ty>>
	class vector {
	public:

		using value_type				= Ty;
		using allocator_type			= Alloc;
		using size_type					= std::allocator_traits<Alloc>::size_type;
		using difference_type			= std::allocator_traits<Alloc>::difference_type;
		using reference					= value_type&;
		using const_reference			= const value_type&;
		using pointer					= std::allocator_traits<Alloc>::pointer;
		using const_pointer				= std::allocator_traits<Alloc>::const_pointer;
		using iterator					= _vector_iterator<Ty>;
		using const_iterator			= const _vector_iterator<Ty>;
		using reverse_iterator			= std::reverse_iterator<iterator>;
		using const_reverse_iterator	= std::reverse_iterator<const_iterator>;

		constexpr vector() noexcept(noexcept(Alloc())) :_size{ 0 }, _capacity{ 0 }, _ptr{ nullptr } {}

		explicit vector(size_t init_size ) :_size{ init_size }, _capacity{ 0 }, _ptr{ nullptr } {
			reserve(init_size);
		}
		vector(const vector& rhs) :_size{ rhs._size }, _capacity{ 0 }, _ptr{ nullptr } {
			reserve(rhs.capacity());
			std::copy(rhs.cbegin(), rhs.cend(), begin());
		}

		constexpr vector(size_type count, value_type value) : _size{ 0 }, _capacity{ 0 }, _ptr{ nullptr } {
			assign(count, value);
		}

		template< class InputIt, std::enable_if_t<std::_Is_iterator_v<InputIt>, int> = 0>
		constexpr vector(InputIt first, InputIt last) : _size{ 0 }, _capacity{ 0 }, _ptr{ nullptr } {
			difference_type dis = std::distance(first, last);
			reserve(dis);
			std::copy(first, last ,begin());
			_size = dis;
		}

		constexpr vector(std::initializer_list<size_type> init) : _size(init.size()), _capacity{ 0 }, _ptr{ nullptr } {
			reserve(init.size());
			std::copy(init.begin(), init.end(), begin());
		}

		constexpr ~vector() {
			_allocator.deallocate(_ptr, _capacity);
		}

		constexpr vector& operator=(const vector& other) {
			reserve(other.capacity());
			_size = other.size();
			std::copy(other.cbegin(), other.cend(), begin());
			return *this;
		}

		constexpr vector& operator=(vector&& other) {
			reserve(other.capacity());
			_size = other.size();
			std::copy(other.begin(), other.end(), begin());
			return *this;
		}

		template<typename T>
		constexpr vector& operator=(std::initializer_list<T> ilist) {
			reserve(ilist.size());
			_size = ilist.size();
			std::copy(ilist.begin(), ilist.end(), begin());
			return *this;
		}

		template<typename T>
		constexpr void assign(size_type count, const T& value) {
			reserve(count);
			_size = count;
			std::fill(begin(), begin() + count, value);
		}

		template< class InputIt, std::enable_if_t<std::_Is_iterator_v<InputIt>, int> = 0>
		constexpr void assign(InputIt first, InputIt last) {
			ptrdiff_t di = std::distance(first, last);
			reserve(di);
			_size = di;
			std::copy(first, last, begin());
		}

		template<typename T>
		constexpr void assign(std::initializer_list<T> ilist) {
			reserve(ilist.size());
			_size = ilist.size();
			std::copy(ilist.begin(), ilist.end(), begin());
		}

		[[nodiscard]] constexpr allocator_type get_allocator() const noexcept {
			return _allocator;
		}

		[[nodiscard]] constexpr reference at(size_type pos) {
			return !(pos < _size) ? throw std::out_of_range : _ptr[pos];
		}
		[[nodiscard]] constexpr const_reference at(size_type pos) const {
			return !(pos < _size) ? throw std::out_of_range("out_of_range") : _ptr[pos];
		}

		[[nodiscard]] constexpr reference operator[](size_type pos) {
			return _ptr[pos];
		}

		[[nodiscard]] constexpr const_reference operator[](size_type pos) const {
			return _ptr[pos];
		}

		[[nodiscard]] constexpr reference front() {
			return _ptr[0];
		}

		[[nodiscard]] constexpr const_reference front() const {
			return _ptr[0];
		}

		[[nodiscard]] constexpr const_reference back() const {
			return _ptr[_size - 1];
		}

		[[nodiscard]] constexpr reference back() {
			return _ptr[_size - 1];
		}

		[[nodiscard]] constexpr pointer data() noexcept {
			return _ptr;
		}

		[[nodiscard]] constexpr const_pointer data()const noexcept {
			return _ptr;
		}

		[[nodiscard]] constexpr iterator begin()noexcept{
			return { _ptr };
		}

		[[nodiscard]] constexpr const_iterator cbegin()const noexcept {
			return { _ptr };
		}

		[[nodiscard]] constexpr reverse_iterator rbegin()noexcept {
			return reverse_iterator(end());
		}

		[[nodiscard]] constexpr reverse_iterator crbegin()noexcept {
			return reverse_iterator(cend());
		}

		[[nodiscard]] constexpr iterator end()noexcept {
			return { _ptr + _size };
		}

		[[nodiscard]] constexpr const_iterator cend()const noexcept {
			return { _ptr + _size };
		}

		[[nodiscard]] constexpr reverse_iterator rend()noexcept {
			return reverse_iterator(begin());
		}

		[[nodiscard]] constexpr const_reverse_iterator crend()noexcept {
			return reverse_iterator(cbegin());
		}

		[[nodiscard]] constexpr bool empty() const noexcept {
			return begin() == end();
		}

		[[nodiscard]] constexpr size_type size() const noexcept {
			return _size;
		}

		[[nodiscard]] constexpr size_type max_size() const noexcept {
			return std::numeric_limits<difference_type>::max();
		}

		[[nodiscard]] constexpr size_type capacity() const noexcept {
			return _capacity;
		}

		constexpr void reserve(size_type new_cap) {
			if (new_cap <= capacity())
				return;
			pointer tmp = _ptr;
			_ptr = _allocator.allocate(new_cap);
			_init_construct(new_cap);
			if (_ptr != nullptr && tmp != nullptr) {
				std::copy(tmp, tmp + size(), _ptr);
				_allocator.deallocate(tmp, _capacity);
			}
			_capacity = new_cap;
		}

		constexpr void shrink_to_fit() {
			_capacity = _size;
		}

		constexpr void clear() noexcept {
			_size = 0;
		}

		template<typename T>
		constexpr iterator insert(const_iterator pos, const T& value) {
			auto p = emplace(pos, std::move(value));
			return p;
		}

		template<typename T>
		constexpr iterator insert(const_iterator pos, T&& value) {
			auto p = emplace(pos, std::forward<T>(value));
			return p;
		}

		template<typename T>
		constexpr iterator	insert(const_iterator pos, size_type count, const T& value) {
			if (count == 0) {
				return pos;
			}
			std::ptrdiff_t dis = std::distance(cbegin(), pos);
			reserve(capacity() * 1.5 + count);

			std::copy(cbegin() + dis, cend(), cbegin() + dis + count);

			std::fill(_ptr + dis, _ptr + dis + count, value);

			_size += count;
			return { _ptr + dis };
		}

		template< class InputIt >
		constexpr iterator insert(const_iterator pos, InputIt first, InputIt last) {
			if (std::distance(first, last) == 0) {
				return pos;
			}
			std::ptrdiff_t dis = std::distance(cbegin(), pos);
			std::ptrdiff_t count = std::distance(first, last);
			reserve(capacity() * 1.5 + count);

			std::copy(cbegin() + dis, cend(), cbegin() + dis + count);

			std::copy(first, last, cbegin() + dis);

			_size += count;
			return { _ptr + dis };
		}

		template<typename T>
		constexpr iterator insert(const_iterator pos,std::initializer_list<T> ilist) {
			return insert(pos, ilist.begin(), ilist.end());
		}

		constexpr void push_back(const value_type& value) {
			if (size() + 1 <= capacity()) {
				_ptr[size()] = std::move(value);
			}else {
				reserve(capacity() * 1.5 + 1);
				_ptr[size()] = std::move(value);
			}
			_size += 1;
		}

		constexpr void push_back(value_type&& value) {
			if (size() + 1 <= capacity()) {
				_ptr[size()] = std::move(value);
			}else {
				reserve(capacity() * 1.5 + 1);
				_ptr[size()] = std::move(value);
			}
			_size += 1;
		}

		template< class... Args >
		constexpr iterator emplace(const_iterator pos, Args&&... args) {
			std::ptrdiff_t dis = cend() - pos - 1;
			if (dis == size()) {
				emplace_back(std::forward<Args>(args)...);
				return begin() + size();
			}
			dis = std::distance(cbegin(), pos);
			reserve(capacity() * 1.5 + 1);
			
			std::copy(cbegin() + dis, cend(), cbegin() + dis + 1);
			
			_ptr[dis] = { std::forward<Args>(args)... };

			_size += 1;
			return { _ptr + dis };
		}

		constexpr iterator erase(const_iterator pos) {
			std::ptrdiff_t dis = std::distance(cbegin(), pos);
			std::copy(cbegin() + dis + 1 , cend(), cbegin() + dis);
			_size -= 1;
			return { _ptr + dis };
		}

		constexpr iterator erase(const_iterator first, const_iterator last) {
			std::ptrdiff_t dis = std::distance(cbegin(), first);
			std::ptrdiff_t count = std::distance(first, last);
			if (count == 0) {
				return last;
			}
			std::copy(cbegin() + dis + count, cend(), cbegin() + dis);
			_size -= count;
			return { _ptr + dis };
		}

		template< class... Args >
		constexpr reference emplace_back(Args&&... args) {
			push_back(std::forward<Args>(args)...);
			return _ptr[_size];
		}

		constexpr void pop_back() {
			_size--;
		}

		constexpr void resize(size_type count) {
			reserve(count);
			_size = count;
		}

		constexpr void resize(size_type count, const value_type& value) {
			resize(count);
			std::fill(end() - count, end(), value);;
		}

		constexpr void swap(vector& other) noexcept {
			std::swap(_size, other._size);
			std::swap(_capacity, other._capacity);
			std::swap(_ptr, other._ptr);
		}

	private:

		constexpr void _init_construct(size_type n) {
			for (size_t i = 0; i < n; i++) {
				::new(&_ptr[i]) value_type;
			}
		}

		pointer _ptr;
		size_type _size;
		size_type _capacity;
		allocator_type _allocator;
	};

	template< class T, class Alloc >
	constexpr bool operator==(const mylib::vector<T, Alloc>& lhs, const mylib::vector<T, Alloc>& rhs) {
		auto ret = std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin());
		if (ret && lhs.size() == rhs.size()) {
			return true;
		}else {
			return false;
		}
	}

	template< class T, class Alloc >
	constexpr auto operator<=>(const mylib::vector<T, Alloc>& lhs, const mylib::vector<T, Alloc>& rhs) {
		if (lhs.size() < rhs.size()) {
			return std::partial_ordering::less;
		}
		else if (lhs.size() > rhs.size()) {
			return std::partial_ordering::greater;
		}else {
			if (std::lexicographical_compare(lhs.cbegin(),lhs.cend(), rhs.cbegin(),rhs.cend()) == true) {
				return std::partial_ordering::less;
			}else {
				return std::partial_ordering::greater;
			}
		}
	}

	template< class T, class Alloc >
	constexpr void swap(mylib::vector<T, Alloc>& lhs, mylib::vector<T, Alloc>& rhs) noexcept {
		lhs.swap(rhs);
	}

	template< class T, class Alloc, class U >
	constexpr typename mylib::vector<T, Alloc>::size_type erase(mylib::vector<T, Alloc>& c, const U& value) {

	}

	template<typename Ty>
	vector(std::initializer_list<Ty>)->vector<Ty>;

	template<typename InputIt>
	vector(InputIt first, InputIt last)->vector<typename std::iterator_traits<InputIt>::value_type>;

}
#endif // !__VECTOR_HPP__