#include<string>
#include<map>
#include<functional>
#include<iostream>

class Test {
public:
	std::map<int, std::function<int(int)>>func;
	int m = 0;

	Test() {
		auto a = [this](auto n) {
			m += 100;
			show();
			return n;
		};
		auto b = [this](auto n) {
			m -= n;
			show();
			return n;
		};
		func.insert(std::make_pair(1, a));
		func.insert(std::make_pair(2, b));
	}

	void test() {
		auto a = [this](auto n) {
			m += 100;
			show();
			return n;
		};
		std::function<std::string(std::string)>f(a);
		auto b = f(std::string("傻子"));
		std::cout << b << std::endl;
	}
private:
	void show() {
		std::cout << this->m << std::endl;
	}
};

int main() {
	Test a;
	a.func[1](100);		//调用函数
	std::cout << a.m << std::endl;

	a.test();		//由此可见，function可以绑定任意的泛型lambda

}
//lambda是一个匿名类，重载了operator()且有template，所以可以这样做，详情看232