#include<fstream>
#include<iostream>
#include<boost/archive/text_oarchive.hpp>
#include<boost/archive/text_iarchive.hpp>
#include<boost/serialization/base_object.hpp>
//STL容器
//如果要序列化一个STL容器，要使用boost自带的头文件，不能直接#include<vector>
#include<boost/serialization/list.hpp>

class A{
    std::list<int> list;
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& list;
    }
public:

    A(int a = 0, int b = 0) :list(a, b) {}

    void print() {
        for (auto i : list) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
};


void A_test() {
    std::ofstream fout("file.txt");// 把对象写到file.txt文件中
    boost::archive::text_oarchive oa(fout); // 文本的输出归档类，使用一个ostream来构造
    A obj(10, 6);
    oa << obj; // 保存obj对象
    fout.close();// 关闭文件

    std::ifstream fin("file.txt");
    boost::archive::text_iarchive ia(fin); // 文本的输入归档类
    A newobj;
    ia >> newobj; // 恢复到newobj对象
    newobj.print();
    fin.close();
}

int main() {
    A_test();//序列化STL容器
}