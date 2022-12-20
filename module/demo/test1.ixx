export module test1.O;//声明当前翻译单元是一个模块单元

export void MyFunc();
//
//export void print(auto);

export import:A;
export import:B;
//我的这个模板分区里的函数实现是没有导出的，但是 模块分区内的所有声明和定义在将它导入的模块单元中均可见，无论它们是否被导出。
