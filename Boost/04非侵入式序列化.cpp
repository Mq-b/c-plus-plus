#include<iostream>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include<boost/serialization/base_object.hpp>
#include <boost/multiprecision/cpp_int.hpp>

class A
{
public:
    A() :_tag(0), _text("") {}

    A(int tag, std::string text) :_tag(tag), _text(text) {}

    int _tag;
    std::string _text;
    void print() {
    std::cout << _tag << ' ' << _text << '\n';
    }
};

namespace boost {
    namespace serialization {
        template<class Archive>
        void serialize(Archive& ar, A& d, const unsigned int version)
        {
            ar& d._tag;
            ar& d._text;
        }
    } // namespace serialization
} // namespace boost

int main() {
	std::ofstream fout("file.txt");// 把对象写到file.txt文件中
	boost::archive::text_oarchive oa(fout); // 文本的输出归档类，使用一个ostream来构造
	A obj(10, "**");
	oa << obj; // 保存obj对象
	fout.close();// 关闭文件

	std::ifstream fin("file.txt");
	boost::archive::text_iarchive ia(fin); // 文本的输入归档类
	A newobj;
	ia >> newobj; // 恢复到newobj对象
	newobj.print();
	fin.close();
}