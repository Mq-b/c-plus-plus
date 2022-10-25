#include"string_view.hpp"
#include<array>
using namespace mylib;
using namespace std::literals;

int main() {
	string_view s("06619");
	std::cout << s.begin().m_ptr << std::endl;
	std::cout << s.begin()[3] << std::endl;
	std::cout << *s.rbegin() << ' ' << *s.crbegin() << ' ' << *(s.cend() - 1) << ' ' << *(s.crend() - 1) << std::endl;
	std::cout << s[3] << std::endl;
	std::cout << s.front() << ' ' << s.back() << ' ' << s.empty() << ' ' << s.size()<<' ' << s.length() << ' ' << s.max_size() << '\n';
	s.remove_prefix(2);
	std::cout << s << '\n';
	s.remove_suffix(2);
	std::cout << s << '\n';

	string_view s2("**//****");
	s.swap(s2);
	std::cout << s << ' ' << s2 << '\n';

	std::string str{ "123456" };
	s.copy(reinterpret_cast<char*>(str.data()), 2, 2);
	std::cout << str.data() << '\n';

	auto s3 = s2.substr(2,3);
	std::cout << s3.size() << '\n';
	std::cout << s3 << '\n';

	string_view s4(str.data());
	std::cout << s4.compare(str.data()) << '\n';

	string_view s5("12311456");
	std::string str2("123");
	std::cout << s5.starts_with(str2) << ' ' << s5.starts_with("123") << ' ' << s5.starts_with('1') << '\n';
	std::cout << s5.ends_with(str2) << ' ' << s5.ends_with("123") << ' ' << s5.ends_with('6') << '\n';

	std::cout << s5.find("45") << ' ' << s5.find('1') <<' ' << s5.find("56") << '\n';
	std::cout << s5.rfind('1') << '\n';

	std::string_view s6("abcd");
	//std::cout << s.find("12346c") << '\n';
	std::cout << s6.find_first_of("cdef") << '\n';
	std::cout << s6.find_last_of("cdef") << '\n';
	std::cout << s6.find_last_of("1") << '\n';
	std::cout << s6.find_first_not_of("bbc") << '\n';
	std::cout << s6.find_last_not_of("bbc") << '\n';
	
	std::cout << "离谱a"_sv.size() << '\n';

	std::cout << ("abcd"_sv <=> "ggggggg"_sv) << '\n';


	std::array a1{ 'n', 'u', 'c', 'l', 'e', 'o', 'n', 's', ':', '\n' };
	basic_string_view s1(a1.cbegin(), a1.cend()); // 推导： CharT -> char
	static_assert(std::is_same_v<decltype(s1)::value_type, char>);
	std::cout << s1;
}