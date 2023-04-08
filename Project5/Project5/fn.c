#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


double** matr_create(int n) 
{
    double **m;
    m = (double**)calloc(n, sizeof(double*));
    for (int i = 0; i < n; ++i)
        m[i] = calloc(n, sizeof(double));
    return m;
}

void matr_input(double **m, int n, int d)
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            printf("m%d[%d][%d] = ", d, i, j);
            scanf("%lf", &m[i][j]);
        }
    }
    printf("\n");
}

void matr_output(double** m, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%lf ", m[i][j]);;
        }
        printf("\n");
    }
    printf("\n");
}

char znak(char c)
{
    printf("¬ведите действие +, -, *: ");
    scanf_s(" %c", &c);
    return c;
}


double** m_summ(double** a, double** b, int n, double** r)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {

            r[i][j] = a[i][j] + b[i][j];
        }
    }
    return r;
}
double** m_mines(double** a, double** b, int n, double** r)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            r[i][j] = a[i][j] - b[i][j];
        }
    }
    return r;
}
double** m_mnoj(double** a, double** b, int n, double** r)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            r[i][j] = 0;
            for (int d = 0; d < n; ++d)
            {
                r[i][j] += a[i][d] * b[d][j];
            }
        }
    }  
    return r; 
}