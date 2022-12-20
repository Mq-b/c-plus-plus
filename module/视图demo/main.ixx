import<iostream>;
import<ranges>;
import<array>;
import<algorithm>;
import<vector>;

namespace stdv = std::views;

template<class U,class F>
	requires std::regular_invocable<F,U&>
std::vector<U>& operator |(std::vector<U>& v, F f) {
	for (auto& i: v) {
		f(i);
	}
	return v;
}

int main() {
	std::array array{ 1,2,3,4,5 };
	for (const auto& i : array | stdv::filter([](int i) {return i % 2 != 0; }) | stdv::transform([](auto i) {return i * i; })) {
		std::cout << i << ' ';
	}

	endl(std::cout);
	for (const auto& i : array ) {
		std::cout << i << ' ';
	}
	endl(std::cout);

	int arr[5][5]{};
	for (int n = 0; auto & i : arr | stdv::join) {
		i = ++n;
	}
	for (const auto& i : arr | stdv::join) {
		std::cout << i << ' ';
	}
	endl(std::cout);

	std::vector V{ 1,2,3 };
	V | [](int i) {std::cout << i << ' '; } | [](int& i) {i *= i; };
	V | [](int i) {std::cout << i << ' '; };
}