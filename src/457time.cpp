#include<sstream>
#include <iomanip>
#include<iostream>

int main()
{
    std::tm t = {};
    std::istringstream ss("2011-Februar-18 23:12:34");
    ss.imbue(std::locale("de_DE.utf-8"));
    ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S");

    if (ss.fail())
        std::cout << "解析失败\n";
    else
        std::cout << std::put_time(&t, "%c") << '\n';
}