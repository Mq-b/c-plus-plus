#include <functional>
#include <iostream>

struct Foo {
    void display_greeting() {
        std::cout << "Hello, world.\n";
    }
    void display_number(int i) {
        std::cout << "number: " << i << '\n';
    }
    int data = 7;
};

int main() {
    Foo f;

    auto greet = std::mem_fn(&Foo::display_greeting);
    greet(&f);

    auto print_num = std::mem_fn(&Foo::display_number);
    print_num(&f, 42);

    auto access_data = std::mem_fn(&Foo::data);
    std::cout << "data: " << access_data(&f) << '\n';
}
/*有一说一，c++17的std::invoke感觉比它好很多
https://zh.cppreference.com/w/cpp/utility/functional/mem_fn
*/