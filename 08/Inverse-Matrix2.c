#include <stdio.h>

#define X 3
#define Y 3

double matrix[Y][X] =
    {
        {1, 2, 3},
        {6, 0, 7},
        {5, 1, -2}};

double E[Y][X] = {
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

                    temp[j] = E[i][j];
                    E[i][j] = E[temp1][j];
                    E[temp1][j] = temp[j];
                }
            }
            else if (matrix[temp2][i] != 0)
            {
                for (int j = 0; j < X; j++)
                {
                    temp[j] = matrix[i][j];
                    matrix[i][j] = matrix[temp2][j];
                    matrix[temp2][j] = temp[j];

                    temp[j] = E[i][j];
                    E[i][j] = E[temp2][j];
                    E[temp2][j] = temp[j];
                }
            }
        }
    }
}

// 逆行説存在判定
double judge(void)
{
    double temp = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[1][0] * matrix[2][1] * matrix[0][2] + matrix[2][0] * matrix[0][1] * matrix[1][2] - matrix[0][0] * matrix[2][1] * matrix[1][2] - matrix[2][0] * matrix[1][1] * matrix[0][2] - matrix[1][0] * matrix[0][1] * matrix[2][2];

    if (!temp)
    {
        printf("逆行列はありません。");
    }
    else
    {
        printf("\ndetA=%9.5f\n\n", temp);
    }

    return temp;
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
            // pivot行の割り算
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
                // 減算
                matrix[j][i] -= temp * matrix[k][i];
                E[j][i] -= temp * E[k][i];
            }
        }
        // 途中式
        // Print_Arr();
        swap();
    }
}

// 行列表示
void Print_Arr(void)

{

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
