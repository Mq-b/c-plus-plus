#include <iostream>
#include <future>
#include <variant>
#include <optional>

#define GET(N,V) std::get<N>(V[N].value()) 

struct A { int a; };
struct B { int b; };
struct C { int c; };
template<typename...Args>
class Any_vector
{
	std::tuple<Args...>m_objs;
public:
	using RetType = std::variant<Args...>;
	constexpr Any_vector(Args...args) : m_objs{ args... } {}

	constexpr auto operator[](size_t index) noexcept -> std::optional<RetType> {
		auto buildRet = [&]<size_t I>(std::in_place_index_t<I>, size_t index, RetType & res) {
			if (I == index) {
				res.template emplace<I>(std::get<I>(m_objs));//原位构造，更新std::variant状态
				return true;
			}
			return false;
		};
		return[&]<size_t ...Is>(std::index_sequence<Is...> is) -> std::optional<RetType> {
			RetType res;
			if ((buildRet(std::in_place_index<Is>, index, res) || ...)) {
				return res;
			}
			return std::nullopt;
		} (std::index_sequence_for<Args...> {});
	}
};

int main() {
	Any_vector v{ A{},B{},C{} };
	std::cout << std::get<0>(v[0].value()).a << '\n';
	std::cout << std::get<1>(v[1].value()).b << '\n';
	std::cout << GET(2, v).c << '\n';
}