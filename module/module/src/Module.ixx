export module Module;//声明可写可不写

import <iostream>;//引入标头

//export int main() {
//    std::cout << "666" << '\n';//在ixx文件里也能写main直接运行
//}

export void func() {
	std::cout << "Module" << std::endl;
}
/*export: 为了访问其他编译单元（如另一代码文件）中的变量或对象，对普通类型（包括基本数据类、结构和类），可以利用关键字extern，来使用这些变量或对象时；
但是对模板类型，则必须在定义这些模板类对象和模板函数时，使用标准C++新增加的关键字export（导出/出口/输出）。*/