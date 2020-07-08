#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct CAL {
	double a;
	char c;
	double b;
}cal;
double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);

int main()
{
	cal ndata;
	double(*fp[4])(double,double) = { add,sub,mul,div };
	printf("사칙연산 수식을 입력해주세요 >> ");
	scanf("%d %c %d", &ndata.a, &ndata.c, &ndata.b);
	switch (ndata.c)
	{
	case '+':
		printf("%.4lf\n",fp[0](ndata.a, ndata.b));
		break;
	case '-':
		printf("%.4lf\n", fp[1](ndata.a, ndata.b));
		break;
	case '*':
		printf("%.4lf\n", fp[2](ndata.a, ndata.b));
		break;
	case '/':
		if (ndata.b == 0) {
			printf("계산할 수 없습니다!\n");
		}
		else {
			printf("%.4lf\n", fp[3](ndata.a, ndata.b));
		}
		break;
	default:
		printf("사칙연산이 아닙니다..!\n");
		break;
	}
	return 0;
}
double add(double a, double b)
{
	return a + b;
}
double sub(double a, double b)
{
	return a - b;
}
double mul(double a, double b)
{
	return a * b;
}
double div(double a, double b)
{
		return a / b;
}