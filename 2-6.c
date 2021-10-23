#include <stdio.h>
#pragma warning(disable:4996)

int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}



int main(void)
{
	int num1;


	printf("정수를 입력하세요: ");
	scanf("%d", &num1);

	int k;
	k = fib(num1);
	printf("%d", k);


	return 0;
}