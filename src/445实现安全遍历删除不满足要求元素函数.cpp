#include<iostream>
#include<vector>
#include<map>

template<typename T, typename F>
concept erase_ = requires(T v, F f) {
	f(*v.begin());
};

template<typename T, typename F>
	requires erase_<T, F>
void erase(T& v, F f) {
	for (auto i = v.begin(); i != v.end(); f(*i) ? i = v.erase(i) : i++);
}

int main() {
	std::vector v{ 1,2,3,4,5 };
	std::map<int, int> v2{ {1,1},{2,2},{3,3},{4,4},{5,5} };
	auto f = [](int v) { return v % 2 == 0; };
	::erase(v, f);
	::erase(v2, [](const std::pair<int, int>& v) {return v.second % 2 == 0; });
	for (auto i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
	for (const auto& [a, b] : v2) {
		std::cout << b << ' ';
	}
}