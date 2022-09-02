#include<iostream>
union Test {
	int a;
	double b;
	char ch;
}t;
int main() {
	t.b = 12000.0;
	t.a = 13;
	printf("%d\n", t);
	printf("%lf\n", t);
	printf("%zd\n", sizeof(t));
	printf("%d\t%lf", t.a, t.b);
}