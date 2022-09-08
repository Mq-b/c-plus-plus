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
		Test(T v) :value{ v } {}
		T getValue() {
			return this->value;
		}
	};
}
void print()
{
	puts("888888");
}