export module number;


import<concepts>;
import<exception>;
import<vector>;
import<initializer_list>;
import<string>;
import<limits>;
#include<format>//纯属为了少爆点红
import<algorithm>;

export namespace mylib {

	//Custom numeric overflow exception
	struct NumOverflow :std::exception
	{
		NumOverflow(const std::string& s) :exception(s.data()) {}
	};

	//Specifies that constraints can only be integer and floating point
	template < class T >
	concept number = std::is_integral_v<T> || std::is_floating_point_v<T>;

	template<number T>
	class Number {
	public:

		Number(T v) :_value{ v } {}

		Number() = default;

		Number(Number&& v) = default;

		Number(const Number& v) = default;

		~Number() = default;

		/*operator T()const noexcept {
			return this->_value;
		}*/

		Number operator +(const Number& v)const {
			auto max = std::max(this->_value, v._value);
			if (this->_value + v._value < max) {
				throw NumOverflow(std::format("{} + {} is greater than the maximum value of type {} {}.\nNumerical overflow error.",
					this->_value, v._value, typeid(T).name(), std::numeric_limits<T>::max()));
			}else {
				return Number(this->_value + v._value);
			}
		}

		T GetValue() {
			return this->_value;
		}

	private:
		T _value;
	};

	//Custom "number" literal
	auto operator "" _num(unsigned long long int lit)->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(long double lit)->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(char lit)->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(wchar_t lit)->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(char16_t lit)->decltype(Number(lit))
	{
		return Number(lit);
	};

	auto operator "" _num(char32_t lit)->decltype(Number(lit))
	{
		return Number(lit);
	};

}