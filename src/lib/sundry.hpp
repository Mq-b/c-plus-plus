#ifndef __SUNDRY_HPP__
#define __SUNDRY_HPP__

#include"mylib.h"
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
			return f(std::forward<Args>(args)...);
		};
	}

	template<class ...Args, class F>requires std::is_class_v<F>
	inline auto bind(F f, Args&&...args) {
		return [=]()mutable
		{
			return f(std::forward<Args>(args)...);
		};
	}

}

#endif // !__SUNDRY_HPP__
