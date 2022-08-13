#include<iostream>
#include<variant>

decltype(auto) demo() {
	//define
	std::variant<int, double, std::wstring> var1{ 1.0 };
	std::variant<int, double, std::wstring> var2{ L"2" };
	std::variant<int, std::wstring> var3{ 3 };

	//assign
	var2 = L"abc";
	var1 = L"str1";
	var2.emplace<int>(1);	//原位构造 variant 中的值
	std::wcout << L"the var1 = " << std::get<std::wstring>(var1) << std::endl;		//std::get()使用类型查找
	std::wcout << L"the var2 = " << std::get<0>(var2) << std::endl;					//std::get()使用下标查找

	//swap
	std::swap(var1, var2);

	//确定变体的类型
	if (var2.index() == 2) {
		//它是绞线型
	}
	var1 = 100;
	if (std::holds_alternative<int>(var1)) {	//检查某个 variant 是否当前持有某个给定类型
		std::wcout << L"var1 is " << typeid(int).name() << std::endl;
	}

	//提供对可有 cv 限定 variant 的类型编译时下标访问，将 variant 的 cv 限定与可选项的 cv 限定（若存在）相结合
	std::variant_alternative<2, decltype(var1)>::type val{ L"123" };
	// 获取值
	var1 = 1;
	std::wcout << L"var1 = " << std::get<int>(var1) << std::endl;

	var2 = L"2";
	std::wcout << L"var2 = " << std::get<2>(var2) << std::endl;

	if (auto pV = std::get_if<int>(&var3)) {	//指向存储于被指向的 variant 中值的指针，错误时为空指针
		std::wcout << L"var3 = " << *pV << std::endl;
	}
}

int main() {
	demo();
	return 0;
}