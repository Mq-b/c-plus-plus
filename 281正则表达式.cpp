#include<iostream>
#include<string>
#include<regex>

void search() {
	//std::regex_search: 搜素正则表达式参数, 但它不要求整个字符序列完全匹配. 
	//而且它只进行单次搜索, 搜索到即停止继续搜索, 不进行重复多次搜索.
	std::string text = "Date:2017-10-10 ~ 2018-10-15";
	std::string pattern = "(\\d\\d\\d\\d)";
	std::regex express(pattern);
	std::smatch results1;
	if (std::regex_search(text, results1, express)){
		for (auto i : results1)
			std::cout << i.length() << ":" << i.str() << std::endl;//打印匹配的字符与长度
	}
	std::cout << std::regex_search(text, express) << std::endl;//正则是否匹配，打印0或者1
}
void extended() {
	std::string str = "zzxayyzz";
	std::regex re1(".*(a|xayy)"); // ECMA
	std::regex re2(".*(a|xayy)", std::regex_constants::extended); // POSIX
	std::cout << "Searching for .*(a|xayy) in zzxayyzz:\n";
	std::smatch m;
	std::regex_search(str, m, re1);
	std::cout << " ECMA (depth first search) match: " << m[0] << '\n';
	std::regex_search(str, m, re2);
	std::cout << " POSIX (leftmost longest)  match: " << m[0] << '\n';
}
void regex_match() {
	std::string text = "192.168.139.2";
	std::regex e("\\d + \\.\\d + \\.\\d + \\.\\d");
	std::cmatch what; //匹配的词语检索出来
	if (regex_match("helloamfinalthinks192.168.139.2AAA", what, e)){
		for (int i = 0; i != what.size(); i++) {
			std::cout << what[i].first;
		}
	}
}
void regex_iterator() 
{
	std::string text = "hello am final thinks 192.168.139.2AAA";
	std::string pattern = "(\\d)+\\.\\d+\\.\\d+\\.\\d";
	std::regex express(pattern);

	std::regex_iterator<std::string::const_iterator> begin(text.cbegin(), text.cend(), express);
	for (auto iter = begin; iter != std::sregex_iterator(); iter++)
	{
		std::cout << iter->length() << ": " << iter->str(0) << std::endl;//str方法可以把分组的数据得到值得注意
	}
}
void regex_replace() {
	std::regex reg("\\d+"); //数字
	std::string str="hello 8848";
	std::cout << std::regex_replace(str, reg, "爆炸手机") << std::endl;
}
int main() {
	
	//std::regex_search
	//search();

	//std::regex_constants::extended
	//extended();

	//regex_match
	//regex_match();

	//std::regex_iterator
	//regex_iterator();

	//regex_replace(替换)
	//regex_replace();

	/*
		std::regex_iterator和std::regex_replace足以满足我们的日常使用。
		C++标准库的正则类效率过低，Qt或boost都有其他更加优秀的类。
	*/
}