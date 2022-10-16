#include<iostream>

template<typename...T>
struct max_size;//声明

template<typename First, typename...Rest>
struct max_size<First, Rest...> {//部分特化(递归)
	using rest_type = typename max_size<Rest...>::type;//递归,调用自身
	using type = typename std::conditional_t<(sizeof(First) > sizeof(rest_type)), First, rest_type>;
};

template<typename First>
struct max_size<First> {//部分特化(终止),这只是为了最后单个类型的时候匹配上，就会终止，得到size最大的类型
	using type = First;
};

int main() {
	using T = max_size<int, double, short, int64_t>::rest_type;//使用rest_type或type是一样的，在单个只剩下单个参数的时候他们的递归就会停止
}