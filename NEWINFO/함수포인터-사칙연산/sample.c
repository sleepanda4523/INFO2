#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct CAL {
	double a;
	char c;
	double b;
}cal;
void add(double, double);
void sub(double, double);
void mul(double, double);
void div(double, double);

int main()
{
	cal ndata;
	void(*fp[4])(double,double) = { add,sub,mul,div };
	printf("��Ģ���� ������ �Է����ּ��� >> ");
	scanf("%d %c %d", &ndata.a, &ndata.c, &ndata.b);
	switch (ndata.c)
	{
	case '+':
		fp[0](ndata.a, ndata.b);
		break;
	case '-':
		fp[1](ndata.a, ndata.b);
		break;
	case '*':
		fp[2](ndata.a, ndata.b);
		break;
	case '/':
		fp[3](ndata.a, ndata.b);
		break;
	default:
		printf("��Ģ������ �ƴմϴ�..!\n");
		break;
	}
	return 0;
}
void add(double a, double b)
{
	printf("%.4lf\n", a + b);
}
void sub(double a, double b)
{
	printf("%.4lf\n", a - b);
}
void mul(double a, double b)
{
	printf("%.4lf\n", a * b);
}
void div(double a, double b)
{
	if (b > a || b == 0) {
		printf("����� �� �����ϴ�!\n");
	}
	else {
		printf("%.4lf\n", a / b);
	}
}