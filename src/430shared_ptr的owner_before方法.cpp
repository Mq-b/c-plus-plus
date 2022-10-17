#include <iostream>
#include <memory>

struct Foo {
    int n1;
    int n2;
    Foo(int a, int b) : n1(a), n2(b) {}
};
int main()
{
    auto p1 = std::make_shared<Foo>(1, 2);
    std::shared_ptr<int> p2(p1, &p1->n1);
    std::shared_ptr<int> p3(p1, &p1->n2);

    std::cout << std::boolalpha
        << "p2 < p3 " << (p2 < p3) << '\n'//true
        << "p3 < p2 " << (p3 < p2) << '\n'//false
        << "p2.owner_before(p3) " << p2.owner_before(p3) << '\n'//false，p2指向的n1，p3指向的n2，n2的地址不大于n3所以为false
        << "p3.owner_before(p2) " << p3.owner_before(p2) << '\n';//false

    std::weak_ptr<int> w2(p2);
    std::weak_ptr<int> w3(p3);
    std::cout
        << "w2.owner_before(w3) " << w2.owner_before(w3) << '\n'//false
        << "w3.owner_before(w2) " << w3.owner_before(w2) << '\n';//false

    //owner_before()返回值若 *this 大于 other 则为 true ，否则为 false
}