import Foo;
int main() {
	auto evil = lolwut();        // 'evil' 拥有 'LolWatchThis' 类型
	//decltype(evil)::say_hello(); // 'LolWatchThis' 的定义不再为内部，error
	//std::cout << typeid(evil).name() << std::endl;
}
/*
翻译单元局部（ TU 局部）实体是为阻止假定为局部（不用于任何其他翻译单元）的实体暴露且用于其他翻译单元而引入的
https://zh.cppreference.com/w/cpp/language/tu_local
*/