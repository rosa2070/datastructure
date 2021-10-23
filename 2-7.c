#include <stdio.h>
#pragma warning(disable:4996)

int fib_iter(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0;
	int p = 1;
	int result = 0;

	for (int i = 2; i <= n; i++) {
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}

int main(void)
{
	int num1;


	printf("정수를 입력하세요: ");
	scanf("%d", &num1);

	int k;
	k = fib_iter(num1);
	printf("%d", k);


	return 0;
}