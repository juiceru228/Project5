#include <stdio.h>

#include "fn.h"


int main() 
{
	int n;
	char c;
	system("chcp 1251");
	system("cls");
	printf("Введите количество строк: ");
	scanf("%d", &n);
	double **a = matr_create(n);
	double **b = matr_create(n);
	double** r = matr_create(n);
	matr_input(a, n, 1);
	matr_input(b, n, 2);
	matr_output(a, n);
	matr_output(b, n);	
	zanovo: c = znak();
	if (c == '+')
	{
		r = m_summ(a, b, n, r);
	}
	else if (c == '-')
	{
		r = m_mines(a, b, n, r);
	}
	else if (c == '*')
	{
		r = m_mnoj(a, b, n, r);
	}
	else
	{
		printf("Не правильно\n");
		goto zanovo;	
	}
	matr_output(r, n);
	return 0;
}
