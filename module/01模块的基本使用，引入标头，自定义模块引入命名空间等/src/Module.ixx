export module Module;//声明可写可不写

export import <iostream>;//引入标头
//export int main() {
//    std::cout << "666" << '\n';//在ixx文件里也能写main直接运行
//}

//export C++20标记一个声明、一组声明或另一模块为当前模块所导出
export void func(auto c) {
	std::cout << "Module\t" <<c <<std::endl;
}
/*模块接口单元可以导出声明和定义，这些内容可以导入到其他翻译单元。它们可以有 export 关键词作为前缀，或者处于 export 块中。
export 声明		
export { 声明序列(可选) }		
https://zh.cppreference.com/w/cpp/language/modules
*/