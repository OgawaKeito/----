#include <stdio.h>

#define A 5
#define B 1
#define C 2

int n = 500000; // 分割数
double s = 2;
double e = 4;
double sum1, sum2;

double f(double x);
double area1(double x, double h);
double area2(double x, double h);

int main(void)
{
    double h = (e - s) / n;
    double x = s;
    for (int i = 0; i < n; i++)
    {
        sum1 += area1(x, h);
        sum2 += area2(x, h);
        x += h;
    }

    printf("分割数%d\n", n);
    printf("区分求積法:%f\n台形法　　:%f", sum1, sum2);
    // -35.333
}

// f(x)をreturn
double f(double x)
{
    double f;
    f = (x * x * x) - (A * x * x) - (B * x) + C;
    return f;
}

double area1(double x, double h)
{
    double w = f(x);
    return w * h;
}

double area2(double x, double h)
{
    double w1 = f(x);
    double w2 = f(x + h);
    return (w1 + w2) * h / 2;
}