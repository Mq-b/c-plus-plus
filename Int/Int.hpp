#ifndef __INT_HPP__
#define __INT_HPP__

#include<iostream>
#include<vector>
#include<string>

namespace mylib {

	/// <summary>
	/// Integer wrapper class
	/// </summary>
	template<std::integral Type>
	class Int{
	public:

		/// <summary>
		/// The friend function overload operator is used to print private data members.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="out"></param>
		/// <param name="v"></param>
		/// <returns></returns>
		template<std::integral T>
		friend std::ostream& operator<<(std::ostream& out, const Int<T>& v)noexcept;

		/// <summary>
		/// The template constructor constructs a literal type object. 
		/// Its data member type must be an integer type. 
		/// The exact type is derived from the argument to the calling constructor
		/// </summary>
		constexpr Int(Type v)noexcept;
		
		/// <summary>
		/// Define defines the conversion function (implicit conversion)
		/// </summary>
		/// <returns>type integer</returns>
		constexpr operator Type()const noexcept;
		
		/// <summary>
		/// To any integer type
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns>T m_value</returns>
		template<std::integral T>
		constexpr T toType()const noexcept;

	private:
		/// <summary>
		/// The only private data member
		/// </summary>
		Type m_value;
	};


	template<std::integral Type>
	constexpr inline Int<Type>::Int(Type v)noexcept {
		this->m_value = v;
	}

	template<std::integral T>
	std::ostream& operator<<(std::ostream& out, const Int<T>& v) noexcept {
		out << v.m_value;
		return out;
	}

	template<std::integral Type>
	constexpr inline Int<Type>::operator Type() const noexcept{
		return this->m_value;
	}

	template<std::integral Type>
	template<std::integral T>
	inline constexpr T mylib::Int<Type>::toType() const noexcept{
		return static_cast<T>(this->m_value);
	}

	/// <summary>
	/// Alias for the template class Int
	/// </summary>
	using uInt64 = Int<size_t>;
	using Int8 = Int<char>;


	namespace literal {

		/// <summary>
		/// The literal operator.
		/// Converts the literal of "_Int" to the size_t version of the Int template class.
		/// </summary>
		/// <param name="v"></param>
		/// <returns>
		/// return an uInt64 Object
		/// </returns>
		uInt64 operator"" _int(size_t v)noexcept {
			return v;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="v"></param>
		/// <returns></returns>
		Int8 operator"" _int(char v)noexcept {
			return v;
		}
	}
}

#endif // __INT_HPP__