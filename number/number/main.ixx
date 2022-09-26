import number;

import<iostream>;
import<limits>;
using namespace mylib;
using namespace std::literals;

int main() {
	Number c{10};
	Number c2(std::move(c));
	std::cout << typeid(1_num).name() << std::endl;
	try
	{
		std::cout << (1_num + std::numeric_limits<std::size_t>::max()).GetValue() << std::endl;
	}
	catch (const std::exception&e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << c << ' ' << c2 << std::endl;
	c += c2;
	std::cout << c << std::endl;
	std::cout << c + c2 << std::endl;
	std::cout << c + 10 << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	//Number<int*> c3(NULL );
	const Number n{ 10 };
	Number n2{ 10 };
	c2 = n;
	c2 = n2;
	c2 = 10_num;
	c = c = c2;
	c2 = std::move(c);
	std::cout << c2 << std::endl;
	auto c3 = &c2;
	std::cout << *c3 << std::endl;
}