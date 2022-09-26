export module number;


import<concepts>;
import<exception>;
import<vector>;
import<initializer_list>;
import<string>;
import<limits>;
import<format>;
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

		constexpr Number()noexcept {}

		Number(Number&& v)noexcept {
			this->_value = v.GetValue();
		}

		Number(const Number& v) = default;

		~Number() = default;

		Number operator +(const Number& v)const {
			auto max = std::max(this->_value, v._value);
			if (this->_value + v._value < max) {
				throw NumOverflow(std::format("{} + {} is greater than the maximum value of type {} {}.\nNumerical overflow error.",
					this->_value, v._value, typeid(T).name(), std::numeric_limits<T>::max()));
			}else {
				return Number(this->_value + v._value);
			}
		}

		Number operator +(const T v)const {
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
		Number<T>& operator =(Number<T2>& v)noexcept {
			this->_value = v.GetValue();
			puts("复制复制");
			return *this;
		}

		template<typename T2>
		Number<T>& operator =(Number<T2>&& v)noexcept {
			this->_value = v.GetValue();
			puts("移动赋值");
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

		Number& operator++()
		{
			this->_value++;
			return *this;
		}

		Number operator++(int)
		{
			auto old = *this; 
			operator++();  
			return old;    
		}

		T GetValue() {
			return this->_value;
		}

	private:
		T _value{};
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
}