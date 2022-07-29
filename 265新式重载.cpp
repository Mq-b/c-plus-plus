#include<string>
#include<stdio.h>
#include<type_traits>

::std::string do_to_string(::std::true_type,::std::true_type,long long value)
{
	char str[64];
	int len = ::sprintf(str, "%lld", value);
	return::std::string(str, len);
}
::std::string do_to_string(::std::true_type,std::false_type,unsigned long long value)
{
	char str[64];
	int len = ::sprintf(str, "%llu", value);
	return::std::string(str, len);
}
::std::string do_to_string(::std::false_type,::std::true_type,long double value)
{
	char str[64];
	int len = ::sprintf(str, "%Lg", value);
	return::std::string(str, len);
}
template<typename T>
::std::string to_string(const T& t)
{
	return do_to_string(::std::is_integral<T>(), ::std::is_signed<T>(), t);
}

int main() {
	::std::string str;

	str = to_string(1234);
	::printf("str=%s\n", str.c_str());

	str = to_string(-1234);
	::printf("str=%s\n", str.c_str());

	str = to_string(56.789);
	::printf("str=%s\n", str.c_str());

	return 0;
}