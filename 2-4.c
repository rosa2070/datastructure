#include <stdio.h>
#pragma warning(disable:4996)

double slow_power(double x, int n)
{
	int i;
	double result = 1;

	for (i = 0; i < n; i++)
		result = result * x;
	return(result);
}



int main(void)
{
	double num1;
	int num2;
	

	printf("������ �Է��ϼ���: ");
	scanf("%lf %d", &num1, &num2);

	double k;
	k = slow_power(num1, num2);
	printf("%lf", k);


	return 0;
}