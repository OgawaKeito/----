#include <stdio.h>

#define N 19
#define X 3
#define Y 2

double height[N] = {170, 182, 171, 166, 168, 164, 173, 170, 172, 167, 164, 161, 180, 173, 163, 168, 165, 171, 182};
double weight[N] = {58, 80, 66, 62, 65, 56, 76, 81, 72, 66, 61, 56, 86, 78, 52, 66, 59, 61, 66};
double number[N];
double matrix[Y][X];

double sum(double *num1, double *num2, int n);
void swap(void);
void normalize(void);
void Print_Arr(void);

int main(void)
{
    // 身長、体重の合計
    matrix[0][0] = N;
    matrix[0][1] = sum(height, number, N);
    matrix[0][2] = sum(weight, number, N);
    matrix[1][0] = sum(height, number, N);
    matrix[1][1] = sum(height, height, N);
    matrix[1][2] = sum(height, weight, N);

    swap();
    normalize();
    Print_Arr();

    double a0 = matrix[0][2];
    double a1 = matrix[1][2];

    printf("\ny = %f x + (%f)\n", a1, a0);
}

// return = Σ(num1 * num2), N = 大きさ
double sum(double *num1, double *num2, int n)
{
    for (int i = 0; i < N; i++)
    {
        number[i] = 1;
    }

    double temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += num1[i] * num2[i];
    }

    return temp;
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
    Print_Arr();
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
        swap();
    }
}

// 行列表示
void Print_Arr(void)

{
    for (int i = 0; i < Y; i++)
    {
        printf("{%10.3f,%10.3f,%10.3f}\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
    printf("\n");
}