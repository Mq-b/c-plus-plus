export module number;

import<concepts>;
import<exception>;
import<vector>;
import<initializer_list>;
import<string>;
import<limits>;
import<format>;
import<algorithm>;

export namespace myNum {

	//Custom numeric overflow exception
	struct NumOverflow :std::exception
	{
		NumOverflow(const std::string& s) :exception(s.data()) {}
	};

	//Specifies that constraints can only be integer and floating point
	template < class T >
	concept number = std::is_integral_v<T> || std::is_floating_point_v<T>;

	using uint64 = unsigned long long;

	template<number T>
	class Number {
	public:

		Number(T v) :_value{ v } {}

		constexpr Number()noexcept = default;

		constexpr Number(Number&& v)noexcept {
			this->_value = v.GetValue();
		}

		constexpr Number(const Number& v)noexcept = default;

		~Number() = default;

		template<typename T2>
		Number operator +(Number<T2>& v)const {
			auto max = std::max(this->_value, T(v.GetValue()));
			if (this->_value + v.GetValue() < max) {
				throw NumOverflow(std::format("{} + {} is greater than the maximum value of type {} {}.\nNumerical overflow error.",
					this->_value, v.GetValue(), typeid(T).name(), std::numeric_limits<T>::max()));
			}else {
				return Number(this->_value + v.GetValue());
			}
		}

		constexpr Number operator +(const T v)const {
			auto max = std::max(this->_value, v);
			if (this->_value + v < max) {
				throw NumOverflow(std::format("{} + {} is greater than the maximum value of type {} {}.\nnumerical overflow error.",
					this->_value, v, typeid(T).name(), std::numeric_limits<T>::max()));
			}
			else {
				return Number(this->_value + v);
			}
		}

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

		void operator+=(const Number& v) {
			auto max = std::max(this->_value, v._value);
			if (this->_value + v._value < max) {
				throw NumOverflow(std::format("{} + {} is greater than the maximum value of type {} {}.\nNumerical overflow error.",
					this->_value, v._value, typeid(T).name(), std::numeric_limits<T>::max()));
			}
			else {
				this->_value += v._value;
			}
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

		constexpr Number* operator&()noexcept {
			return this;
		}

		template<typename T2>
		Number<T> operator -(Number<T2>& v)const {
				return Number(this->_value - v.GetValue());
		}

		explicit constexpr operator T()noexcept {
			return this->_value;
		}

		T GetValue()noexcept {
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

	using Int = Number<uint64>;
	using Char = Number<char>;
}