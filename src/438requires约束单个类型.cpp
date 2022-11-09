#include<iostream>
template<typename T, typename U>
struct person {};

template<typename T>//Person这个concept直接约束了类型必须是person类型的
concept Person = requires(T a) {
	[] <typename U, typename V>(person<U, V>) {}(a);
};

void myfunc(Person auto) {
	::std::cout << "Person auto\n";
}
void myfunc(auto) {//只是为了对比，不具备任何意义
	::std::cout << "Person\n";
}

int main() {
	myfunc(1);//不符合Person
	myfunc(person<int, int>{});
	myfunc(person<double, int>{});
	myfunc(person<double, double>{});
}