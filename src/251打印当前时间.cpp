#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	cout << tmp << endl;
	return 0;
}