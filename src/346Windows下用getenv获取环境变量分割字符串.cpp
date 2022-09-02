#include<iostream>
#include<vector>
int main() {
	std::vector<std::string>ret;
	const char* env_p = std::getenv("PATH");//"PATH"这个指的是系统环境变量那一栏的PATH，而非用户环境变量
	for (std::string Str(env_p); !Str.empty();) {
		int size(0);
		size = Str.find(";");//获取下标
		ret.emplace_back(Str.substr(0, size + 1) + "\n");
		Str = Str.substr(size + 1, Str.size());//字符串收缩
	}
	for (const auto& i : ret)
		std::cout << i;
}