#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

struct S {
	std::string first_name;
	std::string last_name;
};
bool operator==(const S& lhs, const S& rhs) {
	return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}

// 自定义散列函数能是独立函数对象：
struct MyHash {
	std::size_t operator()(S const& s) const
	{
		std::size_t h1 = std::hash<std::string>{}(s.first_name);		/*根据传入的值返回一个哈希值,参数列表是string，将会根据string转换为数字，然后进行某种计算返回哈希值*/
		std::size_t h2 = std::hash<std::string>{}(s.last_name);			/*先使用{}是构造了一个临时对象，然后()是因为它有operator()所以我们使用的是他的operator()函数*/
		return h1 ^ (h2 << 1);
	}
};

// std::hash 的自定义特化能注入 namespace std
namespace std {
	template<> struct hash<S>	/*库函数提供的 hash 的所有显式和部分特化可默认构造 (DefaultConstructible) 、可复制赋值 (CopyAssignable) 、可交换 (Swappable) 且可析构 (Destructible) 。用户提供的 hash 特化亦必须满足这些要求。*/
	{
		size_t operator()(S const& s) const
		{
			size_t const h1(std::hash<std::string>{}(s.first_name));
			size_t const h2(std::hash<std::string>{}(s.last_name));
			return h1 ^ (h2 << 1);
		}
	};
}

int main() {
	std::string str = "Meet the new boss...";
	std::size_t str_hash = std::hash<std::string>{}(str);
	std::cout << "hash(" << std::quoted(str) << ") = " << str_hash << '\n';	/*固定值所生成的哈希值是固定的*/

	S obj = { "Hubert", "Farnsworth" };
	// 使用独立的函数对象
	std::cout << "hash(" << std::quoted(obj.first_name) << ", "
		<< std::quoted(obj.last_name) << ") = "
		<< MyHash{}(obj) << " (使用 MyHash)\n" << std::setw(31) << "or "		/*std::setw用来控制输出空格个数*/
		<< std::hash<S>{}(obj) << " (使用注入的std::hash特化)\n";

	// 自定义散列函数令在无序容器中使用自定义类型可行
	// 此示例将使用注入的 std::hash 特化，
	// 若要使用 MyHash 替代，则将其作为第二模板参数传递
	std::unordered_set<S> names = { obj, {"Bender", "Rodriguez"}, {"Leela", "Turanga"} };	/*哈希set使用自定义类型构造*/
	for (auto& s : names)
		std::cout << std::quoted(s.first_name) << ' ' << std::quoted(s.last_name) << '\n';

	std::cout << "int哈希值 = " << std::hash<int>{}(10) << std::endl;
	/*std::quoted的作用只是单纯的给字符串加引号而已，不用在意*/
	std::string ss("就这??");
	std::cout << std::quoted(ss) << std::endl;	//"就这??"
	std::cout << ss << std::endl;				//就这??
}