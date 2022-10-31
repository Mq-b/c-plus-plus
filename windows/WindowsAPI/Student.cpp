#include "Student.h"

Student::Student()
{
	std::cout << __func__ << '\n';
}

void Student::f()
{
	std::cout << this->n << '\n';
}
