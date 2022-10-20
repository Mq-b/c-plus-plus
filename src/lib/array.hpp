#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include<type_traits>
#include<iterator>
#include<execution>
#include<string>
#include<algorithm>
#include<numeric>
#include<array>
#include<utility>

namespace mylib {

	struct out_of_range :std::exception
	{
		out_of_range(const std::string& s) :exception(s.data()) {}//没必要重写what方法，无所谓，看需求即可，不知道怎么写就看源码实现
	};

	template<class Ty, size_t Size>
	class array {
	public:
		using value_type = Ty;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using pointer = Ty*;
		using const_pointer = const Ty*;
		using reference = Ty&;
		using const_reference = const Ty&;
		using iterator = value_type*;
		using const_iterator = const value_type*;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		[[nodiscard]] constexpr reference at(size_type pos) {
			return  !(pos < Size) ? throw out_of_range("Array access error") : _elems[pos];
		}

		[[nodiscard]] constexpr const_reference at(size_type pos)const {
			return  !(pos < Size) ? throw out_of_range("Array access error") : _elems[pos];
		}

		[[nodiscard]] constexpr reference operator[](size_type pos) {
			return _elems[pos];
		}

		[[nodiscard]] constexpr const_reference operator[](size_type pos)const {
			return _elems[pos];
		}

		[[nodiscard]] constexpr reference front()noexcept {
			return _elems[0];
		}

		[[nodiscard]] constexpr const_reference front()const noexcept {
			return _elems[0];
		}

		[[nodiscard]] constexpr reference back()noexcept {
			return _elems[Size - 1];
		}

		[[nodiscard]] constexpr const_reference back()const noexcept {
			return _elems[Size - 1];
		}

		[[nodiscard]] constexpr pointer data()noexcept {
			return _elems;
		}

		[[nodiscard]] constexpr const_pointer data()const noexcept {
			return _elems;
		}

		[[nodiscard]] constexpr iterator begin()noexcept {
			return _elems;
		}

		[[nodiscard]] constexpr const_iterator begin()const noexcept {
			return _elems;
		}

		[[nodiscard]] constexpr iterator end()noexcept {
			return _elems + Size;
		}

		[[nodiscard]] constexpr const_iterator end()const noexcept {
			return _elems + Size;
		}

		[[nodiscard]] constexpr reverse_iterator rbegin()noexcept {
			return reverse_iterator(end());
		}

		[[nodiscard]] constexpr const_reverse_iterator rbegin()const noexcept {
			return const_reverse_iterator(end());
		}

		[[nodiscard]] constexpr reverse_iterator rend()noexcept {
			return reverse_iterator(begin());
		}

		[[nodiscard]] constexpr const_reverse_iterator rend()const noexcept {
			return const_reverse_iterator(begin());
		}

		[[nodiscard]] constexpr const_iterator cbegin()const noexcept {
			return begin();
		}

		[[nodiscard]] constexpr const_iterator cend()const noexcept {
			return end();
		}

		[[nodiscard]] constexpr const_reverse_iterator crbegin()const noexcept {
			return rbegin();
		}

		[[nodiscard]] constexpr const_reverse_iterator crend()const noexcept {
			return rend();
		}

		[[nodiscard]] constexpr bool empty()const noexcept {
			return Size;
		}

		[[nodiscard]] constexpr size_type size()const noexcept {
			return Size;
		}

		[[nodiscard]] constexpr size_type max_size()const noexcept {
			return Size;
		}

		constexpr void fill(const Ty& value) {
			std::fill_n(_elems, Size, value);
		}

		constexpr void swap(array& other)noexcept(std::_Is_nothrow_swappable<Ty>::value) {
			std::swap(_elems,other._elems);
		}

		Ty _elems[Size];
	};

	template<std::size_t N,typename Ty>
	decltype(auto) get(const Ty& a) {
		return a[N];
	}

	template <class T, std::size_t N, std::size_t... I>
	constexpr mylib::array<std::remove_cv_t<T>, N>
		to_array_impl(T(&& a)[N], std::index_sequence<I...>)
	{
		return { {std::move(a[I])...} };
	}

	template <class T, std::size_t N>
	constexpr mylib::array<std::remove_cv_t<T>, N> to_array(T(&& a)[N])
	{
		return to_array_impl(std::move(a), std::make_index_sequence<N>{});
	}

	template<typename T,std::size_t N>
	constexpr mylib::array<std::remove_cv_t<T>, N>to_array(T(&a)[N]) {
		return to_array_impl(std::move(a), std::make_index_sequence<N>{});
	}

	template<typename Tp, typename... Up>
	array(Tp, Up...)->array<std::enable_if_t<(std::is_same_v<Tp, Up>&& ...), Tp>, 1 + sizeof...(Up)>;

}

#endif // __ARRAY_HPP__
