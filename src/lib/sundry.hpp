#ifndef __SUNDRY_HPP__
#define __SUNDRY_HPP__

#include<iostream>
#include<vector>
#include<list>
#include<bit>
#include<new>
#include<ranges>
#include<string_view>
#include<filesystem>
#include<chrono>
#include<string>
#include<array>
#include<memory>
#include<fstream>
#include<thread>
#include<algorithm>
#include<concepts>
#include <type_traits>

namespace mylib {

	template<typename T>
	struct _1 {
		using Type = T;

		constexpr _1(T v)noexcept :value{ v } {}

		constexpr operator Type()const noexcept {
			return value;
		}

		Type value;
	};

	template<class T>
	struct remove_reference {
		using type = T;
	};
	template<class T>
	struct remove_reference<T&> {
		using type = T;
	};
	template<class T>
	struct remove_reference<T&&> {
		using type = T;
	};

	template <class>
	constexpr bool is_lvalue_reference_v = false; 

	template <class Ty>
	constexpr bool is_lvalue_reference_v<Ty&> = true;

	template<class T>
	using remove_reference_t = typename remove_reference<T>::type;

	template<class T, class T2>
	struct is_same {
		static constexpr bool value = false;
	};
	template<class T>
	struct is_same<T, T> {
		static constexpr bool value = true;
	};
	template<class T, class T2>
	constexpr bool is_same_v = is_same<T, T2>::value;

	template<typename...Ts, typename Type = std::common_type_t<Ts...>>
	constexpr auto min(const Ts&... args)noexcept {
		return std::min({ static_cast<Type>(args)... }, std::less<>());
	}

	template<typename...Ts, typename Type = std::common_type_t<Ts...>>
	constexpr auto max(const Ts&... args)noexcept {
		return std::max({ static_cast<Type>(args)... }, std::less<>());
	}

	template<typename...Ts, typename Type = std::common_type_t<Ts...>>
	constexpr auto sum(const Ts&...args)noexcept {
		return (static_cast<Type>(args) + ...);
	}
	
	template<class ...Args,class F>requires std::is_pointer_v<F>
	inline auto bind(F f, Args&&...args) {
		return [=]()mutable
		{
			return f(forward<Args>(args)...);
		};
	}

	template<class ...Args, class F>requires std::is_class_v<F>
	inline auto bind(F f, Args&&...args) {
		return [=]()mutable
		{
			return f(forward<Args>(args)...);
		};
	}

	template<class...Args, class T, class A>requires (!std::is_class_v<A> && !std::is_pointer_v<A>)
	inline auto bind(A func, T f, Args...args) {
		return [=]()mutable
		{
			return (f->*func)(forward<Args>(args)...);
		};
	}

	template<class Ty>
	constexpr Ty&& forward(remove_reference_t<Ty>& Arg)noexcept {
		return static_cast<Ty&&>(Arg);
	}

	template<class Ty>//使用std::move匹配的版本
	constexpr Ty&& forward(remove_reference_t<Ty>&& Arg)noexcept {
		static_assert(!is_lvalue_reference_v<Ty>, "bad forward call");
		return static_cast<Ty&&>(Arg);
	}

	template <class Ty>
	constexpr remove_reference_t<Ty>&& move(Ty&& Arg) noexcept { 
		return static_cast<remove_reference_t<Ty>&&>(Arg);
	}

	template <class Ty>
	inline constexpr bool is_function_v = // only function types and reference types can't be const qualified
		!std::is_const_v<const Ty> && !std::is_reference_v<Ty>;

	struct A {
		constexpr A(const char* s)noexcept :str(s) {}
		const char* str;
	};

	template<typename T, typename F>
	concept erase_ = requires(T v, F f) {
		f(*v.begin());
	};

	template<typename T, typename F>
		requires erase_<T, F>
	void erase(T& v, F f) {
		for (auto i = v.begin(); i != v.end(); f(*i) ? i = v.erase(i) : i++);
	}
	
	template<typename U, typename F>
		requires std::regular_invocable<F, U&>
	std::vector<U>& operator | (std::vector<U>& vl, F f) {
		for (auto& i : vl) {
			f(i);
		}
		return vl;
	}

	namespace literals {

		template<A a>
		constexpr auto operator""_f() {
			return[=]<typename... T>(T... Args) { return std::format(a.str, Args...); };
		}

	}

	namespace file {
		//inline，防止违反ODR
		inline void copy(std::string_view read, std::string_view write) {
			std::ifstream ifs(read.data(), std::ios::binary | std::ios::in);
			std::ofstream ofs(write.data(), std::ios::binary | std::ios::out);

			if (!ifs.is_open() || !ofs.is_open())
			{
				std::cerr << "文件打开失败" << std::endl;
				throw std::runtime_error("文件打开失败");
			}
			char* buffer = new char[1024] {};
			std::streamsize len{};
			while (!ifs.eof()) {
				len = ifs.read(buffer, 1024).gcount();
				ofs.write(buffer, len);
			}
			ifs.close();
			ofs.close();
			delete buffer;
		}
	}
	
}

#endif // !__SUNDRY_HPP__
