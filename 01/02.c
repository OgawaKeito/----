#include <stdio.h>

int main(void)
{
    double x = 1.0;
    double y = 0.00000000000000001;

    double z = x + 1000000 * y;

    printf("%.75f\n", z);

    return (0);

    // 1.000000000010000000800000000000000000000
}