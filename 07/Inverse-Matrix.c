#include <stdio.h>

#define X 3
#define Y 3

double matrix[Y][X] =
    {
        {1, 2, 3},
        {6, 0, 7},
        {5, 1, -2}};

double E[Y][X] =
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

void swap(void);
void normalize(void);
double judge(void);
void Print_Arr(void);

int main(void)
{
    if (judge())
    {
        swap();
        normalize();
        Print_Arr();
    }
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

// 逆行説存在判定
double judge(void)
{
    int temp = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    if (!temp)
    {
        printf("逆行列はありません。");
    }
    return temp;
}

// 正規化
void normalize(void)
{
    double temp;
    for (int k = 0; k < Y; k++)
    {
        Print_Arr();
        temp = matrix[k][k];
        for (int i = 0; i < X; i++)
        {
            matrix[k][i] /= temp;
            E[k][i] /= temp;
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
                E[j][i] -= temp * E[k][i];
            }
        }
        swap();
    }
}

// 行列表示
void Print_Arr(void)

{

    // for (int i = 0; i < Y; i++)
    // {
    //     for (int j = 0; j < X; j++)
    //     {
    //         printf("%7.3f,", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    for (int i = 0; i < Y; i++)
    {
        printf("{");
        for (int j = 0; j < X; j++)
        {
            printf("%9.5f,", E[i][j]);
        }
        printf("|");
        for (int j = 0; j < X; j++)
        {
            printf("%9.5f,", matrix[i][j]);
        }
        printf("}\n");
    }
    printf("\n");
}
