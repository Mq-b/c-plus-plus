class Test {
public:
	auto operator[](int i) {
		return "operator[]";
	}
	auto operator[](int i)const {
		return "opetator[]const";
	}
};
#include<iostream>
int main() {
	Test a;
	const Test b;
	std::cout << a[0] << '\n' << b[0];
}
/*之前遗漏的，其实如果不以const为不同作为重载的话，不管是不是const的对象也能调用operator[]const*/