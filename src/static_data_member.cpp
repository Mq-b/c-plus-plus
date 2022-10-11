struct X {
	static int value;
};

int X::value = 10;

namespace S {//命名空间作用域都具有外部链接
	int n = 10;
	int f() { return 6; };
}