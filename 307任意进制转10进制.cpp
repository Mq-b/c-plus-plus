#include<iostream>
#include<string>

int main()
{
	int r, ans = 0;
	std::string n;//数字
	std::cin >> r >> n;//R表示进制,N表示要转换的数，ans表示要转换的结果。
	for (int i = 0; n.size() != i; i++)
	{
		ans *= r;
		ans += n[i] - '0';
	}
	std::cout << ans << std::endl;
	return 0;
}
//假如是10进制的100，那么 ans是 0 1 10 100，最后还是100
//此代码不适合使用字符表示的方式，比如16进制的20也就是1a，相当于10进制32，我们没处理1a这种行为