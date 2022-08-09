#include<iostream>
/*
	static_cast：基本类型转换，低风险；
	dynamic_cast：类层次间的上行转换或下行转换，低风险；
	const_cast：去 const 属性，低风险；
	reinterpret_cast：转换不相关的类型，高风险。
*/

/* 上行转换是指派生类→基类*/

/* 下行转换是指基类→派生类*/

/*因为派生类包含基类信息，所以上行转换直接使用static_cast是安全的，dynamic_cast在上行转换方面和static_cast一样*/

/*下行转换使用dynamic_cast更加安全，因为它具有具有类型检查的功能*/

struct Father {
	virtual void print() {
		std::cout << "Father" << std::endl;
	}
};
struct Son :public Father {
	virtual void print() {
		std::cout << "Son" << std::endl;
	}
};

int main() {
	int a1 = 100;
	int const* p1 = &a1;
	//*p1=0;	/*error*/
	auto p2 = const_cast<int*>(p1);		/*合法的*/
	*p2 = 10;
	std::cout << "a1 value = " << a1 << std::endl;
	std::cout << "p1 value = " << p1 << std::endl;
	std::cout << "p2 value = " << p2 << std::endl;

	/* 上行转换 */
	Son* son = new Son;
	son->print();
	auto ff = static_cast<Father*>(son);		/* 安全 */
	ff->print();

	/* 下行转换 */
#if 0
	Father* father = new Father;
	father->print();
	auto ff2 = dynamic_cast<Son*>(father);	//我们不该这么做，基类转派生类前提是基类指针已经指向了派生类的对象
	std::cout << ff2 << std::endl;				/* 地址为空,如果使用static_cast就不会检查类型，也就有可能访问非法内存了，所以下行转换使用dynamic_cast安全 */
	ff2->print();	/* error */
#else
	Father* father = new Son;				/*其实就是多态*/
	auto ff2 = dynamic_cast<Son*>(father);
	std::cout << ff2 << std::endl;
	ff2->print();
#endif

	/* 使用reinterpret_cast转换毫不相干的类型 非常危险*/
	int* p = new int(5);
	uint64_t p_val = reinterpret_cast<uint64_t>(p);		/* 指针转换为整形 */

	std::cout << "p    :" << p << std::endl;
	std::cout << "p_val:" << std::hex << p_val << std::endl;
}