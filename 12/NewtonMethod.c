#include <stdio.h>

int A = 5;
int B = 1;
int C = 2;
double epsi = 0.0000000000001;

double f(double x);
double f_diff(double x);
double judge(double x);

int main(void)
{
    judge(-10);
    judge(1);
    judge(10);
}

// f(x)をreturn
double f(double x)
{
    double f;
    f = (x * x * x) - (A * x * x) - (B * x) + C;
    return f;
}
// f'(x)をreturn
double f_diff(double x)
{
    double f_diff;
    f_diff = 3 * (x * x) - 2 * (A * x) - B;
    return f_diff;
}

double judge(double x)
{
    double ans = f(x);
    double dif = f_diff(x);
    double div = ans / dif;
    double nyu = x - div;

    double lansl = ans;
    if (lansl < 0) // 絶対値
    {
        lansl *= -1;
    }

    if (lansl > epsi)
    {
        judge(nyu);
    }
    else
    {
        printf("x=%f\nf(x) = %.20f\n\n", x, ans);
    }
}