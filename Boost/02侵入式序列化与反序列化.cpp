#include <fstream>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
class A
{
private:
    // 为了能让串行化类库能够访问私有成员，所以要声明一个友元类
    friend class boost::serialization::access;
    // 对象的数据
    int a{};
    double b{};
    // 串行化的函数，这一个函数完成对象的保存与恢复,这是侵入式的方法序列化，要更改类的代码
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& a;   //就是这么简单，也可以使用 ar<<a 这样的语法
        ar& b;
    }
public:
    A(int aa, double bb) :a(aa), b(bb) {}
    constexpr A()noexcept = default;
    void print() { std::cout << a << ' ' << b << std::endl; }
};
int main(){
    std::ofstream fout("file.txt");// 把对象写到file.txt文件中
    boost::archive::text_oarchive oa(fout); // 文本的输出归档类，使用一个ostream来构造
    A obj(1, 2.5);
    oa << obj; // 保存obj对象
    fout.close();// 关闭文件

    std::ifstream fin("file.txt");
    boost::archive::text_iarchive ia(fin); // 文本的输入归档类
    A newobj;
    ia >> newobj; // 恢复到newobj对象
    newobj.print();
    fin.close();
}