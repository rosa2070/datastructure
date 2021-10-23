#include <stdio.h>
#pragma warning(disable:4996)

int factorial_iter(int n)
{
	int i, result = 1;
	for (i = 1; i <= n; i++)
		result = result * i;
	return(result);
}

int main(void)
{
	int num1;

	printf("정수를 입력하세요: ");
	scanf("%d", &num1);

	factorial_iter(num1);

	return 0;
}