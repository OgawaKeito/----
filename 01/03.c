#include <stdio.h>

int main(void)
{
    double x = 1.0;
    double y = 0.00000000000000001;

    for (int i = 0; i < 1000000; i++)
    {
        x += y;
    }
    printf("%.75f\n", x);
    return (0);

    // 1.000000000000000000000000000000000000000
}