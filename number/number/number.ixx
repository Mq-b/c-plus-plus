export module number;

import<concepts>;
import<exception>;
import<vector>;
import<initializer_list>;
import<string>;
import<limits>;
import<format>;
import<algorithm>;
import<cmath>;
import<type_traits>;

export namespace myNum {

	//Custom numeric overflow exception
	struct NumOverflow :std::exception
	{
		NumOverflow(const std::string& s) :exception(s.data()) {}
	};

	//Specifies that constraints can only be integer and floating point
	template < class T >
	concept number = std::is_arithmetic_v<T>;

	template<number T>
	class Number {
	public:

		constexpr Number(T v)noexcept :_value{ v } {}

		constexpr Number()noexcept = default;

		constexpr Number(Number&& v)noexcept {
			this->_value = v.GetValue();
		}

		constexpr Number(const Number& v)noexcept = default;

		~Number() = default;

		template<typename T2>
		constexpr Number<T>& operator =(const Number<T2>& v)noexcept {
			this->_value = v.GetValue();
			return *this;
		}

		constexpr Number& operator=(const Number& v)noexcept = default;

		template<typename T2>
		constexpr Number<T>& operator =(Number<T2>&& v)noexcept {
			this->_value = v.GetValue();
			return *this;
		}

		constexpr Number& operator++()noexcept
		{
			this->_value++;
			return *this;
		}

		constexpr Number operator++(int)noexcept
		{
			auto old = *this;
			operator++();
			return old;
		}

		constexpr Number& operator--()noexcept
		{
			this->_value--;
			return *this;
		}

		constexpr Number operator--(int)noexcept
		{
			auto old = *this;
			operator--();
			return old;
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator +(const Number<T2>& v)const {
			using Type = std::common_type_t<T, T2>;
			auto max = std::max(static_cast<Type>(this->_value), static_cast<Type>(v.GetValue()));
			if (std::fabs(this->_value + v.GetValue()) < std::fabs(max)) {
				throw NumOverflow(std::format("{} + {} is greater than the maximum value of type {} {}.\nnumerical overflow error.",
					this->_value, v.GetValue(), typeid(Type).name(), std::numeric_limits<Type>::max()));
			}
			else {
				return Number<Type>(this->_value + v.GetValue());
			}
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator +(const T2 v)const {
			using Type = std::common_type_t<T, T2>;
			auto max = std::max(static_cast<Type>(this->_value), static_cast<Type>(v));
			if (std::fabs(this->_value) + std::fabs(v) < max) {
				throw NumOverflow(std::format("{} + {} is greater than the maximum value of type {} {}.\nnumerical overflow error.",
					this->_value, v, typeid(Type).name(), std::numeric_limits<Type>::max()));
			}
			else {
				return Number<Type>(this->_value + v);
			}
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator -(const Number<T2>& v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value - v.GetValue());
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator -(const T2 v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value - v);
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator *(const Number<T2>& v)const {
			int64_t max = this->_value * v.GetValue();
			if (this->_value!=0 && max / this->_value!=v.GetValue()) {
				throw NumOverflow(std::format("{} * {} is greater than the maximum value of type {} {}.\nNumerical overflow error.",
					this->_value, v.GetValue(), typeid(T).name(), std::numeric_limits<T>::max()));
			}
			else {
				return Number<std::common_type_t<T, T2>>(this->_value * v.GetValue());
			}
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator *(const T2 v)const {
			int64_t max = this->_value * v;
			if (this->_value != 0 && max / this->_value != v) {
				throw NumOverflow(std::format("{} * {} is greater than the maximum value of type {} {}.\nNumerical overflow error.",
					this->_value, v, typeid(T).name(), std::numeric_limits<T>::max()));
			}
			else {
				return Number<std::common_type_t<T, T2>>(this->_value * v);
			}
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator /(const Number<T2>& v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value / v.GetValue());
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator /(const T2 v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value / v);
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator %(const Number<T2>& v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value % v.GetValue());
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator %(const T2 v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value % v);
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator ^(const Number<T2>& v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value ^ v.GetValue());
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator ^(const T2 v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value ^ v);
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator &(const T2 v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value & v);
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator &(const Number<T2>& v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value & v.GetValue());
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator |(const T2 v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value | v);
		}

		template<typename T2>
		[[nodiscard]] constexpr Number<std::common_type_t<T, T2>> operator |(const Number<T2>& v)const noexcept {
			return Number<std::common_type_t<T, T2>>(this->_value | v.GetValue());
		}

		[[nodiscard]] constexpr Number<T> operator ~()const noexcept {
			return Number(~this->_value);
		}

		[[nodiscard]] constexpr bool operator !()const noexcept {
			return !bool(*this);
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator ==(const Number<T2>& v)const noexcept {
			return this->_value == v.GetValue();
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator ==(const T2& v)const noexcept {
			return this->_value == v;
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator !=(const Number<T2>& v)const noexcept {
			return !this->operator==(v);
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator !=(const T2& v)const noexcept {
			return !this->operator==(v);
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator <(const Number<T2>& v)const noexcept {
			return this->_value < v.GetValue();
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator <(const T2 v)const noexcept {
			return this->_value < v;
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator >(const Number<T2>& v)const noexcept {
			return !this->operator<(v);
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator >(const T2 v)const noexcept {
			return !this->operator<(v);
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator <=(const Number<T2>& v)const noexcept {
			return this->operator<(v) || this->operator==(v);
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator <=(const T2 v)const noexcept {
			return this->operator<(v) || this->operator==(v);
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator >=(const Number<T2>& v)const noexcept {
			return this->operator>(v) || this->operator==(v);
		}

		template<typename T2>
		[[nodiscard]] constexpr bool operator >=(const T2 v)const noexcept {
			return this->operator>(v) || this->operator==(v);
		}

		template<typename T2>
		constexpr void operator+=(const Number<T2>& v)noexcept {
			auto max = std::max(this->_value, static_cast<T>(v.GetValue()));
			if (this->_value + v.GetValue() < max) {
				throw NumOverflow(std::format("{} + {} is greater than the maximum value of type {} {}.\nNumerical overflow error.",
					this->_value, v.GetValue(), typeid(T).name(), std::numeric_limits<T>::max()));
			}
			else {
				this->operator+(v.GetValue());
				this->_value += v.GetValue();
			}
		}

		template<typename T2>
		constexpr void operator+=(Number<T2>&& v) {
			auto max = std::max(this->_value, T(v));
			if (this->_value + v.GetValue() < max) {
				throw NumOverflow(std::format("{} + {} is greater than the maximum value of type {} {}.\nNumerical overflow error.",
					this->_value, v.GetValue(), typeid(T).name(), std::numeric_limits<T>::max()));
			}
			else {
				this->operator+(v.GetValue());
				this->_value += v.GetValue();
			}
		}

		template<typename T2>
		constexpr void operator-=(const Number<T2>& v)noexcept {
			this->_value -= v.GetValue();
		}
		template<typename T2>
		constexpr void operator-=(Number<T2>&& v)noexcept {
			this->_value -= v.GetValue();
		}

		explicit constexpr operator T()const noexcept {
			return this->_value;
		}

		[[nodiscard]] constexpr Number* operator&()noexcept {
			return this;
		}

		explicit constexpr operator bool()const noexcept {
			return static_cast<bool>(this->_value);
		}

		[[nodiscard]] constexpr T GetValue()const noexcept {
			return this->_value;
		}
	private:
		T _value{};
	};

	//Custom "number" literal
	auto operator "" _num(unsigned long long int lit)noexcept ->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(long double lit)noexcept ->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(char lit)noexcept ->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(wchar_t lit)noexcept->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(char16_t lit)noexcept ->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(char32_t lit)noexcept ->decltype(Number(lit))
	{
		return Number(lit);
	};

	//Output operator overloading
	template<number T>
	std::ostream& operator<<(std::ostream& out, Number<T>& v)noexcept {
		out << v.GetValue();
		return out;
	}
	template<number T>
	std::ostream& operator<<(std::ostream& out, Number<T>&& v)noexcept {
		out << v.GetValue();
		return out;
	}

	using uint64 = unsigned long long;
	using Int = Number<uint64>;
	using Char = Number<char>;
	using Schar = Number<signed char>;
	using Uchar = Number<unsigned char>;
}