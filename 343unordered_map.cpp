#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<unordered_map>

struct CityRecord {
	std::string Name;
	uint64_t Population;
};
//顺便提醒 运算符重载必须加const关键字
bool operator==(const CityRecord& lhs, const CityRecord& rhs) {
	return lhs.Name == rhs.Name && lhs.Population == rhs.Population;
}

bool operator<(const CityRecord& a, const CityRecord& b) {
	return a.Population > b.Population;
}
//如果想在哈希map使用自定义的数据类型必须自定义特例化注入(指定如何散列该类型)，可以看330
namespace std {
	template<>
	struct hash<CityRecord>
	{
		size_t operator()(const CityRecord& Key)const noexcept
		{
			return std::hash<std::string>()(Key.Name);
		}
	};
}

int main() {
	std::unordered_map<CityRecord, uint32_t>foundeMap;
	foundeMap.insert(std::make_pair(CityRecord{ "就这",100 }, 3000));
	for (const auto& [a, b] : foundeMap)
		std::cout << a.Name << ' ' << b << std::endl;
}
/*
	map保持其元素有序。如果你不能放弃它，显然你不能使用unordered_map.

	要记住的另一件事是unordered_map通常会使用更多内存。map只有几个管家指针和每个对象的内存。相反，unordered_map有一个大数组（在某些实现中可能会变得很大），然后为每个对象增加额外的内存。如果您需要内存感知，map应该证明更好，因为它缺少大数组。
	
	所以，如果你需要纯粹的查找检索，我会说unordered_map这是要走的路。但总是有取舍，如果你买不起，那么你就不能使用它。
	
	仅从个人经验来看，我发现在使用unordered_map而不是map在主实体查找表中时，性能（当然是测量的）有了巨大的改进。
	
	另一方面，我发现重复插入和删除元素要慢得多。这对于相对静态的元素集合来说非常有用，但是如果您要进行大量的插入和删除，那么散列 + 分桶似乎会加起来。（注意，这是经过多次迭代。）

	https://stackoverflow.com/questions/2196995/is-there-any-advantage-of-using-map-over-unordered-map-in-case-of-trivial-keys
*/

//再强调一下，这个哈希值的生成，C++标准没有规定使用什么算法，这是库实现的事情，也就是可以说是编译器厂商实现