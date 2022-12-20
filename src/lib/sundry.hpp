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

	template<typename T, typename M = std::mutex>
	class singleton
	{
		inline static M mutex{};
		inline static T object;

		struct lock_with_life
		{
			std::lock_guard<M> lock;
			T& object;
			lock_with_life(M& m, T& value) :lock{ m }, object{ value } {}
		};

		singleton() = delete;
	public:

		static auto get()
		{
			return lock_with_life{ mutex,object };
		}
	};

	struct clog {
		template<typename T, typename M>
		friend class singleton;
		inline static std::mutex m;
		std::unique_lock<std::mutex> loc;

		template<class T>
		clog& operator <<(const T& message) {
			std::cout << message;
			return *this;
		}
		clog& operator <<(std::ostream& (*fp)(std::ostream&)) {
			std::cout << fp;
			return *this;
		}

	private:
		clog() :loc{ m } {}
	};


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

	template<size_t...I>
	size_t max(std::index_sequence<I...>) {
		return std::max({ I... });
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

	template<class F, class Ptr = void*>
	struct function {
		function() = delete;
		function(F f) {
			this->func = f;
			this->p = nullptr;
		}
		function(F func, Ptr p) {
			this->func = func;
			this->p = p;
		}
		template<class...Args>
			requires (std::regular_invocable<F, Args...> && (std::is_pointer_v<F> || std::is_class_v<F>))
		auto operator()(Args&&...args) {
			return func(args...);
		}
		template<class...Args>
			requires requires (F func, Ptr p, Args&&...args) { (p->*func)(args...); }
		auto operator()(Args&&...args) {
			return (p->*func)(args...);
		}
	private:
		F func;
		Ptr p;
	};

	consteval std::pair<int, int>minmax(std::vector<int>vec) {
		std::ranges::sort(vec);
		return { vec.front(),vec.back() };
	}

	template<class...Args, class Type = std::common_type_t<Args...>>
	auto minmax(Args&& ...args) -> std::pair<Type, Type> {
		std::vector vec{ std::forward<Type>(args)... };
		auto max = std::ranges::max(vec);
		auto min = std::ranges::min(vec);
		return { min,max };
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

	struct A {
		constexpr A(const char* s)noexcept :str(s) {}
		const char* str;
	};

	inline namespace literals {

		template<A a>
		constexpr auto operator""_f() {
			return[=]<typename... T>(T... Args) { return std::format(a.str, Args...); };
		}

	}

	template<typename T>
	struct type_name {
		inline static std::string name{ typeid(T).name() };
	};
	template<typename T>
	struct type_name<T&&> {
		inline static std::string name{ "{}&&"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<T&> {
		inline static std::string name{ "{}&"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<const T> {
		inline static std::string name{ "const {}"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<const T&> {
		inline static std::string name{ "const {}&"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<const T&&> {
		inline static std::string name{ "const {}&&"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<volatile T> {
		inline static std::string name{ "volatile {}"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<volatile T&> {
		inline static std::string name{ "volatile {}&"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<volatile T&&> {
		inline static std::string name{ "volatile {}&&"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<const volatile T> {
		inline static std::string name{ "const volatile {}"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<const volatile T&> {
		inline static std::string name{ "const volatile {}&"_f(typeid(T).name()) };
	};
	template<typename T>
	struct type_name<const volatile T&&> {
		inline static std::string name{ "const volatile {}&&"_f(typeid(T).name()) };
	};

	template<typename T>
	inline std::string type_name_v = type_name<T>::name;
	
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
			delete[] buffer;
		}
	}
	
}
#define STD       ::std::
#define LOG	      ::my::singleton<my::clog>::get().object

namespace stdr   = ::std::ranges;
namespace stdv   = ::std::views;
namespace stdf   = ::std::filesystem;
namespace stdl   = ::std::literals;
namespace stdc   = ::std::chrono;
namespace stdp   = ::std::pmr;
namespace stde   = ::std::experimental;
namespace my     = ::mylib;
namespace mylibf = ::mylib::file;

using namespace my::literals;
using namespace std::literals;

#endif // !__SUNDRY_HPP__
