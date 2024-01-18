#include <stdio.h>

int A = 5;
int B = 1;
int C = 2;
double epsi = 0.001;

double f(double x);
int judge(double high, double low, double middle);

int main(void)
{
    double high = 10;
    double low = -10;
    double middle = (high + low) / 2;

    printf("high  :%11.5f\n", f(high));
    printf("middle:%11.5f\n", f(middle));
    printf("low   :%11.5f\n", f(low));

    judge(high, low, middle);
}

// f(x)をreturn
double f(double x)
{
    double f;
    f = (x * x * x) - (A * x * x) - (B * x) + C;
    return f;
}

// epsi判定
int judge(double high, double low, double middle)
{
    double temp = f(high) * f(low);
    if (temp < 0)
    {
        // printf("\n|f(%8.3f) * f(%8.3f)| < 0\n", high, low);
        double Absolute = temp * (-1);
        if (Absolute < epsi)
        {
            printf("\n|f(%8.3f) * f(%8.3f)| < epsi\n", high, low);
            return 2;
        }
        else if (f(high) * f(middle) < 0)
        {
            return (1);
        }
        else if (f(high) * f(middle) > 0)
        {
            return (0);
        }
    }
    else
    {
        printf("\n|f(%8.3f) * f(%8.3f)|が正です。\n", high, low);
    }
}
