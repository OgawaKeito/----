#include <stdio.h>

#define X 4
#define Y 3

double matrix[Y][X] =
    {
        {-2, -1, 6, 14},
        {-1, 5, -2, 3},
        {5, -1, 2, 6}};

void swap(void);
void normalize(void);
void Print_Arr(void);

int main(void)
{
    Print_Arr();
    swap();
    Print_Arr();
    normalize();
    Print_Arr();

    return 0;
}

// 入れ替え
void swap(void)
{
    int temp1, temp2;
    double temp[X];
    for (int i = 0; i < Y; i++)
    {
        if (matrix[i][i] == 0)
        {
            temp1 = (i + 1) % Y;
            temp2 = (i + 2) % Y;

            if (matrix[temp1][i] != 0)
            {
                for (int j = 0; j < X; j++)
                {
                    temp[j] = matrix[i][j];
                    matrix[i][j] = matrix[temp1][j];
                    matrix[temp1][j] = temp[j];
                }
            }
            else if (matrix[temp2][i] != 0)
            {
                for (int j = 0; j < X; j++)
                {
                    temp[j] = matrix[i][j];
                    matrix[i][j] = matrix[temp2][j];
                    matrix[temp2][j] = temp[j];
                }
            }
        }
    }
}

// 正規化
void normalize(void)
{
    double temp;
    for (int k = 0; k < Y; k++)
    {
        temp = matrix[k][k];
        for (int i = 0; i < X; i++)
        {
            matrix[k][i] /= temp;
        }
        for (int j = 0; j < Y; j++)
        {
            if (j == k)
            {
                continue;
            }
            temp = matrix[j][k];
            for (int i = 0; i < X; i++)
            {
                matrix[j][i] -= temp * matrix[k][i];
            }
        }
    }
}

// 行列表示
void Print_Arr(void)
{
    for (int i = 0; i < Y; i++)
    {
        printf("{%7.3f,%7.3f,%7.3f,%7.3f}\n", matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
    }
    printf("\n");
}