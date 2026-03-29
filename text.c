#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
main()
{
	int a, b;
	int add, sub, mul, div;

	scanf("%d%d", &a, &b);
	add = a + b;
	sub = a - b;
	mul = a * b;
	div = a / b;
	printf("%d+%d=%d\n", a, b, add);
	printf("%d-%d=%d\n", a, b, sub);
	printf("%d*%d=%d\n", a, b, mul);
	printf("%d/%d=%d\n", a, b, div);
}