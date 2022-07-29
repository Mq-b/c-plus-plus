#include<iostream>
#include<string>

template<typename...> struct Tuple {};
template<typename T1, typename T2> struct Pair {};

template<class... Args1> struct zip
{
    template<class... Args2> struct with
    {
        typedef Tuple<Pair<Args1, Args2>...> type;
        // Pair<Args1, Args2>... 是包展开
        // Pair<Args1, Args2> 是模式
    };
};

typedef zip<short, int>::with<unsigned short, unsigned>::type T1;
// Pair<Args1, Args2>... 会展开成
// Pair<short, unsigned short>, Pair<int, unsigned int> 
// T1 是 Tuple<Pair<short, unsigned short>, Pair<int, unsigned>>
int main()
{

    return 0;
}