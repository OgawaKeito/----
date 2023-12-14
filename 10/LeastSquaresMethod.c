#include <stdio.h>

#define N 19

double height[N] = {170, 182, 171, 166, 168, 164, 173, 170, 172, 167, 164, 161, 180, 173, 163, 168, 165, 171, 182};
double weight[N] = {58, 80, 66, 62, 65, 56, 76, 81, 72, 66, 61, 56, 86, 78, 52, 66, 59, 61, 66};
double number[N];

double sum(double *num1, double *num2, int n);

int main(void)
{
    // 身長、体重の合計
    double X = sum(height, number, N);
    double Y = sum(weight, number, N);
    double XX = sum(height, height, N);
    double XY = sum(height, weight, N);

    double a0 = (X * XY - XX * Y) / (X * X - N * XX);
    double a1 = (Y - N * a0) / X;

    printf("\ny = %f x + (%f)\n", a1, a0);
}

double sum(double *num1, double *num2, int n)
{
    for (int i = 0; i < N; i++)
    {
        number[i] = 1;
    }

    double temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += num1[i] * num2[i];
    }

    return temp;
}
