#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void observe()
{
    std::cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()) { // 使用之前必须复制到 shared_ptr
        std::cout << *spt << "\n";
    }
    else {
        std::cout << "gw is expired\n";
    }
}

int main()
{
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
 
        observe();
    }

    observe();

    std::shared_ptr<int>p;

    {
        std::weak_ptr<int>g = std::make_shared<int>(40);
        p = g.lock();//转换
    }
    std::cout << *p << std::endl;
}
/*std::weak_ptr 来跟踪该对象。需要获得临时所有权时，则将其转换为 std::shared_ptr，此时如果原来的 std::shared_ptr 被销毁，则该对象的生命期将被延长至这个临时的 
std::shared_ptr 同样被销毁为止。

如果我没有转换，那么堆区内存的生命周期只是按照std::shared_ptr!!

weak_ptr的持有者通过lock可以获得一个shared_ptr，这样对象就会至少活到这个新的shared_ptr析构为止

*/