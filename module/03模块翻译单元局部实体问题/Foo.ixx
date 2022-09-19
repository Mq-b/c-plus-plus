export module Foo;

export import <iostream>;
export import<typeinfo>;
namespace {
    class LolWatchThis {        // 匿名的namespace是内部链接，不能导出
        static void say_hello() {
            std::cout << "Hello, everyone!\n";
        }
    };
}

export LolWatchThis lolwut() { // LolWatchThis 被暴露为返回类型
    return LolWatchThis();
}
