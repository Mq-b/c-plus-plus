#include<tuple>
#include<iostream>
#include<type_traits>

template<class TupType, size_t... I>
void print(const TupType& _tup, std::index_sequence<I...>)
{
	std::cout << "(";
	(..., (std::cout << (I == 0 ? "" : ", ") << std::get<I>(_tup)));
	std::cout << ")\n";
}

template<class... T>
void print(const std::tuple<T...>& _tup)	//这个重载只是为了包装一下上面的，少输入一个参数
{
	print(_tup, std::make_index_sequence<sizeof...(T)>());
}

int main() {
	auto tp = std::make_tuple(1, 3.14, "Hello Word");
	print(tp);
}