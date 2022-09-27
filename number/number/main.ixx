import number;

import<iostream>;
import<limits>;
using namespace myNum;
using namespace std::literals;

int main() {
	Number c{10};
	Number c2(std::move(c));
	std::cout << typeid(1_num).name() << std::endl;
	try
	{
		std::cout << (1_num + std::numeric_limits<std::size_t>::max()).GetValue() << std::endl;
		//auto t = 1_num;
		//t += Number(std::numeric_limits<std::size_t>::max());//两行代码都会抛出异常
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

	std::cout << int(c2) << std::endl;

	puts("--------------------------------------------------------------");

	Number c5{ 10 };
	Number c6{ 'a'};
	
	std::cout << c6 - c5 << std::endl;
	std::cout << c6 - 1_num << std::endl;
	std::cout << c6 + c5 << std::endl;
	std::cout << c6 + 1_num << std::endl;

	c6 += c5;
	std::cout << c6 << std::endl;
	c5 -= c2;
	std::cout << c5 << std::endl;
	c6 -= c5;
	std::cout << c6 << std::endl;
	c5 -= 1_num;
	std::cout << c5 << std::endl;

	//std::cout << c5 * 100 << std::endl;
	//std::cout << c5 * 100_num << std::endl;
	c5 = 100;
	std::cout << c5 / 100 << std::endl;
	std::cout << c5 / 100_num << std::endl;

	c5 = 25_num;
	std::cout << c5 % c2 << std::endl;
	std::cout << c5 % c6 << std::endl;
	std::cout << c5 % 6_num << std::endl;
	std::cout << c5 % 6 << std::endl;

	std::cout << (c5 ^ 6) << std::endl;

	std::cout << (c5 & 1) << std::endl;

	std::cout << (c5 | 1) << std::endl;

	std::cout << ~10_num << std::endl;

	std::cout << !0_num << std::endl;

	std::cout << !1_num << std::endl;

	c6 = 'a';
	std::cout << (c6 == c5) << std::endl;

	std::cout << (97_num == c6) << std::endl;

	std::cout << (97_num == 97) << std::endl;

	std::cout << (97_num != 10.5) << std::endl;

	std::cout << (97_num != 97_num) << std::endl;

	std::cout << (97_num < 100_num) << std::endl;

	std::cout << (100_num < 97_num) << std::endl;

	std::cout << (97_num > 100_num) << std::endl;

	std::cout << (100_num > 97_num) << std::endl;

	std::cout << (97_num <= 100_num) << std::endl;

	std::cout << (97_num <= 97_num) << std::endl;

	//std::cout << c6 * 100 << std::endl;
	//auto ret = c6 * 100;

	auto ret2 = 1.0_num * c6 * 2;
	std::cout << ret2 << std::endl;
	try
	{
		auto ret3 = 1_num * c6 * std::numeric_limits<std::size_t>::max();
		std::cout << ret3 << std::endl;
	}
	catch (const std::exception&e)
	{
		std::cerr << e.what() << std::endl;
	}

	Number c7{ -1 };
	Number c8{ -5 };
	//auto ret3 = c7 + c8;
	try
	{
		//auto c8=c7 / 0;
	}
	catch (const std::exception&e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << -c7 << std::endl;
	
	Number c9{ 1u };
	//-c9;

	std::cout << (c9 << 3) << std::endl;

	std::cout << (c9 >> 3) << std::endl;

	Number c10{ 1 };

	std::cout << int((c10 <=> c10)._Value) << std::endl;

	std::cout << int((c10 <=> c8)._Value) << std::endl;

	std::cout << int((c8 <=> c10)._Value) << std::endl;

	std::cout << int((c9 <=> c8)._Value) << std::endl;

	std::cout << int((c9 <=> 1u)._Value) << std::endl;

	std::cout << int((c10 <=> 2)._Value) << std::endl;

	std::cout << int((2 <=> c10)._Value) << std::endl;
	
	std::cout << c10.to_string() << std::endl;

	std::cout << Number<int>::max << std::endl;

	auto c11 = myNum::min(1_num, 2_num, 3_num, 4_num);
	std::cout << c11 << std::endl;

	std::cout << myNum::max(1_num, 2_num, 3_num, 4_num) << std::endl;

}