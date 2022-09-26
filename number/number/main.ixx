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
	c2 = c;
	c2 = 10_num;
	std::cout << c2 << std::endl;
}