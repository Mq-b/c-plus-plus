export module mylib;//模块声明导出
import :imp1;
export namespace mylib {
	void println(auto e);

	template<class T>//模板类声明
	class Test;
}
export void print();