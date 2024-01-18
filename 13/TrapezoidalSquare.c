#include <stdio.h>

#define A 5
#define B 1
#define C 2

double n = 1000; // 分割数
double s = 2;
double e = 4;
double sum;

double f(double x);
double area(double x, double h);

int main(void)
{
    double h = (e - s) / n;
    double x = s;
    for (int i = 0; i < n; i++)
    {
        sum += area(x, h);
        x += h;
    }

    printf("%f", sum);
}

// f(x)をreturn
double f(double x)
{
    double f;
    f = (x * x * x) - (A * x * x) - (B * x) + C;
    return f;
}

double area(double x, double h)
{
    double w1 = f(x);
    double w2 = f(x + h);
    return (w1 + w2) * h / 2;
}