#include <stdio.h>
#pragma warning(disable:4996)

double power(double x, int n)
{
	if (n == 0)return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else return x * power(x * x, (n - 1) / 2);
}



int main(void)
{
	double num1;
	int num2;


	printf("정수를 입력하세요: ");
	scanf("%lf %d", &num1, &num2);

	double k;
	k = power(num1, num2);
	printf("%lf", k);


	return 0;
}