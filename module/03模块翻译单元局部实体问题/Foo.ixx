export module Foo;

export import <iostream>;
export import<typeinfo>;


    export class LolWatchThis {        
        static void say_hello() {
            std::cout << "Hello, everyone!\n";
        }
    };


export LolWatchThis lolwut() { // LolWatchThis 被暴露为返回类型
    return LolWatchThis();
}
