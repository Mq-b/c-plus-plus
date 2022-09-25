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
	
	//Number<int*> c3(NULL );
}