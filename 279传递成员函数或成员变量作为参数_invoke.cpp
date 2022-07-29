#include<iostream>
#include<vector>
namespace stdl = std::ranges;
class Test {
public:
	uint16_t num = 0;
	 auto number(size_t n=0)->std::vector<int> const {
		std::cout << n << std::endl;
		return { 1,2,3,4,5,6,7,8,9,10 };
	}
};

template<typename T,typename A>
void test(T f,A func,int n) {
	stdl::copy((f->*func)(n), std::ostream_iterator<int>{std::cout, " "});
	std::endl(std::cout);
}

int main() {
	Test c;
	test(&c, &Test::number,10);

	auto func = std::invoke(&Test::number,&c,10);
	stdl::copy(func, std::ostream_iterator<int>{std::cout, " "});
	std::endl(std::cout);

	uint16_t& i = std::invoke(&Test::num, &c);
	i = 9999;
	std::cout << c.num << std::endl;
}