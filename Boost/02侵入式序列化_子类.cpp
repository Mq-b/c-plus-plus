#include <fstream>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include<boost/serialization/base_object.hpp>

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

class B :public A//序列化一个子类
{
    friend class boost::serialization::access;
    char c{};
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& boost::serialization::base_object<A>(*this); // 注意这里
        ar& c;
    }
public:
    B(char v = 0) :c(v) {}
    void print() {
        std::cout << c << '\n';
    }
};

void A_test(){
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
//和A的反序列化方式没有任何区别
void B_test() {
    std::ofstream fout("file.txt");
    boost::archive::text_oarchive oa(fout);
    B obj(97);
    oa << obj; 
    fout.close();

    std::ifstream fin("file.txt");
    boost::archive::text_iarchive ia(fin); 
    B newobj;
    ia >> newobj; 
    newobj.print();
    newobj.A::print();//访问父类
    fin.close();
}

int main() {
    //A_test();//侵入式序列化和反序列化
    B_test();//侵入式序列化子类和反序列化
}