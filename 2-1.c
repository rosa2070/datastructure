#include <stdio.h>
#pragma warning(disable:4996)

int factorial(int n)
{
	printf("factorial(%d)\n", n);
	if (n <= 1) return 1;
	else return (n * factorial(n - 1));
}

int main(void)
{
	int num1;
	
	printf("������ �Է��ϼ���: ");
	scanf("%d", &num1);

	factorial(num1);

	return 0;
}