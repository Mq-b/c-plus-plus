#include<sstream>//std::stringstream
#include <array>
#include <iostream>

int wmain()
{
	std::stringstream ss;

	ss << 50;
	std::string a;
	ss >> a;
	std::cout << a << std::endl;
	ss.clear();//每次转换完都要清除

	ss << "1314";
	int b;
	ss >> b;
	std::cout << b << std::endl;

	ss.clear();
	ss << "51.2";
	double c;
	ss >> c;
	std::cout << c << std::endl;
	
	//由此得出std::stringstream主要帮助我们进行字符串和数字之间的转换
	//实际上我们还能像下面这样用
	std::stringstream s;
	s << "我的电话号码是:\t" << 110 << "\t我的ip地址是:\t" << "192.168.139.127";
	std::cout << s.str() << std::endl;
}