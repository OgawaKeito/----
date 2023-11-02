#include <stdio.h>

double matrix[3][4] =
    {
        {3, 2, -3, -2},
        {2, -2, 1, 7},
        {-3, 6, 5, 28}};

void swap(void);
void normalize(void);
void Print_Arr(void);

void main(void)
{
    Print_Arr();
    swap();
    Print_Arr();
    normalize();
    Print_Arr();
}

// 入れ替え
void swap(void)
{
    int temp1, temp2;
    double temp[3][4];
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][i] == 0)
        {
            temp1 = (i + 1) % 3;
            temp2 = (i + 2) % 3;

            if (matrix[temp1][i] != 0)
            {
                for (int j = 0; j < 4; j++)
                {
                    temp[i][j] = matrix[i][j];
                    matrix[i][j] = matrix[temp1][j];
                    matrix[temp1][j] = temp[i][j];
                }
            }
            else if (matrix[temp2][i] != 0)
            {
                for (int j = 0; j < 4; j++)
                {
                    temp[i][j] = matrix[i][j];
                    matrix[i][j] = matrix[temp2][j];
                    matrix[temp2][j] = temp[i][j];
                }
            }
        }
    }
}

// 正規化
void normalize(void)
{
    double temp;
    for (int k = 0; k < 3; k++)
    {
        temp = matrix[k][k];
        for (int i = 0; i < 4; i++)
        {
            matrix[k][i] /= temp;
        }

        for (int j = 0; j < 3; j++)
        {
            if (j == k)
            {
                continue;
            }
            temp = matrix[j][k];
            for (int i = 0; i < 4; i++)
            {
                matrix[j][i] -= temp * matrix[k][i];
            }
        }
    }
}

// 行列表示
void Print_Arr(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("{%8.5f,%8.5f,%8.5f,%8.5f}\n", matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
    }
    printf("\n");
}