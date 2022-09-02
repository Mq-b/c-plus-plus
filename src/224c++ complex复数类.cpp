#include<iostream>
#include<complex>//提供复数类原型

using namespace std::literals::complex_literals;//引入复数类的命名空间
using namespace std;
void test1()
{

	complex<double> z(2, 3);
	complex<double> z1 = z + 5.0;
	cout << z1 << endl;
	complex<double> z2 = z - 5.0;
	cout << z2 << endl;
	complex<double> z3 = z * 2.0;
	cout << z3 << endl;
	complex<double>z4 = z / complex<double>(1, 1);
	cout << z4 << endl;
}
int main()
{
	test1();
	complex<double>z(2, 3);
	complex<double>z1;
	complex<double>z2(z);

	cout << z << endl;
	cout << z1 << endl;
	cout << z2 << endl;
	z.real(22);
	z.imag(33);//修改z的实部和虚部的值
	cout << z << endl;

	complex<double>a, b, c;
	cout << "请输入三个负数：";
	cin >> a >> b >> c;		//只能输入实部的值
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	std::cout << 5i << std::endl;//内建的字面量(虚部的值)
	return 0;
}