#include<iostream>

namespace SS {

	namespace sss {
		void test1(){ std::cout << "not inline\n"; }
	}

	inline  namespace ssss {//inline将ssss命名空间内的函数直接导出到了SS
		void test1() { std::cout << "inline\n"; }
	}
}

int main() {
	SS::test1();//inline
	SS::ssss::test1();//not inline
	SS::sss::test1();
}