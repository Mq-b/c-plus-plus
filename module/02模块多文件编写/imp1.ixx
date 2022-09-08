module;
export module mylib:imp1;
import<iostream>;//引入的标头记得要写在export module xxx的后面
import<string>;
namespace mylib {
	void println(auto e) {
		std::cout << e << std::endl;
	}

	template<class T>
	class Test {
		T value;
	public:
		constexpr Test(T v) :value{ v } {}
		constexpr T getValue()noexcept {
			return this->value;
		}
	};
}
void print()
{
	puts("888888");
}